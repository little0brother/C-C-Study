#include <iostream>
using namespace std;

int Strlen(const char *str)			//�����ַ�������
{
	int i = 0;
	while (*str++)					//��û��������\0��ʱ����������
		i++;

	return i;
}

int Strcmp(char *str1, char *str2)		//�Ƚ����ַ�����С
{
	if (!str1 || !str2)				//�Ƿ����
		return -1;

	while (*str1++ == *str2++);		//��������ַ��� ����ͬ����� λ��

	if (*str1 == *str2)				//�жϵ�ǰ�ַ��Ƿ���ͬ
		return 0;
	else if (*str1 > *str2)			//�жϵ�ǰ�ַ���С �����1>��2 ����ֵΪ1
		return 1;
	else
		return 0;
}

void Strcat(char *str1, char *str2)		//�ַ������Ӻ���
{
	if (!str1 || !str2)
		return;

	while (*str1)				//��ָ������ǰ�ַ���ĩβ
		str1++;

	while (*str2)				//����2������������1
		*str1++ = *str2++;
	*str1 = '\0';				//�����ӺõĴ�ĩβ���� �����ַ�
}

void Strcpy(char *str1, char *str2)		//�ַ�����������
{
	if (!str1 || !str2)
		return;

	while (*str2)					//���ַ���2δ����ĩβʱ ����2��������1
		*str1++ = *str2++;

	*str2 = '\0';
}

int Strchr(const char *str, char chr)		//���ַ����в��ҵ����ַ�
{
	if (!str || !chr)
		return 0;

	int len_str = Strlen(str);					//������������
	for (int i = 0; i <= len_str; i++)			
		if (*str++ == chr)						//�жϵ�ǰ�Ƿ����
			return i+1;
}

int Strstr(char *str1, char *str2, int n)		//�������в����Ӵ���nΪ������ʼλ�ã�
{
	if (!str1 || !str2)
		return 0;

	int len_str1 = strlen(str1);				//������������
	int len_str2 = strlen(str2);

	for (int i = n; i <= len_str1 - len_str2; i++)		// iֵС������֮�� Ϊ���Ҵ���
	{
		int k = 0;
		while (k < len_str2 && str1[i+k] == str2[k])	//������С���Ӵ� �����Ӵ��������ַ����� ����������һλ
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
		cout << "�ȽϽ��: " << "a > b" << endl;
	else
		cout << "�ȽϽ��: " << "a < b" << endl;

	Strcat(a, b);
	cout << "���ӽ��: " << a << endl;

	Strcpy(a, b);
	cout << "�������: " << a << endl;

	char c = 'd';
	int i = Strchr(a, c);
	cout << "�����ַ����: " << i << endl;

	char a1[20] = "abcdefghijk";
	char a2[20] = "fgh";
	cout << "�����Ӵ����: " << Strstr(a1, a2, 0) << endl;

	system("pause");
	return 0;
}