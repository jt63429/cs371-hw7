#include <stdio.h>

float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);

int main()
{
	float number1, number2;

	printf("Enter two numbers: ");
	scanf("%f %f", &number1, &number2);

	printf("Addition: %.2f + %.2f = %.2f\n", number1, number2, add(number1, number2));
	printf("Subtraction: %.2f - %.2f = %.2f\n", number1, number2, subtract(number1, number2));
	printf("Multiplication: %.2f * %.2f = %.2f\n", number1, number2, multiply(number1, number2));
	if  (number2 == 0.0f)
	{
		printf("Divide by zero error.\n");
	}
	else {
		printf("Division: %.2f / %.2f = %.2f\n", number1, number2, divide(number1, number2));
	}

	return 0;
}

float add(float num1, float num2)
{
	return num1 + num2;
}
float subtract(float num1, float num2)
{
	return num1 - num2;
}
float multiply(float num1, float num2) 
{
	return num1 * num2;
}
float divide(float num1, float num2) 
{
	return num1 / num2;
}
