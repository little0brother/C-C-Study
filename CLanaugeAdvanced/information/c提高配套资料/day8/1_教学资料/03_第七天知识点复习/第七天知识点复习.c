һ������
1����������������
	���飺һ���Է���һ�������Ĵ洢����
	�ŵ㣺
		�������Ԫ��Ч�ʸ�
	ȱ�㣺
		��Ҫ����һ�������Ĵ洢���򣨺ܴ������п��ܷ���ʧ�ܣ�
		ɾ���Ͳ���ĳ��Ԫ��Ч�ʵ�
		
	������ʵ�����еĵ���
	�ŵ㣺
		����Ҫһ�������Ĵ洢����
		ɾ���Ͳ���ĳ��Ԫ��Ч�ʸ�
	ȱ�㣺
		�������Ԫ��Ч�ʵ�
	
2����ظ���
	�ڵ㣺�����ÿ���ڵ�ʵ������һ���ṹ��������ڵ㣬���� ������ Ҳ�� ָ����
	typedef struct Node
	{
		int id;		//������
		struct Node *next;	//ָ����
	}SLIST;
	
	β��㣺nextָ��ָ��NULL
	
3���ṹ���׽ṹ��
	typedef struct A
	{
		int b;
	}A;
	/*
	1���ṹ�����Ƕ������һ���ṹ����κ����ͱ���
	2���ṹ��Ƕ�ױ��ṹ����ͨ�����������ԣ�
		���ṹ������ʹ�С�޷�ȷ�������ͱ��ʣ��̶���С�ڴ�����
	3���ṹ��Ƕ�ױ��ṹ��ָ����������ԣ�
		ָ������Ŀռ���ȷ����32λ�� 4�ֽڣ� 64λ�� 8�ֽ�
	*/
	typedef struct B
	{
		int a;
		A tmp1; //ok
		A *p1; //ok

		//struct B tmp2; 
		struct B *next; //32λ�� 4�ֽڣ� 64λ�� 8�ֽ�	
	}B;
	
4������Ĳ�����һ��Ҫ��ͼ��
	ʵ������ָ�����չӦ�ã�ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��ָ�롣
	
	typedef struct Stu
	{
		int id;	//������
		char name[100];

		struct Stu *next; //ָ����
	}Stu;
	
	
	��1����̬����
	//��ʼ�������ṹ�����
	Stu s1 = { 1, "mike", NULL };
	Stu s2 = { 2, "lily", NULL };
	Stu s3 = { 3, "lilei", NULL };

	
	s1.next = &s2; //s1��nextָ��ָ��s2
	s2.next = &s3;
	s3.next = NULL; //β���
	
	Stu *p = &s1; 

	while (p != NULL)
	{
		printf("id = %d, name = %s\n", p->id, p->name);

		//��������ƶ�һλ
		p = p->next; //&s2
	}
	
	��2����̬����
	//Stu *p1 = NULL;
	//p1 = (Stu *)malloc(sizeof(Stu));
	Stu *p1 = (Stu *)malloc(sizeof(Stu));
	Stu *p2 = (Stu *)malloc(sizeof(Stu));
	Stu *p3 = (Stu *)malloc(sizeof(Stu));
	
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL; //β�ڵ�
	
	Stu *tmp = p1;
	while(tmp != NULL)
	{
		printf("id = %d, name = %s\n", tmp->id, tmp->name);

		//��������ƶ�һλ
		tmp = tmp->next;
	}

��������ָ��
1��ָ�뺯�������Ǻ���������ָ�����͵ĺ���
	//ָ�뺯��
	//()���ȼ���*�ߣ����Ǻ���������ֵ��ָ�����͵ĺ���
	//����ָ�����͵ĺ���
	int *fun2()
	{
		int *p = (int *)malloc(sizeof(int));

		return p;
	}

2������ָ�룬����ָ�룬ָ������ָ�룬���Ա�����ָ����÷���

	һ�������ڱ���ʱ������һ����ڵ�ַ�������ַ�ͳ�Ϊ������ָ�룬����������������ڵ�ַ��

	����ָ���������Ҳ�Ǳ�������int a�����ı�����һ���ġ�
	
	int fun(int a)
	{
		printf("a ========== %d\n", a);
		return 0;
	}
	
	//���庯��ָ�������3�ַ�ʽ��
	
	��1���ȶ��庯�����ͣ��������Ͷ���ָ������������ã�
	//��typedef�����ͣ�û���Ǳ���
	typedef int FUN(int a); //FUN�Ǻ������ͣ�����ģʽΪ�� int fun(int);
	FUN *p1 = NULL; //����ָ�����
	p1 = fun; //p1 ָ�� fun ����
	fun(5);   //��ͳ����
	p1(6);    //����ָ��������÷�ʽ
	
	��2���ȶ��庯��ָ�����ͣ��������Ͷ���ָ����������ã�
	//()()���ȼ���ͬ���������ҿ�
	//��һ��()����ָ�룬���ԣ�����ָ��
	//�ڶ������Ŵ�������ָ������ָ��
	typedef int(*PFUN)(int a); //PFUN�Ǻ���ָ������
	PFUN p2 = fun; //p2 ָ�� fun
	p2(7);
	
	��3��ֱ�Ӷ��庯��ָ����������ã�
	int(*p3)(int a) = fun;
	p3(8);

	int(*p4)(int a);
	p4 = fun;
	p4(9);

3������ָ�����飬�������飬ÿ��Ԫ�ض��Ǻ���ָ������
	void add() {}
	void minus() {}
	void multi() {}
	void divide() {}
	void myexit() {}
	
	//����ָ�������fun1ָ��add()����
	void(*fun1)() = add;
	fun1();	//����add()����
	
	//����ָ������
	void(*fun[5])() = { add, minus, multi, divide, myexit };
	//ָ������
	char *buf[] = { "add", "min", "mul", "div", "exit" };
	
	char cmd[100];
	int i = 0;
	while (1)
	{
		printf("������ָ�");
		scanf("%s", cmd);

		for (i = 0; i < 5; i++)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break; //����for()ѭ���������ѭ��
			}
		}

	}

4���ص��������������β�Ϊ������ָ�����
	int add(int a, int b)
	{
		return a + b;
	}
	
	int minus(int a, int b)
	{
		return a - b;
	}

	//int(*p)(int a, int b), p Ϊ����ָ�����
	void fun(int x, int y,  int(*p)(int a, int b) )
	{
		int a = p(x, y); //�ص�����
		printf("a = %d\n", a);
	}
	
	typedef int(*Q)(int a, int b); //Q Ϊ����ָ������
	void fun2(int x, int y, Q p)//p Ϊ����ָ�����
	{

		int a = p(x, y); //�ص�����
		printf("a = %d\n", a);
	}

	//fun()�����ĵ��÷�ʽ
	fun(1, 2, add);

	fun2(10, 5, minus);

���������ĵݹ�
	�ݹ飺�������Ե��ú���������Ҫ��main()����main()�����ǲ��У���û����ô���������ò�������Ҫ�Ľ����
	
	��1����ͨ�������ã�ջ�ṹ���Ƚ�������ȵ��ã��������
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

	�������̣�
	funA(2) -> funB(1) -> printf(b) ���뿪funB()���ص�funA()������-> printf(a)
	
	
	��2�������ݹ����(�������̺�������һ��������ģʽ�����Ǻ����ĵ��ö���)
	void fun(int a)
	{
		if(a == 1)
		{
			printf("a == %d\n", a);
			return; //�жϺ�������Ҫ
		}
		
		fun(a-1);
		
		
		printf("a = %d\n", a);
	}
	
	fun(2);
	
	




