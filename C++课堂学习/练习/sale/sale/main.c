#include "sale.h"

int main()
{
	int a = 0;
	system("CLS");

	printf("\nѡ����Ҫ����Ŀ��\n\t1.��Ʒ����\n\t2.��ʾ���\n\t3.�豸ά��\n\t4.�˳�\n");
	printf("\n�����Ӧ����:");
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
	printf("\nѡ����Ҫ�������Ʒ��(���빺����Ʒ�����):");
	scanf("%d", &a);

	if (shangpin[a - 1].amount >= 0)
	{
		system("CLS");
		printf("\n%s--%fԪ\n\n�븶%fԪ:", shangpin[a - 1].name, shangpin[a - 1].price, shangpin[a - 1].price);
		scanf("%f", &b);

		if (b > shangpin[a - 1].price) {
			printf("����%fԪ\n", b - shangpin[a - 1].price);
			shangpin[a - 1].amount -= 1;

			return_();
		}
		if (b == shangpin[a - 1].price) {
			printf("�������\n");
			shangpin[a - 1].amount -= 1;

			return_();
		}
		if (b < shangpin[a - 1].price) {
			printf("���㣬��%fԪ�������¸���\n", shangpin[a - 1].price - b);
			return_();
		}
	}
	else
		printf("��Ʒ����");

	writefp();
}

void Display_Inventory()
{
	int n = 0, m = 0;

	system("CLS");
	readfp();

	printf("\nװ�����������롰1��,������һ�����롰2��:");
	scanf("%d", &n);

	switch (n) {
	case 1: {
		for (int i = 0; i < M; i++) 
			shangpin[i].amount = 15;
			
		system("CLS");
		printf("\n     /*******װ��ɹ���*******/\n");
		writefp();
		readfp();

		printf("\n\n�������˵������롰1��,�˳������롰2����");
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
	printf("\n\t1.��������Ʒ\n\t2.ɾ����Ʒ\n\t3.�޸���Ʒ�۸�\n\t4.������һ��\n\t5.�˳�");
	printf("\n\t�����Ӧ���֣�");
	scanf("%d", &a);

	switch (a)
	{
	case 1:Add_Goods(); break;/*����δʵ�֣����������add��������readfp������ӡʱ�ٴ�ӡ��һ����ֵ��ȱ��һ������������ȫ�ֵĲ��ҿ��޸ĵı���*/
	case 2:printf("����ɶ��û����\n"); break;
	case 3:printf("�������ɶ��û����\n"); break;
	case 4:main();
	case 5:exit(0);
	}
}

void return_()
{
	system("CLS");

	int c = 0;

	printf("\n������һ��������1,�˳�������0��");
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

	printf("\n    ����         ����    ���\n");

	for (int i = 0; i < M; i++)
		printf("%3d.%-10s--%f--%d\n", i + 1, sb[i].name, sb[i].price, sb[i].amount);
}

/*��ӵ���Ʒ���˳������ʧ���޷������*/
void Add_Goods()
{
	system("CLS");

	int a;

	printf("���������Ʒ���ƣ����� ���ۣ�:");
	scanf("%s %f", &goods[M + 1].name, &goods[M + 1].price); goods[M + 1].amount = 15;

	fp = fopen("massag.txt", "a+");
	if (!fp)
	{
		printf("errror!\n");
		exit(-1);
	}
	fwrite(&goods, sizeof(goods), 1, fp);

	fclose(fp);

	printf("\n��ӳɹ�����");
	printf("\n������һ�������롰1�����˳������롰0����");
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