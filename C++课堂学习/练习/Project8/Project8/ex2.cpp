#include "1.h"


double yuan::zhouchang()
{
	return 2 * 3.14 * r;
}
double yuan::mianji()
{
	return 3.14 * r * r;
}
void yuan::shuru()
{
	cin >> r;
}
void yuan::shuchu()
{
	cout << "Բ���ܳ���" << zhouchang() << endl;
	cout << "Բ�������" << mianji() << endl;
}


double changfangxing::zhouchang()
{
	return 2 * (a + b);
}
double changfangxing::mianji()
{
	return a * b;
}
void changfangxing::shuru()
{
	cin >> a >> b;
}
void changfangxing::shuchu()
{
	cout << "�����������" << mianji() << endl;
	cout << "�������ܳ���" << zhouchang() << endl;
}