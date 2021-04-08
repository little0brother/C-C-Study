// 1. 简述指针数组和数组指针的区别?
答: 指针数组是一个数组，数组元素全都是指针
	数组指针是一个指针，指向一维数组的整个数组

// 2. 如何定义一个指向 int a[10] 类型的指针变量（数组指针）（使用3种方法）？
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
	p = &a;	//为何加 &			答：&a指的是a数组整个首地址，a指的是首元素地址，因为p为二级指针所以加&
	p = b;	//为何不用加 &		答：&b指的是整个二维数组首地址，b指的是首行地址，
	
// 4. int a[3][5] = { 0 };
	//a -> a + 0				: 首行首地址	     
	//a + i						: 第i行首地址
	//*(a+i) -> a[i]			: 第i行首元素地址
	//*(a+i)+j -> &a[i][j]		: 第i行第j列元素地址
	//*(*(a+i)+j ) -> a[i][j]	: 第i行第j列元素值
	

// 5. 如何在栈上开辟一个二维数组，如何在堆上开辟一个二维数组？
	malloc

// 6. int main(int argc, char *argv[]);
//  	argc, argv分别代表什么？
argc: 代表传入参数个数，包括可执行程序
argv: 指针数组，指向输入的参数


// 7. 找到数组中指定字符串的位置
#define NUM(a) (sizeof(a)/sizeof(*a))

char* keywords[] = {
	"while", 
	"case",
	"static",
	"do"
};

int searcheKeyTable(const char* table[], const int size, 
			  const char* key, int *pos);
				  
// 8. 将字符串数组进行排序

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
