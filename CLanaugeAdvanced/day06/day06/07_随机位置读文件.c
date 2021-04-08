#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stu
{
	char name[50];
	int id;
}Stu;

#if(0)
// ���ã����ļ�ָ���ƶ���ָ��λ��
// ����1��stream���ļ�ָ��
// ����2��offset�������ָ��λ�õ�ƫ���� ������ָ�������ƶ�������ָ�������ƶ���
// ����3��SEEK_SET ���ļ���ͷ�ƶ�offset���ֽڣ�SEEK_CUR�ӵ�ǰλ���ƶ�offset���ֽڣ�SEEK_END���ļ�ĩβ�ƶ�offset���ֽ�
// ����ֵ:�ɹ�����0,������-1������errno 
int fseek(FILE* stream, long offset, int whence);

// ���ã������ļ�ͷ���ļ�ָ���λ�ã����Լ��㳤�ȣ����ļ�ָ��ͨ��fseek()������ָ���ƶ����ļ�β��
// ����ֵ:�ɹ����ص�ǰ��дλ��,������-1������errno 
long ftell(FILE* stream);

// ���ļ�ָ���ƶ����ļ�ͷ
void rewind(FILE* stream);
#endif

void my_fwrite(char* path)
{
	FILE* fp = NULL;

	// �ļ��򿪲���������ļ��������򴴽�
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite fopen");
		return;
	}

	Stu s[3];
	char buf[50];
	for (int i = 0; i < 3; i++)
	{
		sprintf(buf, "stu%d%d%d", i, i, i);
		strcpy(s[i].name, buf);

		s[i].id = i + 1;
	}

	// д�ļ�, ���鷽ʽд
	// ����1��д���ļ����ݵ��ڴ��׵�ַ
	// ����2��д�����ݿ����ݵĴ�С
	// ����3��������д�ļ����ݵĴ�С = 3 * sizeof(Stu)
	// ����4���ļ�ָ��
	// ����ֵ���ɹ�д���ļ��Ŀ���Ŀ
	int ret = fwrite(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void my_fread(char* path)
{
	FILE* fp = NULL;

	// �Զ��ķ�ʽ���ļ�������ļ����������ʧ��
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread fopen:");
		return;
	}

	Stu s[3];
	Stu tmp;	// ���������ṹ��

	// 
	fseek(fp, 2 * sizeof(Stu), SEEK_SET);	
	//fseek(fp, (-1) * (int)(sizeof(Stu)), SEEK_END);

	int ret = fread(&tmp, sizeof(Stu), 1, fp);
	if (ret == 1)
	{
		printf("[tmp]%s, %d\n", tmp.name, tmp.id);
	}

	// ��ָ�����ƶ����ʼ�ĵط�
	//fseek(fp, 0, SEEK_SET);
	rewind(fp);

	// ���ļ�, ���鷽ʽд
	// ����1�����ļ����ݵ��׵�ַ
	// ����2�������ݿ����ݵĴ�С
	// ����3�����������ļ����ݵĴ�С = 3 * sizeof(Stu)
	// ����4���ļ�ָ��
	// ����ֵ���ɹ���ȡ�ļ����ݵĿ���Ŀ
	ret = fread(s, sizeof(Stu), 3, fp);
	printf("[my_fread] ret = %d\n", ret);

	for (int i = 0; i < 3; i++)
	{
		printf("id=%d, name=%s\n", s[i].id, s[i].name);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

int main()
{
	my_fwrite("../07.txt");
	my_fread("../07.txt");

	return 0;
}