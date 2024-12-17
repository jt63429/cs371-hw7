#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_file_name[256];
    char *word = NULL;
    char longest_word[256] = "";
    int characters = 0, words = 0, lines = 0;
    int word_length = 12;
    char ch;

    printf("Enter input file name: ");
    scanf("%255s", input_file_name);

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen("analysis_report.txt", "w");
    if (output_file == NULL) {
        fclose(input_file);
        perror("Error opening output file");
        return 1;
    }

    word = (char *)malloc(word_length * sizeof(char));
    if (word == NULL) {
        perror("Initial memory allocation failed");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }


    while ((ch = fgetc(input_file)) != EOF) {
        characters++;

        if (ch == '\n') {
            lines++;
        }

        if (ch == ' ' || ch == '\n') {
            if (word[0] != '\0') {
                words++;
                if (strlen(word) > strlen(longest_word)) {
                    strcpy(longest_word, word);
                }
                word[0] = '\0';
            }
        } else {

            size_t len = strlen(word);
            if (len + 1 >= word_length) {
                word_length *= 2;
                word = realloc(word, word_length * sizeof(char));
                if (word == NULL) {
                    perror("Memory reallocation failed");
                    fclose(input_file);
                    fclose(output_file);
                    return 1;
                }
            }
            word[len] = ch;
            word[len + 1] = '\0';
        }
    }

    if (word[0] != '\0') {
        words++;
        if (strlen(word) > strlen(longest_word)) {
            strcpy(longest_word, word);
        }
    }

    fprintf(output_file, "Characters: %d\n", characters);
    fprintf(output_file, "Words: %d\n", words);
    fprintf(output_file, "Lines: %d\n", lines);
    fprintf(output_file, "Longest Word: %s\n", longest_word);

    free(word);
    fclose(input_file);
    fclose(output_file);

    printf("Program executed successfully\n");

    return 0;
}
