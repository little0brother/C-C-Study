#include <iostream>
using namespace std;

class A
{
private:
	int a;

public:
	A(int a)
	{
		this->a = a;
	}

};

class B
{
private:
	A a1;
	A a2;
	int b1;
	int b2;

public:
};

int main()
{


	return 0;
}