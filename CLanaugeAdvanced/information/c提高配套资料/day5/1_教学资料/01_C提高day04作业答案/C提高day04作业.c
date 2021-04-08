1. 简述指针数组和数组指针的区别?


2. 如何定义一个指向 int a[10] 类型的指针变量（数组指针）（使用3种方法）？


3. 
	int a[10];
	int b[5][10];
	int (*p)[10];
	p = &a;	//为何加 &
	p = b;	//为何不用加 & 
	
4. int a[3][5] = { 0 };
	//a -> a + 0		     
	//a + i				     
	//*(a+i) -> a[i]		 
	//*(a+i)+j -> &a[i][j]   
	//*(*(a+i)+j ) -> a[i][j]
	

5. 如何在栈上开辟一个二维数组，如何在堆上开辟一个二维数组？


6. int main(int argc, char *argv[]);
	argc, argv分别代表什么？


7. 找到数组中指定字符串的位置
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

/*
功能：找到数组中指定字符串的位置
参数：
	table：字符串数组（指针数组）首地址
	size：数组元素个数
	key：匹配字符串，如"do"
	pos: 匹配字符串在数组中的位置，如果"do"在keywords[]中位置为4
返回值：
	成功：0
	失败：非0
*/
int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
如：
int n = 0;
int ret = searcheKeyTable(keywords, NUM(keywords), "do", &n);

printf("%s在keywords[]中位置为%d\n", "do", n);

				  
8. 将字符串数组进行排序

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
	功能：1、把指针数组p1的字符串取出来，
		  2、把二维数组buf2的字符取出来，
		  3、上面的字符串放在 p3，p3 是在堆区分配的二维内存
		  4、对 p3 中字符串进行排序，通过 strcmp() 进行排序
	参数：
		p1： 指针数组首地址，char *p1[] = {"aa", "ccccccc", "bbbbbb"};
		len1：p1元素个数
		buf2：二维数组首元素地址，char buf2[][30] = {"111111", "3333333", "222222"};
		len2：buf2字符串的行数
		p3：二级指针的地址，需要在函数内分配二维内存，保存p1和buf2的字符串，还需要排序
		len3：保存p3中的字符串个数
	返回值：
	*/
    ret = sort(p1, len1, buf2, len2, &p3, &len3);
	
	//释放p3所指向内存
	//在函数内部把p3的值赋值为NULL
	free_buf(&p3);

    return 0;
}
