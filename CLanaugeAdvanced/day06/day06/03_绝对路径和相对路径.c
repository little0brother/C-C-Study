#include <stdio.h>

int main()
{
	FILE* fp = NULL;

	// ���������ȼ�
	// F:\\ProgramLanguage\\CLanguage\\CLanaugeAdvanced\\day06\\day06\\03.txt  (ֻ�����windows)
	// F:/ProgramLanguage/CLanguage/CLanaugeAdvanced/day06/day06/03.txt  (�����windows��linux)

	// "F:\\ProgramLanguage" windows��д��
	// "F:/ProgramLanguage"  linux,windows��֧�֣�����д��

	// ����·����F:\\ProgramLanguage\\CLanguage\\CLanaugeAdvanced\\day06\\day06\\03.txt
	// ���·����'/' 45�ȣ� ./, ../������ʹ�ã�
	// vs:�������ʱ���������Ŀ����(��ǰ����)
	// ֱ�����п�ִ�г�������ڳ���(��ִ�г������ڵ��ļ��������û�������ļ��ͻ���ִ���)
	fp = fopen("./03.txt", "r+");
	if (fp == NULL)
	{
		perror("fopen");
		system("pause");
		return -1;
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return 0;
}