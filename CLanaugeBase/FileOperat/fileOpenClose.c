/*******************/
/* �ļ��򿪹رպ��� */
/******************/

#include <stdio.h>
#include <stdlib.h>

int main1()
{
	FILE* fp;
	if (!(fp = fopen("F:\\ProgramLanguage\\CLanguage\\CLanaugeBase\\FileOperat\\test.txt", "rb"))) 
	// ����ļ���ʧ�ܣ��򷵻�NULL
	{
		printf("Can not open FILE!\n");
		system("pause");
	}
	else 
	{
		printf("Open success!\n");
	}

	fclose(fp); // �ر��ļ�

	return 0;
}