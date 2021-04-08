//2. 实现配置文件读写的写功能，key = value格式，可执行程序参考《02_配置文件》
//提示：
//a) 循环读每一行, 如果此行包含key，则把key的value修改
//b) 如果所有行都不包含key，则在文件结尾追加： "key = value"
//c) 文件大小不能超过8k
//c) 参考：fgets(), strstr(), sprintf(), strcat(), fprintf(), fputs(), fseek(), ftell(), rewind()


/******************************** 写功能未完成 *******************************/

#include <stdio.h>
#include <string.h>

#define INIPATH "./homework/02_cfg/mycfg.ini"

static int flag = -1;	// 标志是否找到该key

void menu()
{
	printf("===============================\n");
	printf("1.写配置文件\n");
	printf("2.读配置文件\n");
	printf("3.清屏\n");
	printf("4.退出\n");
	printf("===============================\n");
}

int trimSpace(char* pval, char* val)
{
	if (pval == NULL || val == NULL)
	{
		return -1;
	}

	int begin = 0;
	int end = strlen(pval) - 1;
	int valLen = 0;

	// 两头堵模型，去除value两边的空格
	while (isspace(pval[begin]) && pval[begin] != 0)
	{
		begin++;
	}

	while (isspace(pval[end]) && pval[end] != 0)
	{
		end--;
	}

	if (end < 0)
	{
		return -2;
	}

	// 计算出 value 的长度，并复制到指定空间中
	valLen = end - begin + 1;
	strncpy(val, pval + begin, valLen);

	return 0;
}

int AlterCfgFile(char* key, char* alval)
{


	return 0;
}

// 搜索是否有键值
int SearchKey(char* path, char* key, char** val)
{
	flag = -1;

	if (path == NULL || key == NULL)
	{
		return -1;
	}

	FILE* fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("[SearchKey] fopen:");
		return -2;
	}

	char fileBuf[512] = { 0 };
	char* tmp = NULL;
	char* pval = NULL;

	// 如果没有遇到文件结尾则一直查找
	while (!feof(fp))
	{
		// 按行读取文件
		tmp = fgets(fileBuf, sizeof(fileBuf), fp);

		// 查找key
		pval = strstr(fileBuf, key);
		if (pval != NULL)
		{
			pval = strchr(tmp, '=');

			// 如果找到 = 则代表有对应value，将value通过二级指针传出
			if (pval != NULL)
			{
				pval++;
				*val = (char*)malloc(strlen(pval) * sizeof(char) + 1);
				strcpy(*val, pval);

				flag = 1;
				break;
			}
			else 
			{
				continue;
			}
		}
		else
		{
			flag = 0;
		}
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void wirteIni()
{
	char key[512]  = { 0 };
	char val[512]  = { 0 };
	char pval[256] = { 0 };
	int  vallen    = 0;

	printf("请输入key:");
	scanf("%s", key);
	printf("请输入value:");
	scanf("%s", val);

	vallen = (int)strlen(val);

	// 查找key
	int ret = SearchKey(INIPATH, key, pval/* 无实际作用 */);
	if (ret != 0)
	{
		printf("[wirteIni] searchKey err:%d\n", ret);
	}

	if (flag == 1)
	{
		//printf("flag = %d\n", flag);
		AlterCfgFile(key, pval);
	}
}

// 原理的实现
#if(0)
int ReadCfgFile(char* path, char* key, char* val, int* len)
{
	if (path == NULL || key == NULL || val == NULL || len == NULL)
	{
		return -1;
	}

	FILE* fp = NULL;
	fp = fopen(path, "r");
	if (fp == NULL)
	{
		perror("ReadCfgFile fopen");
		return -2;
	}

	char buf[1024] = { 0 };
	char* tmp = NULL;
	char* pval = NULL;

	while (!feof(fp))
	{
		// 按照行读取，将文件内容读取到 tmp中， 通过strstr判断文件 key是否存在
		// fgets()读取一行之后，会将指针移动到下一行
		tmp = fgets(buf, sizeof(buf), fp);

		pval = strstr(tmp, key);
		if (pval != NULL)
		{
			// 寻找key所对应的value值
			pval = strchr(pval, '=');
			if (pval == NULL)
			{
				continue;
			}
			pval++;

			flag = 1;
			// 为写函数的查找键值的判断 len为writeIni传入的键长度，如果不为零则代表writeIni调用的函数，则只进行查找，不进行vlaue的改变
			if (flag == 1 && *len != 0)
			{
				break;
			}

			int ret = trimSpace(pval, val);
			if (ret != 0)
			{
				printf("trimSpace err: %d\n", ret);
				return -3;
			}

			*len = strlen(val);
			
			break;
		}
		// 标志是否找到key 如果未找到 key 则不会 通过break 跳出循环
		flag = 0;
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}

	return 0;
}
#endif

void readIni()
{
	char key[512] = { 0 };
	char val[512] = { 0 };
	char* pval = NULL;

	printf("请输入key:");
	scanf("%s", key);

	// 进行key值查找、如果找到标志位为1，如果未找到标志位为0，其他情况为-1
	int ret = SearchKey(INIPATH, key, &pval);
	if (ret != 0)
	{
		printf("[redIni] SearchKey err: %d\n", ret);
	}

	if (flag == 1 && pval != NULL)
	{
		trimSpace(pval, val);
		if (val != NULL)
		{
			printf("\n %s对应的value为:%s, 长度为：%d\n", key, val, strlen(val));
		}
	}
	else if (flag == 0 || pval == NULL)
	{
		printf("未查找到%s\n", key);
	}
}

int main()
{
	int choose = 0;

	while (1)
	{
		menu();
		printf("cmd:");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1:	wirteIni(); break;
		case 2: readIni();  break;
		case 3: system("cls"); break;
		case 4:
		default: exit(0);
		}
	}

	return 0;
}