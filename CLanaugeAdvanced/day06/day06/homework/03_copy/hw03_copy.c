#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileCopy(char* path, char* name)
{
	if (path == NULL || name == NULL)
	{
		return -1;
	}	

	// 将文件以二进制方式读取出来并通过动态申请内存空间，进行存储
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

	// 新建文件, 以写文件方式打开
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

	printf("请输入copy后的文件名:");
	scanf("%s", rename);

	int ret = fileCopy(cpath, rename);
	if (ret != 0)
	{
		printf("fileCopy err:%d\n", ret);
		return ret;
	}

	return 0;
}