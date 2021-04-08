#include "sale.h"

int main()
{
	int a = 0;
	system("CLS");

	printf("\n选择需要的项目：\n\t1.商品购买\n\t2.显示库存\n\t3.设备维护\n\t4.退出\n");
	printf("\n输入对应数字:");
	scanf("%d", &a);

	switch (a)
	{
		case 1: Commodity_Purchase(); break;
		case 2: Display_Inventory(); break;
		case 3: Equipment_Maintenance(); break;
		case 4 : exit(0);
	}

	system("pause");
	return 0;
}

void Commodity_Purchase()
{
	int a;
	float b;
	writefp();
	system("CLS");

	readfp();
	printf("\n选择需要购买的商品。(输入购买商品的序号):");
	scanf("%d", &a);

	if (shangpin[a - 1].amount >= 0)
	{
		system("CLS");
		printf("\n%s--%f元\n\n请付%f元:", shangpin[a - 1].name, shangpin[a - 1].price, shangpin[a - 1].price);
		scanf("%f", &b);

		if (b > shangpin[a - 1].price) {
			printf("找您%f元\n", b - shangpin[a - 1].price);
			shangpin[a - 1].amount -= 1;

			return_();
		}
		if (b == shangpin[a - 1].price) {
			printf("付款完成\n");
			shangpin[a - 1].amount -= 1;

			return_();
		}
		if (b < shangpin[a - 1].price) {
			printf("金额不足，差%f元，请重新付款\n", shangpin[a - 1].price - b);
			return_();
		}
	}
	else
		printf("商品不足");

	writefp();
}

void Display_Inventory()
{
	int n = 0, m = 0;

	system("CLS");
	readfp();

	printf("\n装填所有请输入“1”,返回上一层输入“2”:");
	scanf("%d", &n);

	switch (n) {
	case 1: {
		for (int i = 0; i < M; i++) 
			shangpin[i].amount = 15;
			
		system("CLS");
		printf("\n     /*******装填成功！*******/\n");
		writefp();
		readfp();

		printf("\n\n返回主菜单请输入“1”,退出请输入“2”：");
		scanf("%d", &m);

		switch (m) {
		case 1: main(); break;
		case 2: exit(0);
		}

		break; 
	}
	case 2: main(); break;
	}
}

void Equipment_Maintenance()
{
	int a = 0;

	system("CLS");
	printf("\n\t1.加入新商品\n\t2.删除商品\n\t3.修改商品价格\n\t4.返回上一层\n\t5.退出");
	printf("\n\t输入对应数字：");
	scanf("%d", &a);

	switch (a)
	{
	case 1:Add_Goods(); break;/*功能未实现，问题出现在add函数，由readfp函数打印时少打印了一个数值，缺少一个可以作用再全局的并且可修改的变量*/
	case 2:printf("还是啥都没！！\n"); break;
	case 3:printf("这个还是啥都没！！\n"); break;
	case 4:main();
	case 5:exit(0);
	}
}

void return_()
{
	system("CLS");

	int c = 0;

	printf("\n返回上一层请输入1,退出请输入0：");
	scanf("%d", &c);
	if (c == 1)
		main();
	else
		exit(0);
}

void writefp()
{

	for (int i = 0; i < M; i++)
		goods[i] = shangpin[i];

	fp = fopen("massag.txt", "w+");
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	fwrite(&goods, sizeof(goods), 1, fp);

	fclose(fp);
}

void readfp()
{
	massage sb[M];

	fp = fopen("massag.txt", "r");
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	fread(&sb, sizeof(sb), 1, fp);

	printf("\n    名称         单价    库存\n");

	for (int i = 0; i < M; i++)
		printf("%3d.%-10s--%f--%d\n", i + 1, sb[i].name, sb[i].price, sb[i].amount);
}

/*添加的商品，退出后会消失（无法解决）*/
void Add_Goods()
{
	system("CLS");

	int a;

	printf("输入添加商品名称（名称 单价）:");
	scanf("%s %f", &goods[M + 1].name, &goods[M + 1].price); goods[M + 1].amount = 15;

	fp = fopen("massag.txt", "a+");
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	fwrite(&goods, sizeof(goods), 1, fp);

	fclose(fp);

	printf("\n添加成功！！");
	printf("\n返回上一层请输入“1”，退出请输入“0”：");
	scanf("%d", &a);
	switch (a)
	{
	case 0:exit(0); break;
	case 1:Equipment_Maintenance(); break;
	}
}

/*
void writefp()
{
	fp = fopen("massage.txt", "wb");

	if (fp == NULL) {
		printf("error!");
		return 0;
	}
	for (int i = 0; i < M; i++)
	fwrite(&shangpin[i], sizeof(shangpin), 1, fp);

	fclose(fp);
}
*/

/*
void readfp()
{
	massage mas[M + 1];

	fp = fopen("massage.txt", "rb");

	if (fp == NULL) {
		printf("error!");
		return 0;
	}
	for (int i = 0; i < M; i++)
		fread(&mas[i], sizeof(mas), 1, fp);

	for (int j = 0; j < M; j++)
		printf("%15s--%f--%d\n", mas[j].name, mas[j].price, mas[j].amount);

	fclose(fp);
}
*/