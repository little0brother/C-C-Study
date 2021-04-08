#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileCopy(char* path, char* name)
{
	if (path == NULL || name == NULL)
	{
		return -1;
	}	

	// ���ļ��Զ����Ʒ�ʽ��ȡ������ͨ����̬�����ڴ�ռ䣬���д洢
	FILE* rfp = fopen(path, "rb");
	if (rfp == NULL)
	{
		perror("[fileCopy] fopen");
		return -2;
	} 

	fseek(rfp, 0, SEEK_END);
	int filelen = ftell(rfp);
	char* copytmp = (char*)malloc(filelen * sizeof(char) + 1);

	rewind(rfp);
	fread(copytmp, filelen, 1, rfp);
	copytmp[filelen] = 0;
	
	if (rfp != NULL)
	{
		fclose(rfp);
		rfp = NULL;
	}

	// �½��ļ�, ��д�ļ���ʽ��
	FILE* wfp = fopen(name, "wb");
	if (wfp == NULL)
	{
		perror("[fileCopy] fopen");
		return -3;
	}

	fwrite(copytmp, filelen, 1, wfp);

	if (wfp != NULL)
	{
		fclose(wfp);
		wfp = NULL;
	}
	
	return 0;
}

int main()
{
	char* cpath = "./homework/03_copy/test.jpg";
	char rename[64] = { 0 };

	printf("������copy����ļ���:");
	scanf("%s", rename);

	int ret = fileCopy(cpath, rename);
	if (ret != 0)
	{
		printf("fileCopy err:%d\n", ret);
		return ret;
	}

	return 0;
}