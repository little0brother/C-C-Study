/* 定义一个Tree类，有成员ages（树龄），成员函数grow（int years）对ages加上years，age（）显示tree对象的ages的值 */

#include <iostream>
using namespace std;

class Tree
{
private:
	int ages;

public:
	Tree(int ages) { this->ages = ages; }
	int grow(int years) { return ages + years; }
	int age() { return ages; }
};

int main()
{
	Tree tree(2);
	cout << tree.grow(10) << endl;
	cout << tree.age() << endl;

	return 0;
}