一、基本概念
1、文件分类
	普通文件：存放在硬盘中的文件
	设备文件：屏幕、键盘等特殊文件
	
	文本文件：ASCII文件，每个字节存放一个字符的ASCII码，打开文件看到的是文本信息
	二进制文件：数据按其在内存中的存储形式原样存放，打开文件看到的是乱码
	
2、文件缓冲区（了解）
	ANSI C（标准C语言库函数）标准采用“缓冲文件系统”处理数据文件。
	
	写文件（设备文件除外），并不会直接写到文件中，会先放在缓冲区，默认情况下，关闭文件或缓冲区满了才写到文件。
	如果没有关闭文件，缓冲区也没有满，可以通过程序正常结束，或者人为刷新缓冲区fflush(fd)来把缓冲区的内容写到文件中。
	
	缓冲区了解一下即可，增加缓冲区只是为了提高效率，减少频繁交互的次数，我们写程序基本上不用关心。
	
	

二、读写文件步骤
1、打开文件
	//定义文件指针
	FILE *fp = NULL;
	fopen("c:\\demo.txt", "w+"); //"c:\\demo.txt" windows有效
	//"c:/demo.txt": 文件路径，可以是绝对路径和相对路径
	//"w+": 打开权限，读写方式打开，文件不存在则创建，写内容时，会清空原来内容再写
	//"r+"：读写方式打开，文件不存在则报错
	fp = fopen("./demo.txt", "w+"); // 45度 "c:/demo.txt" linux windows都可用
	if (fp == NULL)
	{
		perror("fopen"); //打印错误信息
		return;
	}
	
	默认情况下，VS, Qt相对路径说明：
	1）编译代码时，相对路径相对于工程目录
	2）直接点击可执行程序，相对路径相对于可执行程序
	
	c语言中有三个特殊的文件指针无需定义、打开可直接使用:
	stdin： 标准输入  默认为当前终端（键盘）
	我们使用的scanf、getchar函数默认从此终端获得数据

	stdout：标准输出  默认为当前终端（屏幕）
	我们使用的printf、puts函数默认输出信息到此终端

	stderr：标准出错  默认为当前终端（屏幕）
	当我们程序出错或者使用: perror函数时信息打印在此终端
	
	fputc('a', stdout); //stdout -> 屏幕, 打印普通信息

	char ch;
	ch = fgetc(stdin); //std -> 键盘
	printf("ch = %c\n", ch);

	//fprintf(stderr, "%c", ch ); //stderr -> 屏幕， 错误信息
	fputc(ch, stderr);
	
	
2、读写文件
	1、输出，即为写，把buf中的内容写到指定的文件中
	2、输入，即为读，把文件中的内容取出放在指定的buf

3、关闭文件
	fclose(fp);
	
二、读写文件
1、库函数的学习
	1）包含所需头文件
	2）函数名字
	3）功能
	4）参数
	5）返回值
	
2、按照字符读写文件：fgetc()、fputc()
	1）写文件
	char *str = "111abcdefg12345678";
	int i = 0;
	for (i = 0; i < (int)strlen(str); i++)
	{
		//功能：往文件fp中写str[i]，一个字符一个字符写
		//参数：str[i]：写入文件的字符，fp：文件指针
		//返回值：成功写入文件的字符，失败：-1
		fputc(str[i], fp);
	}
	
	2）读文件
	char ch;
	//feof(fp)判断文件是否到结尾，已经到结尾返回值为非0，没有到结尾返回值为0
	while ( !feof(fp) ) //如果文件没有结尾
	{
		//返回值：成功读取的字符
		ch = fgetc(fp);
		printf("%c", ch);
	}
	
3、按照行读写文件：fputs()、fgets()
	1）写文件
	char *buf[] = { "11111111\n", "aaaaaaaaaaaa\n", "bbbbbbbbbbbb\n" }; //指针数组
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		//功能：往文件fp写入一行内容buf[i]
		//参数：buf[i]：字符串首地址，fp：文件指针
		//返回值：成功：0，失败：非0
		fputs(buf[i], fp); 
	}
	
	2）读文件
	char buf[512] = {0};
	//从文件中读取一行内容（以"\n"作为标志），放在buf中
	//一次最大只能读sizeof(buf)-1，如果小于sizeof(buf)-1，则按实际大小读取
	//然后在字符串结尾自动加上字符‘\0’(转换为C风格字符串)
	//返回值：成功：读出的字符串，失败：NULL
	if (fgets(buf, sizeof(buf), fp) != NULL) 
	{
		printf("buf = %s", buf);
	}
	
4、按照块读写文件：fread()、fwirte()
	typedef struct Stu
	{
		char name[50];
		int id;
	}Stu;
	Stu s[3];
	
	1）写文件
	//写文件，按块的方式写
	//s：写入文件内容的内存首地址
	//sizeof(Stu)：块数据的大小
	//3：块数， 写文件数据的大小 sizeof(Stu) *3
	//fp：文件指针
	//返回值，成功写入文件的块数目，不是数据总长度
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("ret = %d\n", ret);
	
	
	2）读文件
	//读文件，按块的方式读
	//s：放文件内容的首地址
	//sizeof(Stu)：块数据的大小
	//3：块数， 读文件数据的大小 sizeof(Stu) *3
	//fp：文件指针
	//返回值，成功读取文件内容的块数目，不是数据总长度
	int ret = fread(s, sizeof(Stu), 3, fp);
	printf("ret = %d\n", ret);
	
5、按照格式化进行读写文件：fprintf()、fscanf()	
	1）写文件
	//格式化写文件
	int a = 250;
	int b = 10;
	int c = 20;
	//和printf()用法一样，只是printf是往屏幕（标准输出）写内容
	//fprintf往指定的文件指针写内容
	//返回值：成功：写入文件内容的长度，失败：负数
	fprintf(fp, "Tom = %d, just like %d, it is %d", a, b, c);
	
	2）读文件
	int a, b, c;
	fscanf(fp, "Tom = %d, just like %d, it is %d", &a, &b, &c);
	printf("a = %d, b = %d, c = %d\n", a, b, c);
	
6、随机读写
	//文件光标移动到文件结尾
	//SEEK_SET：文件开头
	//SEEK_CUR：文件当前位置
	//SEEK_END：文件结尾
	fseek(fp, 0, SEEK_END);


	//获取光标到文件开头文件的大小ftell
	long size = ftell(fp);
	
	//文件光标恢复到开始位置
	rewind(fp);
	
	
	typedef struct Stu
	{
		char name[50];
		int id;
	}Stu;
	Stu tmp; //读第3个结构体

	//假如文件中写了三个结构体
	//从起点位置开始，往后跳转2个结构体的位置
	fseek(fp, 2*sizeof(Stu), SEEK_SET);
	//从结尾位置开始，往前跳转一个结构体的位置
	//fseek(fp, -1 * (int)sizeof(Stu), SEEK_END);
	int ret = 0;
	ret = fread(&tmp,sizeof(Stu), 1,  fp);
	if(ret == 1)
	{
		printf("[tmp]%s, %d\n", tmp.name, tmp.id);
	}
	
	//把文件光标移动到文件开头
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);
	
	
三、综合案例
1、加密文件读写（使用别人写好的接口）
2、配置文件读写（自定义接口）

	