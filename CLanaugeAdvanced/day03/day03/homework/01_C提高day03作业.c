1. 	char buf[] = "abcdef";

	//������ɶ����
	const char *p = buf;
	char const *p = buf;
	char * const p = buf;
	const char *const *p = buf;

��: const char *p ��ʾָ��ָ����ڴ�����ݲ����޸�
	char const *p ��ͬ
	char *const p ��ʾָ���ָ�����޸�
	const char* const *p ��ʾָ���ָ����ָ��ָ����ڴ�鶼�����޸� 
	

2.	char *p1[] = {"1111", "2222", "3333"};
	sizeof(p1)/sizeof(p1[0]) = ?	

	��: sizeof(p1) = 12		sizeof(p1[0]) = 4
	
	char *p2[10] = {"1111", "2222", "3333"};
	sizeof(p2)/sizeof(p2[0]) = ?	

	��: sizeof(p2) = 40		sizeof(p2[0]) = 4
	
	char p3[][30] = {"1111", "2222", "3333"};
	sizeof(p3)/sizeof(p3[0]) = ?	

	��: sizeof(p3) = 90		sizeof(p3[0]) = 30
	
	char p4[10][30] = {"1111", "2222", "3333"};
	sizeof(p4)/sizeof(p4[0]) = ?	

	��: sizeof(p4) = 300		sizeof(p4[0]) = 30



3. char buf[][30] = {"1111", "2222", "3333"};
	��ά����������������Ϊʲô������ôд��
	void fun(char **buf);
	�𣺴���ʱ������λָ�������������������++����ʱ���ᵼ�£�һ��ֻ��Ų��4λ���������ƶ����ڶ���Ԫ����ʼ��ַ
	
	void fun(char **buf) �� void fun(char buf[][30]) ��ʲô����
		��: ��һ�ֶ�buf��ָ����λʱ����Ϊ ָ�����ͳ���Ϊ4
			�ڶ��ִ���Ϊ��ά���飬ÿ����λ��������Ϊ30


4. �������ֶ���ָ���ڴ�ģ��ͼ

	mian()
	{
		//ָ������
		char *p1[] = {"123", "456", "789"};

		//��ά����
		char p2[3][4]  = {"123", "456", "789"};  

		//�ֹ���ά�ڴ�
		char **p3 = (char **)malloc(3 * sizeof(char *)); //char *array[3];

		int i = 0;
		for (i=0; i<3; i++)
		{
			p3[i] = (char *)malloc(10*sizeof(char)); //char buf[10]

			sprintf(p3[i], "%d%d%d", i, i, i);
		}
		
	}
	
5. ���ַ�����������������abcd11111abcd2222abcdqqqqq����,��дһ�������ӿڣ�������½����
	���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
	Ҫ��
		1. ��ȷʵ�ֽӿں͹���
		2. ��д��������
	/*
	src:    ԭ�ַ���
	dst:    ���ɵĻ���Ҫ�����ַ���
	sub:    ��Ҫ���ҵ����ַ���
	new_sub:�ỻ�������ַ���

	return : 0 �ɹ�
			-1 ʧ��
	*/
	int replaceSubstr(/* in */char *src, /* out */char** dst, 
                 /* in */char *sub,  /* in */char *new_sub);

6. ��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeee,ssss,����

	д��������(API)��������½��
	��һ��API(�ڶ����ڴ�ģ�ͣ� ��ά����)
	1)�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ������
	2)�Ѷ�ά��������������Ҳ����
	int spitString(const char *str, char c, char buf[10][30]/*in*/, int *count);

	�ڶ���API(�������ڴ�ģ�ͣ���̬���ɶ�ά�ڴ�)
	1)�Զ��ŷָ��ַ������γ�һ������ָ�롣
	2)��һ����ֶ������ַ�����������
	int spitString2(const char *str, char c, char **myp /*in*/, int *count);

	Ҫ��
	1, ����ȷ��﹦�ܵ�Ҫ�󣬶�����ӿڡ�
	2, ��ȷʵ�ֽӿں͹���.
	3, ��д��ȷ�Ĳ�������.