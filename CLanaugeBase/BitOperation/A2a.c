/*****************/
/* ��Сд��ĸת�� */
/*****************/

#include <stdio.h>

int main1()
{
	char ch, temp;
	printf("please input letter: ");
	ch = getchar();
	temp = getchar();

	while ( !(ch >= 'A' && ch <= 'z') || (ch >= 'Z' && ch <= 'a'))
	{
		printf("Error!\nplease input letter: ");
		ch = getchar();
	}

	if (ch & 32)			// �ж��ַ������Ƶ�5λ�Ƿ�Ϊ 1 
	{
		ch = ch & 223;		// ���Ϊ 1 �������������Ե�5λȡ�������д
	}
	else
	{
		ch = ch | 255;		// �����Ϊ 1 ����λ�����㣬ʹ����λ�� 1 ����Сд
	}

	printf("%c", ch);

	//if (ch >= 97 && ch <= 122)
	//{
	//	ch = ch & 223;
	//}
	//else if (ch <= 90 && ch >= 60)
	//{
	//	ch = ch | 32;
	//}

	return 0;
}