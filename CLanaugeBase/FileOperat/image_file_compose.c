/*******************/
/* ͼƬ���ļ��ϳ��� */
/*******************/

/* �����ļ��Զ����Ƶ���ʽ��ȡ�����������Զ����Ƶ���ʽд�뵽��һ���ļ��У�ʵ��һ���ļ��������ݣ�ͨ���ĺ�׺���������ļ��ĳ��� */

#include <stdio.h>
#include <stdlib.h>

int main4()
{
	FILE *f_pic, *f_file, *f_finish;
	char pic_name[20], file_name[20], finish_name[20], ch;

	printf("Please input compose image name: ");
	scanf("%s", pic_name);
	printf("\nPlease input compose other file name: ");
	scanf("%s", file_name);
	printf("\nPlease input compose finish file name: ");
	scanf("%s", finish_name);

	if (!(f_pic = fopen(pic_name, "rb")))
	{
		printf("Con not open %s!", pic_name);
		exit(0);
	}

	if (!(f_file = fopen(file_name, "rb")))
	{
		printf("Con not open %s!", file_name);
		exit(0);
	}

	if (!(f_finish = fopen(finish_name, "wb")))
	{
		printf("Con not open %s!", finish_name);
		exit(0);
	}

	while (!(feof(f_pic)))
	{
		ch = fgetc(f_pic);
		fputc(ch, f_finish);
	}
	fclose(f_pic);

	while (!(feof(f_file)))
	{
		ch = fgetc(f_file);
		fputc(ch, f_finish);
	}
	fclose(f_file);
	fclose(f_finish);

	return 0;
}