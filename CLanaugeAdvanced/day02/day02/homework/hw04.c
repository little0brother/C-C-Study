/************************************************************************************************
*  键值对（“key = value”）字符串，在开发中经常使用
	要求1：请自己定义一个接口，实现根据key获取.
	要求2：编写测试用例。
	要求3：键值对中间可能有n多空格，请去除空格

	注意：键值对字符串格式可能如下：
	"key1 = value1"
	"key2 =       value2"
	"key3  = value3"
	"key4        = value4"
	"key5   =   "
	"key6   ="
	
	int getKeyByValue(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen);

	int main(void)
	{
		//...
		getKeyByValude("key1 =   valude1", "key1", buf, &len);
		//...

		return 0;
	}
*************************************************************************************************/

/*
* getKeyByValue();
*   功能: 挑出键值对所对应的值
*   参数:
*		keyvaluebuf: 键值对
*		keybuf     : 所要查询的键名称
*		valuebuf   : 用于存放键所对应值的字符串
*		valuebuflen: 键所对应值的字符串的长度
*   返回值: 
*		成功: 0
*		失败: 非0
*/

/*
* trimSpace();
	功能获取非空字符串
	参数：
		inbuf:  原始字符串buf首地址
		outbuf: 非空字符串buf首地址
	返回之：
		成功：0
		失败：非0
*/

#include <stdio.h>
#include <ctype.h>

int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen);

#if(1)
// 去除非空字符串
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* p = inbuf;
	char* buf = outbuf;

	// 定义字符串vlaue的起点终点
	int begin = 0;
	int end = strlen(inbuf) - 1;
	int n = 0;

	// 因为键值对中间会有空格，所以要去除空格
	while ( isspace(inbuf[begin]) && (inbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(inbuf[end]) && end > 0)
	{
		end--;
	}

	// 如果字符串为0 那么字符串不存在
	if (end == 0)
	{
		return -2;
	}


	// 记录字符串长度
	n = end - begin + 1;

	// 将字符串拷贝至vbuf，并通过形参返回至主函数
	strncpy(outbuf, inbuf + begin, n);

	return 0;
}

// 查找键所对的值，并且去除等号
int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen)
{
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return  -1;
	}

	char* kvbuf = keyvaluebuf;
	char* kbuf  = keybuf;
	char* vbuf  = valuebuf;


	// 查找键值，并跳转至后方继续查找
	// kbbuf = "= value"
	// "key4 = vluue " -> " =   value "
	kvbuf = strstr(kvbuf, kbuf);
	if (kvbuf == 0)
	{
		return -2;
	}
	kvbuf += sizeof(kbuf);

	//  查到 = 
	// 跳过 = 重新设置查找位置
	//  " =   value " -> "   value  "
	kvbuf = strstr(kvbuf, "=");
	if (kvbuf == 0)
	{
		return -3;
	}
	kvbuf += sizeof("=");

	// 取出非空字符串
	int ret = 0;
	ret = trimSpace(kvbuf, vbuf);
	if (ret != 0)
	{
		printf("trimSpace err:%d\n", ret);
		return -4;
	}

	// 获取长度,通过*间接赋值
	*valuebuflen = strlen(vbuf);

	return 0;
}
#endif

int main(void)
{
	char* keyvaluebuf = "key1 =         ";
	char* key         = "key1";
	char  value[100]  = { 0 };

	int valuelen = 0;
	int ret         = 0;

	ret = getKeyByValue(keyvaluebuf, key, value, &valuelen);
	if (ret != 0)
	{
		printf("getKeyByValue err:%d\n", ret);
		return ret;
	}

	printf("val = %s\nvaluebuflen = %d\n", value, valuelen);

	printf("\n");
	return 0;
}

#if(0)
// 与上述方法相同，在排除空格以及“=”时利用循环判断来解决
int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen)
{
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return  -1;
	}

	char* kvbuf = keyvaluebuf;
	char* kbuf = keybuf;
	char* vbuf = valuebuf;

	// 查找键值，并跳转至后方继续查找
	// kbbuf = "= value"
	// "key4 = vluue " -> " =   value "
	kvbuf = strstr(kvbuf, kbuf);
	if (kvbuf == 0)
	{
		return -2;
	}
	kvbuf += sizeof(kbuf);

	// 定义字符串vlaue的起点终点
	int begin = 0;
	int end = strlen(kvbuf) - 1;

	// 空格要用单引号 '='
	// 因为键值对中间会有空格和等号，所以要去除空格和等号
	while ( (isspace(kvbuf[begin]) || kvbuf[begin] == '=') && (kvbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(kvbuf[end]) && end > 0)
	{
		end--;
	}

	// 记录字符串长度
	*valuebuflen = end - begin + 1;
	if (*valuebuflen <= 0)
	{
		return -5;
	}

	// 将字符串拷贝至vbuf，并通过形参返回至主函数
	strncpy(vbuf, kvbuf + begin, *valuebuflen);

	return 0;
}
#endif