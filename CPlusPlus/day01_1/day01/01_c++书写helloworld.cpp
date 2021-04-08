#include <iostream> // 标准输入输出流 i-input 输入    o-output 输出  类似于stdio
using namespace std;  // 使用 命名空间 标准

int main()
{
	// cout 输出流对象 向屏幕中输出内容
	// << 在c++中可以有新的意义，可以在cout后拼接向输出的内容
	// endl 结束输出并且换行

	cout << "Hello world!" << endl;
	std::cout << "Hello world!" << endl;

	system("pause");
	return EXIT_SUCCESS;
}