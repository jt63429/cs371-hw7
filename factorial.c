#include <stdio.h>

int main()
{
	int n;
	int factorial = 1;

	printf("Enter a non-negative integer: ");
	scanf("%d", &n);

	if (n < 0) {
		printf("Negative integer entered, please try again\n");
		return 0;
	}
	else {
		for (int i = 1;	i <= n; i++) {
			factorial *= i;
		}

	printf("The factorial of %d = %d\n", n, factorial);

	}

	return 0;

}
