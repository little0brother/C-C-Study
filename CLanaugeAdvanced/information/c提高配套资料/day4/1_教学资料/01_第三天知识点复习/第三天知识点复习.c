һ��const��ʹ��
1��const��������Ϊֻ��
	const int a = 10;
	a = 100; //error

	char buf[100] = "abcdef";
	const char *p = buf;	//���������ֳ����� char *p = "123445";
	char const *p = buf;	//����*��ָ��ָ���ܱ䣬ָ��ָ����ڴ治�ܱ�
	//p[0] = '1'; //error
	p = "123456"; //ok
	
	char * const p1 = buf;	//����ָ�������ָ��ָ����ڴ棬ָ��ָ���ܱ�
	//p1 = "123456"; //error
	p1[0] = '1'; //ok
	
	const char * const p2 = buf; //p2, ֻ��

�����༶ָ��
1����ζ���������͵�ָ�����
	//ĳ�������ĵ�ַ��Ҫ����һ����ô�����͵ı�������
	//��������͵Ļ����ϼ�һ��*
	int b;
	int *q = &b;	//һ��ָ��
	int **t = &q;	//����ָ��
	int ***m = &t;	//����ָ��
	
2������ָ�������
	���룺�������������ڴ�
	����������ú��������ڴ�
	
	char *p1 = NULL; //û�з����ڴ�
	int len = 0;
	getMem(&p1, &len); //Ҫ��ͨ���������βθı�ʵ�ε�ֵ�������ַ����
	
	void getMem(char **p1 /*out*/,  int *plen /*in*/)
	{
		//��Ӹ�ֵ����ָ������������塣
		*p1 = malloc(100);
		*plen = 100;
	}
	
3������ָ��������������ڴ�ģ��
	1��
	//ָ�����飬�����ÿ��Ԫ�ض���ָ������
	// [] �����ȼ��� * �ߣ��������飬ÿ��Ԫ�ض���ָ�����ͣ�char *��
	char *myArray[] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};
	
	char **p = {"aaaaaa", "ccccc", "bbbbbb", "111111"}; //err

	void fun(int a[]);
	void fun(int *a); // a[] �ȼ��� *a
	
	void printMyArray(char *myArray[], int num);
	// char *�������ͣ�myArray[]�ȼ��� *myArray
	// char *myArray[] -> char ** myArray
	
	void printMyArray(char **myArray, int num);
	void sortMyArray(char **myArray, int num);
	
	������򣬽�������ָ���ָ����Ϊԭ��ָ��ָ�������ֳ����������ֳ��������ڴ�һ�����䣬�ڴ�Ͳ��ܱ䡣
	
	2��
	//��ά���� 10��30�У�10��һά����a[30]
	//�ܹ�������10���ַ������������ 4 ��
	//ÿ���ַ������Ȳ��ܳ���29����һ��λ�÷Ž�����������0
	char myArray[10][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};

	void printMyArray(char myArray[10][30], int num);
	void sortMyArray(char myArray[10][30], int num);
	
	char a[][30] = {"aaaaaa", "ccccc", "bbbbbbb", "1111111111111"};//ok
	char a[][30]; //err������ʱ�����ʼ��
	
	��ά������������������е�ַ����һ��һά����ĵ�ַ��
	���е�ַ��������Ԫ�ص�ַ��ֵ��һ���ģ��������ǲ�����һ��
	���е�ַ+1������һ�У�һ��30���ֽڣ�+30
	������Ԫ�ص�ַ+1������һ���ַ���һ���ַ�Ϊ1���ֽڣ�+1
	sizeof(a): ��4��һά���飬ÿ�����鳤��Ϊ30��4 * 30 = 120
	sizeof(a[0]): ��0��һά������Ԫ�ص�ַ���൱�ڲ��0��һά����ĳ��ȣ�Ϊ30
	
	char b[30];
	&b��������һά����ĵ�ַ���൱�ڶ�ά�������е�ַ
	b����һά������Ԫ�ص�ַ���൱�ڶ�ά����������Ԫ�ص�ַ
	&b �� b ��ֵ��Ȼ��һ�������ǣ����ǵĲ�����һ��
	&b + 1�� �����������飬+30
	b+1: ����1���ַ���+1
	
	
	//����ͨ�� char ** ��Ϊ�����βΣ���Ϊָ��+1������һ��
	// char **��ָ��+1����Ϊ 4 ���ֽ�
	// char a[][30]��ָ��+1����Ϊ 1 �еĳ��ȣ�����Ϊ 30 ���ֽ�
	void printMyArray(char **buf, int num);
	
	3��
	int a[3];
	int *q = (int *)malloc(3 * sizeof(int)); //�൱��q[3]
	
	//��̬����һ�����飬ÿ��Ԫ�ض���char * //char *buf[3]
	int n = 3;
	char **buf = (char **)malloc(n * sizeof(char *)); //�൱�� char *buf[3]
	for (i = 0; i < n; i++)
	{
		buf[i] = (char *)malloc(30 * sizeof(char));
	}

	
	char **myArray = NULL;
	char **getMem(int num); //�ֹ������ά����
	void printMyArray(char **myArray, int num);
	void sortMyArray(char **myArray, int num);
	void arrayFree(char **myArray, int num);
	
	
4�����ֶ���ָ���ڴ�ģ��ͼ
	

