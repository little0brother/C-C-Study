// 1. ����ָ�����������ָ�������?
��: ָ��������һ�����飬����Ԫ��ȫ����ָ��
	����ָ����һ��ָ�룬ָ��һά�������������

// 2. ��ζ���һ��ָ�� int a[10] ���͵�ָ�����������ָ�룩��ʹ��3�ַ�������
1).typedef (*P)[10];
   P p = &a;

2).typedef (P)[10];
   P* p = &a;

3).int(*p)[10];
   p = &a;

// 3. 
	int a[10];
	int b[5][10];
	int (*p)[10];
	p = &a;	//Ϊ�μ� &			��&aָ����a���������׵�ַ��aָ������Ԫ�ص�ַ����ΪpΪ����ָ�����Լ�&
	p = b;	//Ϊ�β��ü� &		��&bָ����������ά�����׵�ַ��bָ�������е�ַ��
	
// 4. int a[3][5] = { 0 };
	//a -> a + 0				: �����׵�ַ	     
	//a + i						: ��i���׵�ַ
	//*(a+i) -> a[i]			: ��i����Ԫ�ص�ַ
	//*(a+i)+j -> &a[i][j]		: ��i�е�j��Ԫ�ص�ַ
	//*(*(a+i)+j ) -> a[i][j]	: ��i�е�j��Ԫ��ֵ
	

// 5. �����ջ�Ͽ���һ����ά���飬����ڶ��Ͽ���һ����ά���飿
	malloc

// 6. int main(int argc, char *argv[]);
//  	argc, argv�ֱ����ʲô��
argc: ���������������������ִ�г���
argv: ָ�����飬ָ������Ĳ���


// 7. �ҵ�������ָ���ַ�����λ��
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
				  
// 8. ���ַ��������������

int sort(char **array1, int num1,
         char (*array2)[30], int num2, 
         char ***myp3 /*out*/, int *num3);

int  main()
{
    int ret = 0; 
    char *p1[] = {"aa", "ccccccc", "bbbbbb"};
    char buf2[10][30] = {"111111", "3333333", "222222"};
    char **p3 = NULL;   
    int len1, len2, len3, i = 0;
                            
    len1 = sizeof(p1)/sizeof(*p1);
    len2 = 3;
                                    
    ret = sort(p1, len1, buf2, len2, &p3, &len3);

    return 0;
}
