1���ṹ�����ͻ�������
	1���ṹ�����Ͷ���
	//struct�ṹ��ؼ���
	//struct STU����������������
	//{}�����и��ֺ�
	struct Stu
	{
		char name[32];
		char tile[32];
		int age;
		char addr[50];
	};
	
	//ͨ��typedef��struct Stu����ΪStu
	typedef struct Stu
	{
		int a;
	}Stu;
	
	2���ṹ������Ķ���
	//1)�ȶ������ͣ��ٶ�����������
	struct Stu a;
	
	//2)�������͵�ͬʱ���������
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
	
	3���ṹ�������ʼ��
	//�������ͬʱʱ��ʼ��
	struct Stu g = { "lily", "teacher", 22, "guangzhou" };

	4��������ָ�뷨�����ṹ���Ա
	//�������� �������
	struct Stu h;
	strcpy(h.name, "^_^");
	(&h)->name
	
	//ָ�뷨�� ->
	struct Stu *p;
	p = &h;
	strcpy(p->name, "abc");
	(*p).name

	
	5���ṹ������
	//�ṹ������
	typedef struct Teacher
	{
		char name[32];
		int age;
	}Teacher;
	
	//����ṹ�����飬ͬʱ��ʼ��
	Teacher t1[2] = 
	{
		{ "lily", 18 },
		{ "lilei", 22 }
	};
	
	Teacher t1[2] = {"lily", 18, "lilei", 22 };

2���ṹ����ָ��
	//�ṹ������
	typedef struct Teacher
	{
		char *name;
		int age;
	}Teacher;
	
	//�ṹ������
	typedef struct Teacher
	{
		char *name;
		char **stu;
		int age;
	}Teacher;
	
3���ṹ�帳ֵ
	Teacher t1 = { "lily", "teacher", 18, "beijing" };
	//��ͬ���͵Ľṹ������������໥��ֵ
	//��t1ÿ����Ա��������һ������t2��Ӧ�ĳ�Ա��
	Teacher t2 = t1;
	
4��ǳ���������
	typedef struct Teacher
	{
		char *name;
		int age;
	}Teacher;
	
	//�ṹ����Ƕ��ָ�룬���Ҷ�̬����ռ�
	//ͬ���ͽṹ������໥��ֵ
	//��ͬ�ṹ���Աָ�����ָ��ͬһ���ڴ�
	Teacher t1;
	t1.name = (char *)malloc(30);
	strcpy(t1.name, "lily");
	t1.age = 22;

	Teacher t2;
	t2 = t1;
	
	//�������Ϊ�����ڴ棬���¿���һ��
	t2.name = (char *)malloc(30);
	strcpy(t2.name, t1.name);

	
5���ṹ��ƫ�������˽⣩
	//�ṹ�����Ͷ����������ڲ��ĳ�Ա�������ڴ沼���Ѿ�ȷ��
	typedef struct Teacher
	{
		char name[64]; //64
		int age;	//4
		int id;	 //4
	}Teacher;
	
	Teacher t1;
	Teacher *p = &t1;

	int n1 = (int)(&p->age) - (int)p;  //����ڽṹ���׵�ַ
	int n2 = (int)&((Teacher *)0)->age; //����0��ַ��ƫ����

6���ṹ���ֽڶ��루�Կռ任ʱ�䣩�������뿴���ṹ���ֽڶ������.doc��


	