#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_file_name[256], output_file_name[256];
    char *word = NULL;
    char longest_word[256] = "";
    int characters = 0, words = 0, lines = 0;
    int word_length = 12;

    printf("Enter input file name: ");
    scanf("%255s", input_file_name);
    printf("Enter output file name: ");
    scanf("%255s", output_file_name);

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(output_file_name, "w");
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

    while (fscanf(input_file, "%s", word) != EOF) {
        words++;
        characters += strlen(word);

        if (strlen(word) > strlen(longest_word)) {
            strcpy(longest_word, word);
        }

        if (strlen(word) >= word_length) {
            word_length = strlen(word) + 1;
            word = (char *)realloc(word, word_length * sizeof(char));
            if (word == NULL) {
                perror("Memory reallocation failed");
                fclose(input_file);
                fclose(output_file);
                return 1;
            }
        }

        // Read the next character and count newline characters (only once per line)
        char ch;
        while ((ch = fgetc(input_file)) != EOF && ch != '\n') {
            // No need to count non-word characters separately
            if (ch != ' ' && ch != '\t') {
                characters++;  // Count non-space characters
            }
        }

        if (ch == '\n') {
            lines++;
        }
    }

    if (characters > 0 && word[strlen(word) - 1] != '\n') {
        lines++;
    }

    fprintf(output_file, "Characters: %d\n", characters);
    fprintf(output_file, "Words: %d\n", words);
    fprintf(output_file, "Lines: %d\n", lines);
    fprintf(output_file, "Longest Word: %s\n", longest_word);

    free(word);
    fclose(input_file);
    fclose(output_file);

    return 0;
}
