#include <stdio.h>
#include <string.h>
#include "des.h"

int main()
{
	unsigned char buf[] = "iuio34234uondlafdas";
	int srclen = strlen(buf);
	unsigned char dst[100] = { 0 };		// ����
	int dstlen = 0;		// ���ĵĳ���

	// ����
	int ret = DesEnc(buf, srclen, dst, &dstlen);
	if (ret != 0)
	{
		printf("����ʧ��, err:%d\n", ret);
	}

	printf("%s\t���ܺ�%s\n", buf, dst);

	memset(buf, 0, sizeof(buf));
	int len = 0;
	// ����
	ret = DesDec(dst, dstlen, buf, &len);
	if (ret != 0)
	{
		printf("����ʧ��, err:%d\n", ret);
	}

	if (srclen != len)
	{
		printf("���ܺ�ĳ��Ⱥ�ԭ���Ĳ�һ��\n");
	}

	printf("%s\t���ܺ�%s\n", dst, buf);

	return 0;
}