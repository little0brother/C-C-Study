#include <stdio.h>

struct plural add(struct plural num1, struct plural num2);
struct plural multiply(struct plural num1, struct plural num2);

struct plural {
	int a;
	int b;
};

int main()
{
	struct plural num1, num2, num3;
	int x;

	printf("Enter the first complx number (X + Xi):");
	scanf_s("%d+%di", &num1.a, &num1.b);
	printf("Enter the second complx number(X + Xi):");
	scanf_s("%d+%di", &num2.a, &num2.b);
	printf("Press 1(or 2) to add(multiply) complex number:");
	scanf_s("%d", &x);

	if (x == 1)
		num3 = add(num1, num2);
	else
		num3 = multiply(num1, num2);

	printf("%d + %di\n", num3.a, num3.b);

	system("pause");
	return 0;
}

struct plural add(struct plural num1, struct plural num2)
{
	struct plural x;
	x.a = num1.a + num1.b;
	x.b = num1.b + num2.b;

	return x;
}

struct plural multiply(struct plural num1, struct plural num2)
{
	struct plural x;
	x.a = (num1.a * num2.a) - (num1.b * num2.b);
	x.b = (num1.a * num2.b) + (num1.b * num2.a);

	return x;
}