#include <stdio.h>

int main()
{
	float fahrenheit, celsius;

	printf("Enter your temperature in Fahrenheit: ");
	scanf("%f", &fahrenheit);

	celsius = (fahrenheit - 32) * 5/9;

	printf("Your temperature in Celsius: %.2f degrees\n", celsius);

	return 0;
}
