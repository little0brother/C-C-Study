#include <stdio.h>
#include <string.h>
#include "des.h"

int main()
{
	unsigned char buf[] = "iuio34234uondlafdas";
	int srclen = strlen(buf);
	unsigned char dst[100] = { 0 };		// 密文
	int dstlen = 0;		// 密文的长度

	// 加密
	int ret = DesEnc(buf, srclen, dst, &dstlen);
	if (ret != 0)
	{
		printf("加密失败, err:%d\n", ret);
	}

	printf("%s\t加密后：%s\n", buf, dst);

	memset(buf, 0, sizeof(buf));
	int len = 0;
	// 解密
	ret = DesDec(dst, dstlen, buf, &len);
	if (ret != 0)
	{
		printf("解密失败, err:%d\n", ret);
	}

	if (srclen != len)
	{
		printf("解密后的长度和原来的不一致\n");
	}

	printf("%s\t解密后：%s\n", dst, buf);

	return 0;
}