#include <iostream>
using namespace std;

// 1.值传递
void mySwap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 2.地址传递
void mySwap02(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 3.引用传递
void mySwap03(int& a, int& b) // int& a = a; int& b = b;
{
	int temp = a;
	a = b;
	b = temp;
}

// 引用的注意事项

// 1.不要返回局部变量的引用（因为再执行完后，内存空间会别释放，所以无引用对象）
int& myFunc()
{
	int a = 10;
	return a;
}
void test04()
{
	int& ret = myFunc();
	cout << "ret = " << ret << endl;	//编译器优化了结果，保存住之前的数据
}

// 2.如果函数的返回值是引用，那么这个函数可以作为左值进行运算
int& myFunc2()
{
	static int a = 10;
	return a;
}
void test05()
{
	int& ret = myFunc2();
	cout << "ret = " << ret << endl;	//编译器优化了结果，保存住之前的数据
	cout << "ret = " << ret << endl;
	cout << "ret = " << ret << endl;

	myFunc2() = 100;	// a = 100;
	cout << "ret = " << ret << endl;
	cout << myFunc2() << endl;

}

int main()
{
	int a = 10;
	int b = 20;

	//mySwap01(a, b);
	//mySwap02(&a, &b);
	//mySwap03(a, b);
	//test04();
	test05();

	/*cout << "a = " << a << endl;
	cout << "b = " << b << endl;*/

	return 0;
}