#include <iostream>
using namespace std;

int Strlen(const char *str)			//计算字符串长度
{
	int i = 0;
	while (*str++)					//当没有遇到‘\0’时，长度自增
		i++;

	return i;
}

int Strcmp(char *str1, char *str2)		//比较两字符串大小
{
	if (!str1 || !str2)				//非法检测
		return -1;

	while (*str1++ == *str2++);		//计算出两字符串 不相同或结束 位置

	if (*str1 == *str2)				//判断当前字符是否相同
		return 0;
	else if (*str1 > *str2)			//判断当前字符大小 如果串1>串2 返回值为1
		return 1;
	else
		return 0;
}

void Strcat(char *str1, char *str2)		//字符串连接函数
{
	if (!str1 || !str2)
		return;

	while (*str1)				//将指针移向当前字符串末尾
		str1++;

	while (*str2)				//将串2依次连接至串1
		*str1++ = *str2++;
	*str1 = '\0';				//在连接好的串末尾加上 截至字符
}

void Strcpy(char *str1, char *str2)		//字符串拷贝函数
{
	if (!str1 || !str2)
		return;

	while (*str2)					//当字符串2未到串末尾时 将串2拷贝至串1
		*str1++ = *str2++;

	*str2 = '\0';
}

int Strchr(const char *str, char chr)		//在字符串中查找单个字符
{
	if (!str || !chr)
		return 0;

	int len_str = Strlen(str);					//计算主串长度
	for (int i = 0; i <= len_str; i++)			
		if (*str++ == chr)						//判断当前是否相等
			return i+1;
}

int Strstr(char *str1, char *str2, int n)		//在主串中查找子串（n为查找起始位置）
{
	if (!str1 || !str2)
		return 0;

	int len_str1 = strlen(str1);				//计算两串长度
	int len_str2 = strlen(str2);

	for (int i = n; i <= len_str1 - len_str2; i++)		// i值小与两串之差 为查找次数
	{
		int k = 0;
		while (k < len_str2 && str1[i+k] == str2[k])	//当长度小于子串 并且子串与主串字符不等 则主串后移一位
			k++;

		if (k == len_str2)
			return i;
	}
	return -1;
}

int main()
{

	char a[20] = "good ";
	char b[10] = "study";
	
	if (Strcmp(a, b))
		cout << "比较结果: " << "a > b" << endl;
	else
		cout << "比较结果: " << "a < b" << endl;

	Strcat(a, b);
	cout << "连接结果: " << a << endl;

	Strcpy(a, b);
	cout << "拷贝结果: " << a << endl;

	char c = 'd';
	int i = Strchr(a, c);
	cout << "查找字符结果: " << i << endl;

	char a1[20] = "abcdefghijk";
	char a2[20] = "fgh";
	cout << "查找子串结果: " << Strstr(a1, a2, 0) << endl;

	system("pause");
	return 0;
}