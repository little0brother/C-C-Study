一、const的使用
1）const声明变量为只读
	const int a = 10;
	a = 100; //error

	char buf[100] = "abcdef";
	const char *p = buf;	//类似于文字常量区 char *p = "123445";
	char const *p = buf;	//修饰*，指针指向能变，指针指向的内存不能变
	//p[0] = '1'; //error
	p = "123456"; //ok
	
	char * const p1 = buf;	//修饰指针变量，指针指向的内存，指针指向不能变
	//p1 = "123456"; //error
	p1[0] = '1'; //ok
	
	const char * const p2 = buf; //p2, 只读

二、多级指针
1）如何定义合适类型的指针变量
	//某个变量的地址需要定义一个怎么样类型的变量保存
	//在这个类型的基础上加一个*
	int b;
	int *q = &b;	//一级指针
	int **t = &q;	//二级指针
	int ***m = &t;	//三级指针
	
2）二级指针做输出
	输入：主调函数分配内存
	输出：被调用函数分配内存
	
	char *p1 = NULL; //没有分配内存
	int len = 0;
	getMem(&p1, &len); //要想通过函数的形参改变实参的值，必须地址传递
	
	void getMem(char **p1 /*out*/,  int *plen /*in*/)
	{
		//间接赋值，是指针存在最大的意义。
		*p1 = malloc(100);
		*plen = 100;
	}
	
3）二级指针做输入的三种内存模型
	1、
	//指针数组，数组的每个元素都是指针类型
	// [] 的优先级比 * 高，它是数组，每个元素都是指针类型（char *）
	char *myArray[] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};
	
	char **p = {"aaaaaa", "ccccc", "bbbbbb", "111111"}; //err

	void fun(int a[]);
	void fun(int *a); // a[] 等价于 *a
	
	void printMyArray(char *myArray[], int num);
	// char *代表类型，myArray[]等价于 *myArray
	// char *myArray[] -> char ** myArray
	
	void printMyArray(char **myArray, int num);
	void sortMyArray(char **myArray, int num);
	
	如果排序，交换的是指针的指向，因为原来指针指向是文字常量区，文字常量区的内存一旦分配，内存就不能变。
	
	2、
	//二维数组 10行30列，10个一维数组a[30]
	//总共能容量10行字符串，这个用了 4 行
	//每行字符串长度不能超过29，留一个位置放结束符：数字0
	char myArray[10][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};

	void printMyArray(char myArray[10][30], int num);
	void sortMyArray(char myArray[10][30], int num);
	
	char a[][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};//ok
	char a[][30]; //err，定义时必须初始化
	
	二维数组的数组名代表首行地址（第一行一维数组的地址）
	首行地址和首行首元素地址的值是一样的，但是它们步长不一样
	首行地址+1，跳过一行，一行30个字节，+30
	首行首元素地址+1，跳过一个字符，一个字符为1个字节，+1
	sizeof(a): 有4个一维数组，每个数组长度为30，4 * 30 = 120
	sizeof(a[0]): 第0个一维数组首元素地址，相当于测第0个一维数组的长度：为30
	
	char b[30];
	&b代表整个一维数组的地址，相当于二维数组首行地址
	b代表一维数组首元素地址，相当于二维数组首行首元素地址
	&b 和 b 的值虽然是一样，但是，它们的步长不一样
	&b + 1： 跳过整个数组，+30
	b+1: 跳过1个字符，+1
	
	
	//不能通过 char ** 作为函数形参，因为指针+1步长不一样
	// char **，指针+1步长为 4 个字节
	// char a[][30]，指针+1步长为 1 行的长度，这里为 30 个字节
	void printMyArray(char **buf, int num);
	
	3、
	int a[3];
	int *q = (int *)malloc(3 * sizeof(int)); //相当于q[3]
	
	//动态分配一个数组，每个元素都是char * //char *buf[3]
	int n = 3;
	char **buf = (char **)malloc(n * sizeof(char *)); //相当于 char *buf[3]
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
	}

	
	char **myArray = NULL;
	char **getMem(int num); //手工打造二维数组
	void printMyArray(char **myArray, int num);
	void sortMyArray(char **myArray, int num);
	void arrayFree(char **myArray, int num);
	
	
4）三种二级指针内存模型图
	

