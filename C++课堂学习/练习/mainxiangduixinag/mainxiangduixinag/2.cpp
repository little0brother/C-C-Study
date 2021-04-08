#include "zaojia.h"

double yuan::zaojia()
{
	return 3.14 * r * r * 10;
}
double yuan::shuru()
{
	cin >> r;
	return zaojia();
}

double chang::zaojia()
{
	return x * y * 10;
}
double chang::shuru()
{
	cin >> x >> y;
	return zaojia();
}