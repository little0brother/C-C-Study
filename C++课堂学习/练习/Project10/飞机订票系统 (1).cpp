#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>//��Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����������getch()���� 
#include<time.h> //ʱ��� 
#include<mmsystem.h>//windows�����ý���йصĴ�����ӿ�
#pragma comment(lib,"winmm.lib")//Ԥ����֧�ֶ�windows ��ý��ı��.
//#include<graphics.h>//ͼ�ο�
 
#define N 15 //�������15��NΪȫ�ֱ���
 
typedef struct traininfor 
{
	char qishi[30]; //��ʼվ 
	char zhongdian[30]; //�յ�վ  
	char trainnumber[10]; //����� 
	int piaonumber; //ÿ�κ��������Ʊ��
	int sellnumber;//���ۺ���Ʊ��
	char time[30]; //�ɻ�����ʱ��  
}hang;
 
int d=0;//ͳ���ж��ٴκ���
struct ticket *yonghu;//�û���Ʊ��Ϣͷ���
hang plane[N]; //������Ϣ�ṹ������ 
int menu();//��ӡ���˵����� 
int DengLu();//��¼Ʊ��ϵͳ���� 
void JianFile();//�����ļ�������Ϣ����
void OpenFile();//��ȡ�ļ���Ϣ���� 
void check(); //�鿴��֣�ݵ�ĳ�յ�վ�ɻ�Ʊ��Ϣ���� 
void exit(); // �˳�����  
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	DengLu();//	��¼Ʊ��ϵͳ����
	JianFile();//�����ļ�������Ϣ 
	//OpenFile();//���ļ���ȡ������Ϣ 
	
	while(1)
	{//ÿ�β������Զ��������˵�����
		switch(menu())
		{//menu()����Ϊ����ѡ��
			case 1://ѡ��Ϊ1ʱ 
					OpenFile();//���ļ���ȡ������Ϣ
					printf("�ѳɹ����뺽����Ϣ\n\n\n"); 
					break; 
					
			case 2: //ѡ��Ϊ2ʱ 
					check();// �鿴��֣�ݵ�ĳ�յ�վ�ɻ�Ʊ��Ϣ���� 
					break;
					
			case 3://ѡ��Ϊ3ʱ 
					system("cls");//���� 
					printf("��л����ʹ�ã�ף������;���\n");
					Sleep(5000);//�ӳ�15�� 
					exit(1);//
					break;
			
		} 
	}
	return  0;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//��¼Ʊ��ϵͳ
int DengLu() 
{
	//getch()=�Ӽ�������һ���ַ��Ҳ���ʾ  getche()=�Ӽ�������һ���ַ�����ʾ 
	printf("��ӭ����Ʊ��ϵͳ��\n");
	int i;
	do{
		i=1;
		i--;
	}while(i);
	   
		printf("\n��������Ʊ��ϵͳ��ҳ");
			PlaySound("20100814_5c610cfa0dec6116aa701YT6vHJzW9Zw.wav", NULL, SND_FILENAME | SND_SYNC); //���ֲ���
			printf("\n");
			//Sleep(3000);//��ʱ3�� 
		return 0;
} 
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void JianFile()
{
	FILE *fp;//�����ļ�ָ��
	if((fp=fopen("txt.in","w"))==NULL)
	{//�����ļ�ʧ��
		printf("����ʧ�ܣ�\n");
		exit(0);
	}
	//���ļ������뺽����Ϣ
	fprintf(fp,"֣�� ���� T1230 200 123 2019��6��6��12��15��\n");
	fprintf(fp,"֣�� ���� T1231 200 200 2019��6��6��13��15��\n");
	fprintf(fp,"֣�� ���� T1232 200 66 2019��6��6��14��15��\n");
	fprintf(fp,"֣�� ���� T1234 200 196 2019��6��6��15��15��\n");
	fprintf(fp,"֣�� ���� T1235 200 177 2019��6��6��16��15��\n");
	fprintf(fp,"֣�� ����Ͽ T1236 200 155 2019��6��6��17��15��\n");
	fprintf(fp,"֣�� �ױ� T1237  200 99 2019��6��6��18��15��\n");
	fprintf(fp,"֣�� �ܿ� T1238 200 182 2019��6��6��19��15��\n");
	fprintf(fp,"֣�� פ��� T1239 200 111 2019��6��6��20��15��");
	fclose(fp);
	return ;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ļ���ȡ������Ϣ
void OpenFile()
{ 
	FILE *fp; //�����ļ�ָ�� 
	d=0;//��ʾ��ȡ����ǰ�ļ�λ��
	if((fp=fopen("txt.in","r"))==NULL)
	{//���ļ�
		printf("�ļ���ʧ�ܣ�\n");
		return ;
	}
 
	while(!feof(fp))
	{//��ȡ���ļ�Ϊ�� 
		//printf("���趨��%d��վ�ĵص㡢���Ρ�����š���վʱ�䡢Ԥ��Ʊ�����ѱ�����Ʊ����\n",d);
		fscanf(fp,"%s%s%s%d%d%s",plane[d].qishi,plane[d].zhongdian,plane[d].trainnumber,&plane[d].piaonumber,&plane[d].sellnumber,plane[d].time);
		d++;
	} 
	fclose(fp);//�ر��ļ� 
	return ;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
	char s[10];//�����ַ���ѡ��
	int n;//����ѡ��
	//�˵����
	printf("--------------------Ʊ��ϵͳĿ¼--------------------\n\n");
	printf("1, ���뺽����Ϣ\n");
	printf("2, ��ѯ�ɻ�Ʊ\n");
	printf("3, �˳�����\n");
	printf("ע�⣺�ɻ��ӱ�վ�ܵ���ĵط�������������������\n");
	printf("���⡢����������Ͽ���ױڡ��ܿڡ�פ���\n");
	printf("��������˽������Ϣ������ѡ�����\n \n");
	printf("�����������ߣ�2018��Ӧ������һ�� ����,����\n");
	printf("������ѡ�");
 
	while(1)
	{//��ѭ��״̬
		fflush(stdin);//���������
		//gets(s);//�õ�һ���ַ���
		n=atoi(s);//�ַ���ת��Ϊ���� 
		if(n<1||n>3)//�ж������ѡ���Ƿ���ȷ
		printf("����������������룺\n");
		else//��������������ѭ��
		break; 
	}
	//����ѡ��ֵ
	return n;
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �鿴��֣�ݵ�ĳ�յ�վ�ɻ�Ʊ��Ϣ����
void check()
{
	int i, j;//ѭ������
	int find = 1, flag = 0, count = 0;//��־����
	char qi[30];//��ʼվ 
	char mudi[30];//�յ�վ 
	printf("��������ʼ��(��ʾ����ʼ��Ϊ֣��)�� \n");
	scanf("%s", qi);//������ʼ��
	printf("������Ŀ�ĵأ� \n");
	scanf("%s", mudi);//����Ŀ�ĵ�

	while (1)
	{//��ѭ��״̬
		if (0 == strcmp(qi, "֣��"))
		{//��ʼ��Ϊ֣��ʱ
			flag = 1;//��־����Ϊ1����ʾ��ʼ��û�г���
			for (j = 0; j < d; j++)
			{//ѭ��d�κ�����Ϣ
				if (0 == strcmp(plane[j].zhongdian, mudi))
				{//������յ�վ�뺽����Ϣ�յ�վһ��
					count = 1;//��־����Ϊ1
					printf("����ţ� ");//��������
					printf("%s\n", plane[j].trainnumber);
					printf("��ʼ��:  ");//�����ʼ��
					printf("%s\n", plane[j].qishi);
					printf("Ŀ�ĵأ� ");//���Ŀ�ĵ�
					printf("%s\n", plane[j].zhongdian);
					printf("�˴κ�������Ʊ���� ");//�������Ʊ��
					printf("%d\n", plane[j].sellnumber);
					printf("�˴κ���ʱ�䣺");//�������ʱ��
					printf("%s\n", plane[j].time);
					printf("�˴κ���ɻ�Ʊ������  ");//���Ʊ��
					printf("%d\n\n\n\n", plane[j].piaonumber);
					return;
				}
			}
		}
		else
		{
			flag = 1;//��ʼ���������
			printf("�������󣬷��ز˵�!\n\n\n");
			return;
		}

		if (0 == count && flag == 1)
		{//��ʼ�ز���Ŀ�ĵ��������
			printf("sorry ����ѯ�Ľ������Ϣ!\n\n\n");
			return;
		}
		if (i > 1 && i % 10 == 0)  system("every key");//ÿʮ��һ����ʾ}
		return;
	}

}