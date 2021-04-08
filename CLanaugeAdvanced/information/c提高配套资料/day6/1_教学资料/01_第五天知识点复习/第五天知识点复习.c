1、结构体类型基本操作
	1）结构体类型定义
	//struct结构体关键字
	//struct STU合起来才是类型名
	//{}后面有个分号
	struct Stu
	{
		char name[32];
		char tile[32];
		int age;
		char addr[50];
	};
	
	//通过typedef把struct Stu改名为Stu
	typedef struct Stu
	{
		int a;
	}Stu;
	
	2）结构体变量的定义
	//1)先定义类型，再定义变量，最常用
	struct Stu a;
	
	//2)定义类型的同时，定义变量
	struct _Stu
	{
		char name[32];
		char tile[32];
		int age;
		char addr[50];
	}c;
	
	struct 
	{
		char name[32];
		char tile[32];
		int age;
		char addr[50];
	}e, f;
	
	3）结构体变量初始化
	//定义变量同时时初始化
	struct Stu g = { "lily", "teacher", 22, "guangzhou" };

	4）变量和指针法操作结构体成员
	//变量法， 点运算符
	struct Stu h;
	strcpy(h.name, "^_^");
	(&h)->name
	
	//指针法， ->
	struct Stu *p;
	p = &h;
	strcpy(p->name, "abc");
	(*p).name

	
	5）结构体数组
	//结构体类型
	typedef struct Teacher
	{
		char name[32];
		int age;
	}Teacher;
	
	//定义结构体数组，同时初始化
	Teacher t1[2] = 
	{
		{ "lily", 18 },
		{ "lilei", 22 }
	};
	
	Teacher t1[2] = {"lily", 18, "lilei", 22 };

2、结构体套指针
	//结构体类型
	typedef struct Teacher
	{
		char *name;
		int age;
	}Teacher;
	
	//结构体类型
	typedef struct Teacher
	{
		char *name;
		char **stu;
		int age;
	}Teacher;
	
3、结构体赋值
	Teacher t1 = { "lily", "teacher", 18, "beijing" };
	//相同类型的结构体变量，可以相互赋值
	//把t1每个成员的内容逐一拷贝到t2对应的成员中
	Teacher t2 = t1;
	
4、浅拷贝和深拷贝
	typedef struct Teacher
	{
		char *name;
		int age;
	}Teacher;
	
	//结构体中嵌套指针，而且动态分配空间
	//同类型结构体变量相互赋值
	//不同结构体成员指针变量指向同一块内存
	Teacher t1;
	t1.name = (char *)malloc(30);
	strcpy(t1.name, "lily");
	t1.age = 22;

	Teacher t2;
	t2 = t1;
	
	//深拷贝，人为增加内存，重新拷贝一下
	t2.name = (char *)malloc(30);
	strcpy(t2.name, t1.name);

	
5、结构体偏移量（了解）
	//结构体类型定义下来，内部的成员变量的内存布局已经确定
	typedef struct Teacher
	{
		char name[64]; //64
		int age;	//4
		int id;	 //4
	}Teacher;
	
	Teacher t1;
	Teacher *p = &t1;

	int n1 = (int)(&p->age) - (int)p;  //相对于结构体首地址
	int n2 = (int)&((Teacher *)0)->age; //绝对0地址的偏移量

6、结构体字节对齐（以空间换时间），详情请看《结构体字节对齐规则.doc》


	