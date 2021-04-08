#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>//主要是一些用户通过按键盘产生的对应操作，比如getch()函数 
#include<time.h> //时间库 
#include<mmsystem.h>//windows中与多媒体有关的大多数接口
#pragma comment(lib,"winmm.lib")//预处理，支持对windows 多媒体的编程.
//#include<graphics.h>//图形库
 
#define N 15 //航班最多15，N为全局变量
 
typedef struct traininfor 
{
	char qishi[30]; //起始站 
	char zhongdian[30]; //终点站  
	char trainnumber[10]; //航班号 
	int piaonumber; //每次航班的生成票数
	int sellnumber;//已售航班票数
	char time[30]; //飞机出发时间  
}hang;
 
int d=0;//统计有多少次航班
struct ticket *yonghu;//用户购票信息头结点
hang plane[N]; //航班信息结构体数组 
int menu();//打印主菜单函数 
int DengLu();//登录票务系统函数 
void JianFile();//建立文件航班信息函数
void OpenFile();//读取文件信息函数 
void check(); //查看从郑州到某终点站飞机票信息函数 
void exit(); // 退出程序  
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	DengLu();//	登录票务系统函数
	JianFile();//建立文件航班信息 
	//OpenFile();//打开文件读取航班信息 
	
	while(1)
	{//每次操作完自动返回主菜单作用
		switch(menu())
		{//menu()函数为输入选项
			case 1://选项为1时 
					OpenFile();//打开文件读取航班信息
					printf("已成功导入航班信息\n\n\n"); 
					break; 
					
			case 2: //选项为2时 
					check();// 查看从郑州到某终点站飞机票信息函数 
					break;
					
			case 3://选项为3时 
					system("cls");//清屏 
					printf("感谢您的使用，祝您的旅途愉快\n");
					Sleep(5000);//延迟15秒 
					exit(1);//
					break;
			
		} 
	}
	return  0;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//登录票务系统
int DengLu() 
{
	//getch()=从键盘输入一个字符且不显示  getche()=从键盘输入一个字符并显示 
	printf("欢迎来到票务系统：\n");
	int i;
	do{
		i=1;
		i--;
	}while(i);
	   
		printf("\n即将进入票务系统主页");
			PlaySound("20100814_5c610cfa0dec6116aa701YT6vHJzW9Zw.wav", NULL, SND_FILENAME | SND_SYNC); //音乐播放
			printf("\n");
			//Sleep(3000);//延时3秒 
		return 0;
} 
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void JianFile()
{
	FILE *fp;//定义文件指针
	if((fp=fopen("txt.in","w"))==NULL)
	{//创建文件失败
		printf("建立失败！\n");
		exit(0);
	}
	//向文件中输入航班信息
	fprintf(fp,"郑州 南阳 T1230 200 123 2019年6月6日12点15分\n");
	fprintf(fp,"郑州 信阳 T1231 200 200 2019年6月6日13点15分\n");
	fprintf(fp,"郑州 商丘 T1232 200 66 2019年6月6日14点15分\n");
	fprintf(fp,"郑州 开封 T1234 200 196 2019年6月6日15点15分\n");
	fprintf(fp,"郑州 洛阳 T1235 200 177 2019年6月6日16点15分\n");
	fprintf(fp,"郑州 三门峡 T1236 200 155 2019年6月6日17点15分\n");
	fprintf(fp,"郑州 鹤壁 T1237  200 99 2019年6月6日18点15分\n");
	fprintf(fp,"郑州 周口 T1238 200 182 2019年6月6日19点15分\n");
	fprintf(fp,"郑州 驻马店 T1239 200 111 2019年6月6日20点15分");
	fclose(fp);
	return ;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//文件读取航班信息
void OpenFile()
{ 
	FILE *fp; //定义文件指针 
	d=0;//表示读取到当前文件位置
	if((fp=fopen("txt.in","r"))==NULL)
	{//打开文件
		printf("文件打开失败！\n");
		return ;
	}
 
	while(!feof(fp))
	{//读取到文件为空 
		//printf("请设定第%d个站的地点、车次、航班号、到站时间、预售票数、已被购买票数：\n",d);
		fscanf(fp,"%s%s%s%d%d%s",plane[d].qishi,plane[d].zhongdian,plane[d].trainnumber,&plane[d].piaonumber,&plane[d].sellnumber,plane[d].time);
		d++;
	} 
	fclose(fp);//关闭文件 
	return ;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
	char s[10];//输入字符串选项
	int n;//整型选项
	//菜单框架
	printf("--------------------票务系统目录--------------------\n\n");
	printf("1, 导入航班信息\n");
	printf("2, 查询飞机票\n");
	printf("3, 退出程序\n");
	printf("注意：飞机从本站能到达的地方有南阳、信阳、商丘\n");
	printf("开封、洛阳、三门峡、鹤壁、周口、驻马店\n");
	printf("如果您想了解更多信息请输入选项序号\n \n");
	printf("本程序制作者：2018级应用物理一班 张妍,高婷\n");
	printf("请输入选项：");
 
	while(1)
	{//死循环状态
		fflush(stdin);//清空输入流
		//gets(s);//得到一串字符串
		n=atoi(s);//字符串转化为整数 
		if(n<1||n>3)//判断输入的选项是否正确
		printf("输入错误，请重新输入：\n");
		else//符合条件，结束循环
		break; 
	}
	//返回选项值
	return n;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 查看从郑州到某终点站飞机票信息函数
void check()
{
	int i, j;//循环变量
	int find = 1, flag = 0, count = 0;//标志变量
	char qi[30];//起始站 
	char mudi[30];//终点站 
	printf("请输入起始地(提示：起始地为郑州)： \n");
	scanf("%s", qi);//输入起始地
	printf("请输入目的地： \n");
	scanf("%s", mudi);//输入目的地

	while (1)
	{//死循环状态
		if (0 == strcmp(qi, "郑州"))
		{//起始地为郑州时
			flag = 1;//标志变量为1，表示起始地没有出错
			for (j = 0; j < d; j++)
			{//循环d次航班信息
				if (0 == strcmp(plane[j].zhongdian, mudi))
				{//输入的终点站与航班信息终点站一致
					count = 1;//标志变量为1
					printf("航班号： ");//输出航班号
					printf("%s\n", plane[j].trainnumber);
					printf("起始地:  ");//输出起始地
					printf("%s\n", plane[j].qishi);
					printf("目的地： ");//输出目的地
					printf("%s\n", plane[j].zhongdian);
					printf("此次航班已售票数： ");//输出已售票数
					printf("%d\n", plane[j].sellnumber);
					printf("此次航班时间：");//输出航班时间
					printf("%s\n", plane[j].time);
					printf("此次航班飞机票数量：  ");//输出票数
					printf("%d\n\n\n\n", plane[j].piaonumber);
					return;
				}
			}
		}
		else
		{
			flag = 1;//起始地输入错误
			printf("输入有误，返回菜单!\n\n\n");
			return;
		}

		if (0 == count && flag == 1)
		{//起始地并且目的地输入错误
			printf("sorry 您查询的结果无信息!\n\n\n");
			return;
		}
		if (i > 1 && i % 10 == 0)  system("every key");//每十个一屏显示}
		return;
	}

}