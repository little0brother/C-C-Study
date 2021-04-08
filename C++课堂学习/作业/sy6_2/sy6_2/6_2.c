#include <stdio.h>

double convert(double temp, char type);

int main()
{
	double temp;
	char type;

	printf("Enter temperature: ");
	scanf_s("%lf", &temp);
	printf("Press C to convert to Celsius, F to convert to Fahrenheit:");
	scanf_s(" %c", &type);
	printf("Corresponding temperature: %.lf\n", convert(temp, type));

	system("pause");
	return 0;
}

double convert(double temp, char type)
{
	switch (type)
	{
	case 'f':
	case 'F':
		return 32 + 1.8 * temp;
	case 'c':
	case 'C':
		return 5.0 / 9 * (temp - 32);
	}
}