/* ����һ��Tree�࣬�г�Աages�����䣩����Ա����grow��int years����ages����years��age������ʾtree�����ages��ֵ */

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