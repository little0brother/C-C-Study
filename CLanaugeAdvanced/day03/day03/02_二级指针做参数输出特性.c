#include <stdio.h>

#if(0)
// ֵ���ݣ��βε��κ��޸Ĳ���Ӱ�쵽ʵ��
// ����ȡ��ַ�� ����ֵ���� ����Ӱ���ַ�ڵ�����
int getMem(char* p)
{
	p = (char*)malloc(sizeof(char) * 100);
	if (p == NULL)
	{
		return -1;
	}
	strcpy(p, "dfae");
	printf("p = %s\n", p);

	return 0;
}

int main(void)
{
	char* p = NULL;
	int ret = 0;

	ret = getMem(p);
	if (ret != 0)
	{
		printf("getMen err:%d\n", ret);
		return ret;
	}
	printf("p = %s\n", p);

	printf("\n");
	return 0;
}
#endif


#if(1)
// ����ָ�룬ͨ����ַ���ݣ��޸��β����ı�ʵ��
int getMem(char** p /* ����� */)
{
	if (p == NULL)
	{
		return -1;
	}

	// ������ʱ����
	char* tmp = (char*)malloc(100);
	if (tmp == NULL)
	{
		return -2;
	}

	strcpy(tmp, "dfae");

	*p = tmp;

	return 0;
}

int main(void)
{
	char* p = NULL;
	int ret = 0;

	ret = getMem(&p);
	if (ret != 0)
	{
		printf("getMen err:%d\n", ret);
		return ret;
	}
	printf("p = %s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}


	printf("\n");
	return 0;
}
#endif