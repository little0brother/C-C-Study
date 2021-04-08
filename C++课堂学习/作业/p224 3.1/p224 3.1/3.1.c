#include <stdio.h>
#include <math.h>

struct point {
	double x;
	double y;
};

int main()
{
	struct point p1, p2;
	double dst = 0;
	double a, b;

	printf("Inout  first:");
	scanf_s("%lf %lf", &p1.x, &p1.y);
	printf("Input second:");
	scanf_s("%lf %lf", &p2.x, &p2.y);

	//a = p1.x - p2.x;
	//b = p1.y - p2.y;
	a = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	dst = sqrt(a);

	printf("distance:%.2lf\n", dst);

	system("pause");
	return 0;
}