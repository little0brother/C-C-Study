/****************************/
/* �ṹ���빲���庯��������� */
/****************************/

#include <stdio.h>

int main()
{
	// �ṹ�嶨���÷�����
	//main1();

	// ��Ʊͳ�Ƴ���
	//main2();

	// ����ָ��
	//main3();

	// �ṹָ������������Ĳ���
	//main4();

	// ��̬�洢���������
	//main5();

	// ������union
	main6();


	// ����
	//main100();

	return 0;
}



// ע�ͺ����� ����:ɾ��ָ���ַ��������ַ�
#if(0)
void scanf_str(char ch[80])
{
	gets_s(ch, 80);
}

// ɾ���ַ����е�ָ���ַ�
void delete_ch(char ch[80], char c)
{
	int i, j;
	for (i = j = 0; ch[i] != '\0'; i++)
		if (ch[i] != c)
			ch[j++] = ch[i];

	ch[j] = '\0';
}

void printf_ch(char ch[80])
{
	printf("%s", ch);
}

int main()
{
	char str[20];
	char c;
	
	scanf_str(str);
	c = getchar();
	delete_ch(str, c);
	printf_ch(str);

	return 0;
}
#endif


#if(0)
/** ��ӡ1-5�׳� **/

#include <stdio.h>

int f(int a)
{
	static int f = 1;

	f = f * a;

	return f;
}

int main()
{
	int i;
	for (int i = 1; i <= 5; i++)
		printf("%d! = %d\n", i, f(i));
	
	return 0;
}
#endif