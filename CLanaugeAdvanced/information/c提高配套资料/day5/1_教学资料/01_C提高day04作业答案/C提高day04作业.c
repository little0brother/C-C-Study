1. ����ָ�����������ָ�������?


2. ��ζ���һ��ָ�� int a[10] ���͵�ָ�����������ָ�룩��ʹ��3�ַ�������


3. 
	int a[10];
	int b[5][10];
	int (*p)[10];
	p = &a;	//Ϊ�μ� &
	p = b;	//Ϊ�β��ü� & 
	
4. int a[3][5] = { 0 };
	//a -> a + 0		     
	//a + i				     
	//*(a+i) -> a[i]		 
	//*(a+i)+j -> &a[i][j]   
	//*(*(a+i)+j ) -> a[i][j]
	

5. �����ջ�Ͽ���һ����ά���飬����ڶ��Ͽ���һ����ά���飿


6. int main(int argc, char *argv[]);
	argc, argv�ֱ����ʲô��


7. �ҵ�������ָ���ַ�����λ��
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

/*
���ܣ��ҵ�������ָ���ַ�����λ��
������
	table���ַ������飨ָ�����飩�׵�ַ
	size������Ԫ�ظ���
	key��ƥ���ַ�������"do"
	pos: ƥ���ַ����������е�λ�ã����"do"��keywords[]��λ��Ϊ4
����ֵ��
	�ɹ���0
	ʧ�ܣ���0
*/
int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
�磺
int n = 0;
int ret = searcheKeyTable(keywords, NUM(keywords), "do", &n);

printf("%s��keywords[]��λ��Ϊ%d\n", "do", n);

				  
8. ���ַ��������������

int sort(char **array1, int num1,
         char (*array2)[30], int num2, 
         char ***myp3 /*out*/, int *num3);

int  main()
{
    int ret = 0; 
    char *p1[] = {"aa", "ccccccc", "bbbbbb"};
    char buf2[][30] = {"111111", "3333333", "222222"};
    char **p3 = NULL;   
    int len1, len2, len3, i = 0;
                            
    len1 = sizeof(p1)/sizeof(*p1);
    len2 = sizeof(buf2)/sizeof(buf2[0]);
    
	/*
	���ܣ�1����ָ������p1���ַ���ȡ������
		  2���Ѷ�ά����buf2���ַ�ȡ������
		  3��������ַ������� p3��p3 ���ڶ�������Ķ�ά�ڴ�
		  4���� p3 ���ַ�����������ͨ�� strcmp() ��������
	������
		p1�� ָ�������׵�ַ��char *p1[] = {"aa", "ccccccc", "bbbbbb"};
		len1��p1Ԫ�ظ���
		buf2����ά������Ԫ�ص�ַ��char buf2[][30] = {"111111", "3333333", "222222"};
		len2��buf2�ַ���������
		p3������ָ��ĵ�ַ����Ҫ�ں����ڷ����ά�ڴ棬����p1��buf2���ַ���������Ҫ����
		len3������p3�е��ַ�������
	����ֵ��
	*/
    ret = sort(p1, len1, buf2, len2, &p3, &len3);
	
	//�ͷ�p3��ָ���ڴ�
	//�ں����ڲ���p3��ֵ��ֵΪNULL
	free_buf(&p3);

    return 0;
}
