#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
5. ���ַ�����������������abcd11111abcd2222abcdqqqqq����,��дһ�������ӿڣ�������½����
���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
Ҫ��
1. ��ȷʵ�ֽӿں͹���
2. ��д��������
*/

/*
src:    ԭ�ַ���
dst:    ���ɵĻ���Ҫ�����ַ���
sub:    ��Ҫ���ҵ����ַ���
new_sub:�ỻ�������ַ���

return : 0 �ɹ�
-1 ʧ��
*/
int replaceSubstr(/* in */char *src, /* out */char** dst,
	/* in */char *sub,  /* in */char *new_sub)
{
	if (src == NULL || dst == NULL ||
		sub == NULL || new_sub == NULL)
	{
		return -1;
	}

	/*
	src = "dddddabcd11111abcd2222abcdqqqqq";
	sub = "abcd"
	new_sub = "aaaaaa"
	*/

	char *start = src;
	char *p = NULL;
	char tmp[512] = { 0 };
	int len = 0;

	do 
	{
		/*
		src = "dddddabcd11111abcd2222abcdqqqqq";
		sub = "abcd"
		new_sub = "aaaaaa"
		*/
		p = strstr(start, sub); 
		if (p != NULL)
		{
			len = 0;
			len = p - start;
			if (len > 0)
			{
				strncat(tmp, start, len); //tmp = "ddddd"
			}

			strncat(tmp, new_sub, strlen(new_sub)); //tmp = "dddddaaaaaa"

			//�����������λ��
			start = p + strlen(sub);
		}
		else
		{
			strcat(tmp, start);
			break;
		}

	} while (*start != '\0'); //start[i]  != 0

	char *buf = (char *)malloc(strlen(tmp) + 1);
	strcpy(buf, tmp);

	//��Ӹ�ֵ����ָ������������
	*dst = buf;


	return 0;
}

void freeBuf(char *buf)
{
	free(buf);
	buf = NULL;
}

void freeBuf2(char **buf)
{
	char *tmp = *buf;

	if (tmp != NULL)
	{
		free(tmp);
	}

	*buf = NULL;

}

int main(void)
{
	char *p = "dddddabcd11111abcd2222abcdqqqqq";
	char *buf = NULL; //��replaceSubstr�����з���ռ�
	int ret = 0;

	ret = replaceSubstr(p, &buf, "abcd", "cccc");
	if (ret != 0)
	{
		printf("replaceSubstr err: %d\n", ret);

		system("pause");
		return ret;
	}
	printf("p = %s\n", p);
	printf("buf = %s\n", buf);

	/*
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	*/

// 	freeBuf(buf);
// 	free(buf);
// 	buf = NULL;

	freeBuf2(&buf);

	if (buf != NULL)
	{
		free(buf);
	}

	printf("\n");
	system("pause");
	return 0;
}