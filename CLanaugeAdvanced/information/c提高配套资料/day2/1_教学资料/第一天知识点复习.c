一、学习标准
	//第一套api接口
	int socketclient_init(void **handle);
	int socketclient_send(void *handle, unsigned char *buf, int len);
	int socketclient_recv(void *handle, unsigned char *buf, int *len);
	int socketclient_destory(void *handle);

	//第二套api接口
	int socketclient_init2(void **handle);
	int socketclient_send2(void *handle, unsigned char *buf, int len);
	int socketclient_recv2(void *handle, unsigned char **buf, int *len);
	int socketclient_free(unsigned char **buf);
	int socketclient_destory2(void **handle);
	
二、听课标准
	1）选择法排序
	2）会简单封装函数
	3）数组做函数参数会退化为一级指针
	 a)数组做函数参数时，应该把数组元素个数也传递给函数
	 b)形参中的数组，编译器把它当做指针处理，C语言的特色
	 c)实参中的数组，和形参中数组本质不一样
	 void fun(int a[]);// 4字节
	 main()
	 {
		 int a[] = {1, 2, 3}; // 12个字节
		 fun(a);
	 }
	
三、数据类型
	1）类型的本质：固定内存大小的别名
	2）数据类型的作用：编译器预算对象（变量）分配的内存空间大小
		int a;  //告诉c编译器分配4个字节的内存
	3）数据类型可以通过typedef起别名
	4）可以通过sizeof() 测类型大小
	5）void数据类型（无类型，万能类型）
	 a)如果函数没有返回值，必须用void修饰: void fun(int a);
	 b)如果函数没有参数，参数可以用void修饰: int fun(void);
	 c)不能定义void类型的普通变量, void a; //error，不能确定分配多大空间
	 d)void *p; //ok， 万能指针， 指针类型都是 4 个指针，函数参数，函数返回值
	 
	 int b[10];
	//b, &b的数组类型不一样
	//b， 数组首元素地址， 一个元素4字节，+1， +4
	//&b, 整个数组的首地址，一个数组4*10  = 40字节，+1， +40


四、拓展知识
	1）分文件时，头文件防止头文件重复包含
	#pragma  once
	
	2）让C代码可以在C++编译器编译运行
	//__cplusplus是编译器提供好的宏，不是自定义的
	#ifdef __cplusplus
	extern "C"{
	#endif // __cplusplus
	
	//函数的声明
	
	#ifdef __cplusplus
	}
	#endif // __cplusplus
	
五、变量
	1）变量本质：内存空间的别名
	2）必须通过数据类型定义变量
	3）变量相当于门牌号，内存相当于房间，通过门牌号找到房间，通过变量找到所对应的内存
	4）变量的赋值：1）直接   2）间接
		int a;
		a = 100; //直接赋值
		
		int *p = 0;
		p = &a;	  //指针指向谁，就把谁的地址赋值给指针
		*p = 222; //间接赋值
	4）重点：没有变量，哪来内存，没有内存，哪里内存首地址
	5）变量三要素(名称、大小、作用域)，变量的生命周期
	
六、内存四区（栈区、堆区、全局区、代码区）
	1）栈区：系统分配空间，系统自动回收，函数内部定义的变量，函数参数，函数结束，其内部变量生命周期结束
	2）堆区：程序员动态分配空间，由程序员手动释放，没有手动释放，分配的空间一直可用
	3）全局区（全局变量和静态变量，里面又分为初始化区和未初始化区，文字常量区：字符常量）：整个程序运行完毕，系统自动回收

	4）内存四区模型图（C语言学好指针的关键）

	5）a) 栈区地址生长方向：地址由上往下递减
	   b) 堆区地址生成方向：地址由下往上递增
	   c) 数组buf, buf+1 地址永远递增
	   
七、函数调用模型
	1）程序各个函数运行流程（压栈弹栈，入栈出栈，先进后出）
	
八、指针也是一种数据类型
	1）指针变量也是一种变量，也有空间，32位程序大小为4个字节
	int *p = 0x1122;
	
	2）*操作符，*相当于钥匙，通过*可以找到指针所指向的内存区域
	int a = 10;
	int *p = NULL;
	p = &a; //指针指向谁，就把谁的地址赋值给指针
	
	*p = 22;	//*放=左边，给内存赋值，写内存
	int b = *p; //*放=右边，取内存的值，读内存
	
	
	






	 
	 