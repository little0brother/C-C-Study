//------------自动售货机--------------------
//		陕西科技大学电气与信息工程学院
//author 张栋瑜 周乐伟 温家正 		电气176 
//		制作时间 2018/6/20
//		联系方式 530281461@qq.com 
//----------------------------------------- 

//初次使用请进行系统维护并录入商品信息 

#include <stdio.h>
#define SIZE 100000
#include<string.h>
#include<stdlib.h>
#include<conio.h>

//货物数据结构 
struct huowu
{
	int n;				//编号 
	char name[10];		//名称 
	int Price;			//价格 
	int Maths;			//剩余数量 
}s[SIZE];


/*录入数据*/
void finput()
{
	FILE *fp;
	int i, p, t, x = 1;
	fp = fopen("fs+", "wb");
	printf("已进入重新录入数据界面，之前数据将被清除！\n\n请按提示输入编号\n");
	for (i = 0; i<SIZE; i + 1)
	{
		printf(" 第%d个  请输入编号(请与左方编号一致，按回车键进入下一步，当输入i=-1时,完成录入商品信息)\n", x++);//需要逐一手动先输入编号 
		scanf("%d", &t);
		i = t;
		if (i == -1)
		{
			fclose(fp);
			return;
		}
		else
		{
			i = t - 1;
			printf("请输入 名称 价格 及添加的 库存 ，用空格间隔开，按回车键继续\n");
			scanf("%s %d %d", &s[i].name, &s[i].Price, &s[i].Maths);

			s[i].n = i + 1;
			fwrite(&s[i], sizeof(struct huowu), 1, fp);
		}
	}
	fclose(fp);
}
/*输出数据*/
void flist()
{
	FILE *fp;
	int i;
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                         列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号          名称             价格		库存 \n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; fread(&s[i], sizeof(struct huowu), 1, fp) == 1; i++)
	{
		printf("%d%18s%16d%16d\n", s[i].n, s[i].name, s[i].Price, s[i].Maths);
	}
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	fclose(fp);

}

/*修改数据*/
void fchange()
{
	FILE *fp;
	int k;
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                         列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号          名称             价格		库存 \n");
	printf("-----------------------------------------------------------\n");
	for (k = 0; fread(&s[k], sizeof(struct huowu), 1, fp) == 1; k++)
	{
		printf("%d%18s%16d%16d\n", s[k].n, s[k].name, s[k].Price, s[k].Maths);
	}
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	int i, num, n;
	int flag = 0;
	printf("请输入要修改商品的序号:");
	scanf("%d", &n);
	for (i = 0; i <= SIZE; i++)
		if (s[i].n == n)
		{
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			printf("                         列表\n");
			printf("-----------------------------------------------------------\n");
			printf("序号   	                  名称                          价格\n");
			printf("-----------------------------------------------------------\n");
			printf("%d%32s%25d\n", s[i].n, s[i].name, s[i].Price);
			printf("-----------------------------------------------------------\n\n");
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			n = i;
			flag = 1;
			break;
		}
	if (flag == 0)
	{
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		printf("                        输入错误!\n");
		printf("                        请重新选择!\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		return;
	}
	printf("\n\n\n");
	fp = fopen("fs+", "rb+");
	fseek(fp, n * sizeof(struct huowu), 0);
	printf("请输入新的 名称  价格:");
	scanf("%s%d", s[i].name, &s[i].Price);
	fwrite(&s[i], sizeof(struct huowu), 1, fp);
	fclose(fp);
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                       成绩列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号   	                  名称                          价格\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; fread(&s[i], sizeof(struct huowu), 1, fp) == 1; i++)
	{
		printf("%d%28s%28d\n", s[i].n, s[i].name, s[i].Price);
	}
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	fclose(fp);

}
/*  排序*/
void ftaxis()
{
	int i, j, n;
	FILE *fp;
	struct huowu t;
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                         列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号   	                  名称                          价格\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; fread(&s[i], sizeof(struct huowu), 1, fp) == 1; i++)
	{
		printf("%d%28s%28d\n", s[i].n, s[i].name, s[i].Price);
	}
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	fclose(fp);
	n = i;
	for (i = 0; i<n; i++)
		for (j = i + 1; j<n; j++)
			if (s[i].Price<s[j].Price)
			{
				t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
	fp = fopen("fss+", "w");
	printf("\n\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                         列表 \n");
	printf("-----------------------------------------------------------\n");
	printf("序号   	                  名称                          价格\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i<n; i++)
	{
		fwrite(&s[i], sizeof(struct huowu), 1, fp);
		printf("%d%28s%28d\n", s[i].n, s[i].name, s[i].Price);
	}
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	fclose(fp);

}
/*内部操作systeam*/
int neibu()
{
	system("cls");
	int n;
	for (;;)
	{
		printf("\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		printf("※                                                          ※\n");
		printf("※                 欢迎进入自动售货机(内部)                 ※\n");
		printf("※                                                          ※\n");
		printf("※                                                          ※\n");
		printf("※                          主菜单                          ※\n");
		printf("※                                                          ※\n");
		printf("※                      ▲1.重新所有录入数据▲              ※\n");
		printf("※                      ▲2.展示商品信息▲                  ※\n");
		printf("※                      ▲3.补充库存▲                      ※\n");
		printf("※                      ▲4.修改数据▲                      ※\n");
		printf("※                      ▲5.按照价格排序并生成另一个文件▲  ※\n");
		printf("※                      ▲6.退出系统▲                      ※\n");
		printf("※                                                          ※\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n\n");
		printf("请输入选择项(1-6):");
		scanf("%d", &n);
		printf("\n\n\n\n");
		if (n>0 && n<8)
		{
			switch (n)
			{
			case 1:finput(); break;
			case 2:flist(); break;
			case 3:fadd(); break;
			case 4:fchange(); break;
			case 5:ftaxis(); break;
			case 6:printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");
				printf("※                                            ※\n");
				printf("※                  谢谢使用!                 ※\n");
				printf("※                    再见!                   ※\n");
				printf("※                                            ※\n");
				printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");
				exit(0);
			}
		}
		else
		{
			printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");
			printf("※                                            ※\n");
			printf("※                  输入错误!                 ※\n");
			printf("※                   请退出!                  ※\n");
			printf("※                                            ※\n");
			printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");
			break;
		}
	}
	system("cls"); //清空屏幕  
}

//添加库存 
int fadd()
{
	FILE *fp;
	int i, num, n;
	int flag = 0;
	printf("请输入要补货 商品 的序号:");
	scanf("%d", &n);
	for (i = 0; i <= SIZE; i++)
		if (s[i].n == n)
		{
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			printf("                         列表\n");
			printf("-----------------------------------------------------------\n");
			printf("序号   	                  名称         				库存\n");
			printf("-----------------------------------------------------------\n");
			printf("%d%8s%8d\n", s[i].n, s[i].name, s[i].Maths);
			printf("-----------------------------------------------------------\n\n");
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			n = i;
			flag = 1;
			break;
		}
	if (flag == 0)
	{
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		printf("                        输入错误!\n");
		printf("                         请返回!\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		return;
	}
	printf("\n\n\n");
	fp = fopen("fs+", "rb+");
	fseek(fp, n * sizeof(struct huowu), 0);
	printf("请输入添加后此商品总个数");
	scanf("%d", &s[i].Maths);
	fwrite(&s[i], sizeof(struct huowu), 1, fp);
	fclose(fp);
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                       列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号   	                  名称                          库存\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; fread(&s[i], sizeof(struct huowu), 1, fp) == 1; i++)
	{
		printf("%d%8s%8d\n", s[i].n, s[i].name, s[i].Maths);
	}
	printf("------------------------补货完成-------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	fclose(fp);

}

/*购买*/
void buy()
{
	FILE *fp;
	int i;
	system("cls");
	fp = fopen("fs+", "rb");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("                       列表\n");
	printf("-----------------------------------------------------------\n");
	printf("序号          名称             价格		库存 \n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; fread(&s[i], sizeof(struct huowu), 1, fp) == 1; i++)
	{
		printf("%d%18s%16d%18d\n", s[i].n, s[i].name, s[i].Price, s[i].Maths);
	}
	printf("----------------请输入需要的商品按回车继续-----------------\n");
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	int num, n, B = 1;
	float money = 0.0, m = 0;
	int flag = 0;
restar:
	printf("请输入要购买商品的序号:");
	scanf("%d", &n);
	for (i = 0; i <= SIZE; i++)
		if (s[i].n == n)
		{
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			printf("-----------------------------------------------------------\n");
			printf("序号   	                  名称                          价格\n");
			printf("-----------------------------------------------------------\n");
			printf("%d%30s%26d元\n", s[i].n, s[i].name, s[i].Price);
			printf("-----------------------------------------------------------\n\n");
			printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
			n = i;
			flag = 1;
			break;
		}
	if (flag == 0)
	{
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		printf("                        输入错误!\n");
		printf("                         请返回!\n");
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
		return;
	}
	printf("\n\n\n");
	fp = fopen("fs+", "rb+");
	fseek(fp, n * sizeof(struct huowu), 0);
	s[i].Maths = s[i].Maths - 1;
	fwrite(&s[i], sizeof(struct huowu), 1, fp);
	fclose(fp);
	fp = fopen("fs+", "rb");
	if (s[i].Maths <= 0)
	{
		printf("存货不足，请购买其他商品！\n");
		s[i].Maths = 0;
		goto restar;

	}
	else
		printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("-----------------------------------------------------------\n");
	printf("			请	支	付	%d	元（仅限一元以上面额）\n", s[i].Price);
	printf("-----------------------------------------------------------\n\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n");
	while (B)
	{
		scanf("%f", &money);
		m += money;
		if (m<s[i].Price)
		{
			printf("金额不足，请继续支付\n\n");
		}
		if (m == s[i].Price)
		{
			printf("付款成功\n\n");
			B = 0;
			break;
			s[i].Maths = s[i].Maths - 1;

		}
		if (m>s[i].Price)
		{
			money = m - s[i].Price;
			printf("		付款成功,找零%f请您收好\n\n\n\n     				欢迎下次使用\n\n\n", money);
			B = 0;
			break;
			s[i].Maths = s[i].Maths - 1;
		}
	}
	fclose(fp);
	system("pause");
}
//主函数 
int main()
{
	char sr;//定义电脑接受的字符  
	system("color F0");

start://起始位置  
	system("cls");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");
	printf("※         欢迎使用自动售货机（初始试用版）   ※\n");
	printf("※                                            ※\n");
	printf("※          	 请输入选项                   ※\n");
	printf("※               a.用户购买                   ※\n");
	printf("※               b.系统维护                   ※\n");
	printf("※                                            ※\n");
	printf("※               按回车继续 。。。            ※\n");
	printf("※※※※※※※※※※※※※※※※※※※※※※※※\n");


	scanf("\n%c", &sr);

	switch (sr)
	{
	case 'a': buy(); break;

	case 'b': neibu(); break;

	}
	goto start;//回到起始位置  
}