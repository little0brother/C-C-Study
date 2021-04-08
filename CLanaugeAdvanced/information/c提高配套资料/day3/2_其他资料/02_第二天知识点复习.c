一、指针强化
1、指针也是一种数据类型，指针变量也是一种变量，和int a本质是一样的
	1）指针变量也是一种变量，也有空间，32位程序大小为4个字节
	int *p = 0x1122;
	
	2）*操作符，*相当于钥匙，通过*可以找到指针所指向的内存区域
	int a = 10;
	int *p = NULL;
	p = &a; //指针指向谁，就把谁的地址赋值给指针
	
	*p = 22;	//*放=左边，给内存赋值，写内存
	int b = *p; //*放=右边，取内存的值，读内存
	
	3）指针变量，和指向指向的内存是两个不同的概念
	char *p = NULL; 
	char buf[] = "abcdef";
	//改变指针变量的值
	p = buf; 
	
	p = p + 1; //改变了指向变量的值，改变了指针的指向
	
	*p = 'm'; //改变指针指向的内存，并不会影响到指针的值
	
	4）写内存时，一定要确保内存可写
	char *buf2 = "sadgkdsjlgjlsdk"; //文字常量区，内存不可改
	//buf2[2] = '1'; //err
	
2、间接赋值（*p）是指针存在最大意义
	1）间接赋值三大条件
		a) 两个变量
		b) 建立关系
		c) 通过 * 操作符进行间接赋值
		
		1)
		int a;
		int *p;  //两个变量
		p = &a;  //建立关系
		*p = 100; //通过 * 操作符进行间接赋值
		
		2)
		int b;
		fun(&b); //两个变量之一：实参，给函数传参时，相当于建立关系
		
		//p = &b
		void fun(int *p) //两个变量之一：形参参
		{
			*p = 100; //通过 * 操作符进行间接赋值
		}
	
	2、如何定义合适类型的指针变量
	//某个变量的地址需要定义一个怎么样类型的变量保存
	//在这个类型的基础上加一个*
	int b;
	int *q = &b;
	int **t = &q;
	
	重要：如果想通过函数形参改变实参的值，必须传地址
	1、值传递，形参的任何修改不会影响到实参
	2、地址传递，形参（通过*操作符号）的任何修改会影响到实参
	
	用1级指针形参，去间接修改了0级指针(实参)的值。
	用2级指针形参，去间接修改了1级指针(实参)的值。
	用3级指针形参，去间接修改了2级指针(实参)的值。
	用n级指针形参，去间接修改了n-1级指针(实参)的值。
		
	int a = 10;
	fun(a); //值传递
	void fun(int b)
	{
		b = 20;
	}
	
	fun2(&a);//地址传递
	void fun2(int *p)
	{
		*p = 20; //通过*操作内存
	}
	
	int *p = 0x1122;
	void fun3(p);//值传递
	void fun3(int *p)
	{
		p = 0x2233;
	}
	
	void fun4(&p);//地址传递
	void fun4(int **p)
	{
		*p = 0xaabb; //通过*操作内存
	}
	
3、不允许向NULL和未知非法地址拷贝内存
	char *p = NULL;
	//给p指向的内存区域拷贝内容
	strcpy(q, "1234"); //err
	
	//静态
	char buf[100];
	p = buf;
	strcpy(q, "1234"); //ok
	
	//动态
	p = (char *)malloc(sizeof(char) * 10 );
	strcpy(q, "1234"); //ok
	
	char *q = "123456";
	strcpy(q, "abcd"); //?
	
4、void *指针的使用
	void *p = 0x1122; //可以这么做，不建议，一般赋值为NULL
	char buf[1024] = "abcd";
	p = (void *)buf; //指向 char 
	printf("p = %s\n", (char *)p); //使用时转化为实际类型指针
	
	int a[100] = { 1, 2, 3, 4 };
	p = (void *)a;  //指向 int
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		//使用时转化为实际类型指针
		int *tmp = (int *)p;
		printf("%d ", *(tmp+i));
		printf("%d ", tmp[i]);
		
		printf("%d ", *( (int *)p + i ) );
	}
	
	void * 常用于函数参数：memset(), memcpy()
	
5、栈区返回变量的值和变量的地址区别
	int fun()
	{
		int a = 10;
		return a;
	}
	
	int *fun2()
	{
		int a = 10;
		return &a;
	}
	
	int *fun3()
	{
		static int a = 10;
		return &a;
	}
	
	int b = fun(); //ok, b的值为10
	
	//也ok, p确实也保存了fun2()内部a的地址
	//但是，fun2完毕，a就释放，p就指向未知区域
	int *p = fun2(); 
	
	//ok，fun3()中的a在全局区，函数运行完毕，a的空间不释放
	int *q = fun3();
	
6、.c -> 可执行程序过程
	预处理：宏定义展开、头文件展开、条件编译，这里并不会检查语法
	编译：检查语法，将预处理后文件编译生成汇编文件
	汇编：将汇编文件生成目标文件(二进制文件)
	链接：将目标文件链接为可执行程序
	程序只有在运行才加载到内存（由系统完成），但是某个变量具体分配多大，是在编译阶段就已经确定了，换句话说，在编译阶段做完处理后，程序运行时系统才知道分配多大的空间，所以，很多时候说，这个变量的空间在编译时就分配（确定）了。
	
7、	指针做函数参数的输入输出特性
	输入：主调函数分配内存
	输出：被调用函数分配内存
	
	//结合内存四区模型图
	main()
	{
		char buf[100] = "123456";
		fun1(buf);  //输入
		
		char *p = NULL;
		fun2(&p); //输出
		
		//因为p在fun2()动态分配空间了，使用完毕应该释放
		if(p != NULL)
		{
			free(p);
			p = NULL;
		}
	}
	
	void fun1(char *p /*in*/)
	{
		strcpy(p, "1234")
	}
	
	void fun2(char **p /*out*/)
	{
		char *tmp = malloc(100);
		strcpy(tmp, "1234");
		*p = tmp; //间接赋值是指针存在最大意义，通过*操作内存
	}
	
8、变量内存的值和变量的地址
	int a = 0;
	a变量内存的值为0
	a变量的地址(&a)绝对不为0，只要定义了变量，系统会自动为其分配空间（一个合法不为0的地址）
	
二、字符串操作
1、字符串基本操作
	1）字符串初始化
	/* C语言没有字符串类型，用字符数组模拟
	   C语言字符串以数字0，或字符 '\0' 结尾，数字 0 和字符 '\0' 等价 */
		
	char str1[100] = { 'a', 'b', 'c', 'd' }; //没赋值的自动以数字0填充
	char str2[] = { 'a', 'b', 'c', 'd' };   //数组长度为4，结尾没有数字0
	char str4[] = "abcdef"; //常用赋值方式，栈区
	char *p = "abcdef"; //文字常量区，内容不允许被修改
	
	char *buf = (char *)malloc(100); //堆区
	strcpy(buf, "abcd"); //"abcd"拷贝到buf指向的内存区域中

	2）sizeof和strlen区别
	//使用字符串初始化，常用
	char buf8[] = "abc";
	//strlen: 测字符串长度，不包含数字0，字符'\0'
	//sizeof：测数组长度，包含数字0，字符'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));

	char buf9[100] = "abc";
	printf("strlen = %d, sizeof = %d\n", strlen(buf9), sizeof(buf9));
	
	3）'\0' 后面最好别跟数字，因为几个数字合起来有可能是一个转义字符
	//\012相当于\n
	char str[] = "\0129";
	printf("%s aaaa\n", str);
	
	4）字符'\0', 数字0, 字符'0', NULL的区别
	a) 字符'\0'  ASCII码值为 0 的字符
	   字符'\0' 和 数字 0 是等级的，'\0'中'\'是转义字符
	  
		char buf[100];
		//下面是等级，在数组第10个位置设置字符串结束符
		buf[10] = 0;
		buf[10] = '\0'; 
	
	b) 字符'0'是字符串的某个字符内容为'0', ASCII码值为 48 的字符
		char buf[100];
		buf[0] = '0'; //第0个字符为字符 '0'
	
	c) NULL 标准头文件（stdio.h）的宏 其值为数字 0
	
	
	4）数组法、指针法操作字符串
	char buf[] = "abdgdgdsg"
	char *p = buf;  //buf是数组首元素地址，它也是指针
	for (i = 0; i < strlen(buf); i++)
	{
		//[] 和 * 操作是等价的，也是操作指针指向内存
		printf("%c ", buf[i]); //符合程序员习惯
		printf("%c ", p[i]); 	//符合程序员习惯
		printf("%c ", *(p+i)); 
		printf("%c ", *(buf + i));
	}
	
	注意：数组名也是指针，数组首元素地址，但是，它是一个只读常量
	p++; //ok
	buf++; //err
	
	5）字符串拷贝函数
	int  my_strcpy(char *dst, char *src)
	{
		if (dst == NULL || src == NULL){
			return -1;
		}

		//辅助变量把形参接过来
		char *to = dst;
		char *from = src;

		//*dst = *src
		//dst++， src++
		//判断 *dst是否为0, 为0跳出循环
		while (*to++ = *from++) ;

		return 0;
	}
	
	
2、项目开发常用字符串应用模型
	1、利用strstr标准库函数找出一个字符串中substr出现的个数
	char *p = "11abcd111122abcd333abcd3322abcd3333322qqq";
	int n = 0;
	do {
		p = strstr(p, "abcd");
		if (p != NULL)
		{
			n++; //累计个数
			//重新设置查找的起点
			p = p + strlen("abcd");
		}
		else //如果没有匹配的字符串，跳出循环
		{
			break;
		}
	} while (*p != 0); //如果没有到结尾
	
	
	2、两头堵模型
	char *p = "      abcddsgadsgefg      ";
	int begin = 0;
	int end = strlen(p) - 1; 
	int n = 0;
	
	if(end < 0){
		return;
	}
	
	//从左往右移动，如果当前字符为空，而且没有结束
	while (p[begin] == ' ' && p[begin] != 0)
	{
		begin++; //位置从右移动一位
	}

	//从右往左移动，如果当前字符为空
	while (p[end] == ' ')
	{
		end--; //往左移动
	}

	n = end - begin + 1; //非空元素个数

	strncpy(buf, p + begin, n);
	buf[n] = 0;
	
	//如何证明strncpy()拷贝不会自动加字符串结束符'\0'
	char dst[] = "aaaaaaaaaaaaaaa";
	strncpy(dst, "123", 3);
	printf("dst = %s\n", dst); //dst = "123aaaaaaaaaaaa"
		