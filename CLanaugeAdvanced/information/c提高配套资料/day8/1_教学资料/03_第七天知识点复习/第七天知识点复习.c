一、链表
1、数组和链表的区别
	数组：一次性分配一块连续的存储区域
	优点：
		随机访问元素效率高
	缺点：
		需要分配一块连续的存储区域（很大区域，有可能分配失败）
		删除和插入某个元素效率低
		
	链表：现实生活中的灯笼
	优点：
		不需要一块连续的存储区域
		删除和插入某个元素效率高
	缺点：
		随机访问元素效率低
	
2、相关概念
	节点：链表的每个节点实际上是一个结构体变量，节点，既有 数据域 也有 指针域
	typedef struct Node
	{
		int id;		//数据域
		struct Node *next;	//指针域
	}SLIST;
	
	尾结点：next指针指向NULL
	
3、结构体套结构体
	typedef struct A
	{
		int b;
	}A;
	/*
	1、结构体可以嵌套另外一个结构体的任何类型变量
	2、结构体嵌套本结构体普通变量（不可以）
		本结构体的类型大小无法确定，类型本质：固定大小内存块别名
	3、结构体嵌套本结构体指针变量（可以）
		指针变量的空间能确定，32位， 4字节， 64位， 8字节
	*/
	typedef struct B
	{
		int a;
		A tmp1; //ok
		A *p1; //ok

		//struct B tmp2; 
		struct B *next; //32位， 4字节， 64位， 8字节	
	}B;
	
4、链表的操作（一定要画图）
	实际上是指针的拓展应用：指向指向谁，就把谁的地址赋值给指针。
	
	typedef struct Stu
	{
		int id;	//数据域
		char name[100];

		struct Stu *next; //指针域
	}Stu;
	
	
	（1）静态链表
	//初始化三个结构体变量
	Stu s1 = { 1, "mike", NULL };
	Stu s2 = { 2, "lily", NULL };
	Stu s3 = { 3, "lilei", NULL };

	
	s1.next = &s2; //s1的next指针指向s2
	s2.next = &s3;
	s3.next = NULL; //尾结点
	
	Stu *p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//结点往后移动一位
		p = p->next; //&s2
	}
	
	（2）动态链表
	//Stu *p1 = NULL;
	//p1 = (Stu *)malloc(sizeof(Stu));
	Stu *p1 = (Stu *)malloc(sizeof(Stu));
	Stu *p2 = (Stu *)malloc(sizeof(Stu));
	Stu *p3 = (Stu *)malloc(sizeof(Stu));
	
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL; //尾节点
	
	Stu *tmp = p1;
	while(tmp != NULL)
	{
		printf("id = %d, name = %s\n", tmp->id, tmp->name);

		//结点往后移动一位
		tmp = tmp->next;
	}

二、函数指针
1、指针函数，它是函数，返回指针类型的函数
	//指针函数
	//()优先级比*高，它是函数，返回值是指针类型的函数
	//返回指针类型的函数
	int *fun2()
	{
		int *p = (int *)malloc(sizeof(int));

		return p;
	}

2、函数指针，它是指针，指向函数的指针，（对比数组指针的用法）

	一个函数在编译时被分配一个入口地址，这个地址就称为函数的指针，函数名代表函数的入口地址。

	函数指针变量，它也是变量，和int a变量的本质是一样的。
	
	int fun(int a)
	{
		printf("a ========== %d\n", a);
		return 0;
	}
	
	//定义函数指针变量有3种方式：
	
	（1）先定义函数类型，根据类型定义指针变量（不常用）
	//有typedef是类型，没有是变量
	typedef int FUN(int a); //FUN是函数类型，类型模式为： int fun(int);
	FUN *p1 = NULL; //函数指针变量
	p1 = fun; //p1 指向 fun 函数
	fun(5);   //传统调用
	p1(6);    //函数指针变量调用方式
	
	（2）先定义函数指针类型，根据类型定义指针变量（常用）
	//()()优先级相同，从左往右看
	//第一个()代表指针，所以，它是指针
	//第二个括号代表函数，指向函数的指针
	typedef int(*PFUN)(int a); //PFUN是函数指针类型
	PFUN p2 = fun; //p2 指向 fun
	p2(7);
	
	（3）直接定义函数指针变量（常用）
	int(*p3)(int a) = fun;
	p3(8);

	int(*p4)(int a);
	p4 = fun;
	p4(9);

3、函数指针数组，它是数组，每个元素都是函数指针类型
	void add() {}
	void minus() {}
	void multi() {}
	void divide() {}
	void myexit() {}
	
	//函数指针变量，fun1指向add()函数
	void(*fun1)() = add;
	fun1();	//调用add()函数
	
	//函数指针数组
	void(*fun[5])() = { add, minus, multi, divide, myexit };
	//指针数组
	char *buf[] = { "add", "min", "mul", "div", "exit" };
	
	char cmd[100];
	int i = 0;
	while (1)
	{
		printf("请输入指令：");
		scanf("%s", cmd);

		for (i = 0; i < 5; i++)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break; //跳出for()循环，最近的循环
			}
		}

	}

4、回调函数，函数的形参为：函数指针变量
	int add(int a, int b)
	{
		return a + b;
	}
	
	int minus(int a, int b)
	{
		return a - b;
	}

	//int(*p)(int a, int b), p 为函数指针变量
	void fun(int x, int y,  int(*p)(int a, int b) )
	{
		int a = p(x, y); //回调函数
		printf("a = %d\n", a);
	}
	
	typedef int(*Q)(int a, int b); //Q 为函数指针类型
	void fun2(int x, int y, Q p)//p 为函数指针变量
	{

		int a = p(x, y); //回调函数
		printf("a = %d\n", a);
	}

	//fun()函数的调用方式
	fun(1, 2, add);

	fun2(10, 5, minus);

三、函数的递归
	递归：函数可以调用函数本身（不要用main()调用main()，不是不行，是没有这么做，往往得不到你想要的结果）
	
	（1）普通函数调用（栈结构，先进后出，先调用，后结束）
	void funB(int b)
	{
		printf("b = %d\n", b);
		
		return;
	}
	
	void funA(int a)
	{
		funB(a-1);
		
		printf("a = %d\n", a);
	}

	调用流程：
	funA(2) -> funB(1) -> printf(b) （离开funB()，回到funA()函数）-> printf(a)
	
	
	（2）函数递归调用(调用流程和上面是一样，换种模式，都是函数的调用而已)
	void fun(int a)
	{
		if(a == 1)
		{
			printf("a == %d\n", a);
			return; //中断函数很重要
		}
		
		fun(a-1);
		
		
		printf("a = %d\n", a);
	}
	
	fun(2);
	
	




