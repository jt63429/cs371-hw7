#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *array;
	int n;

	printf("Array size: ");
	scanf("%d", &n);

	array = (int*) malloc(n* sizeof(int));
	if (array == NULL) {
		printf("Memory allocation unsuccessful\n");
		return 1;
	}

	for(int i = 0; i < n; i++) {
		*(array + i)  = i + 1;
	}

	for(int i = 0; i < n; i++) {
		*(array + i) += 1;
	}

	printf("Modified Array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}

