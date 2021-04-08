/**
	���ַ�����������������abcd11111abcd2222abcdqqqqq����, ��дһ�������ӿڣ�������½����
	���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
	Ҫ��
	1. ��ȷʵ�ֽӿں͹���
	2. ��д��������
*/

/**
	src:    ԭ�ַ���
	dst:    ���ɵĻ���Ҫ�����ַ���
	sub:    ��Ҫ���ҵ����ַ���
	new_sub:�ỻ�������ַ���

	return : 0 �ɹ�
			-1 ʧ��
*/

#include <stdio.h>
#include <string.h>

#define DSTLEN 100

// ��һ�治��ȫ���ܣ�������ԭ���Ѿ�ʵ��
#if(0)
int replaceSubstr(/* in */char* src, /* out */char** dst, /* in */char* sub,  /* in */char* new_sub)
{
	if (src == NULL || sub == NULL || new_sub == NULL)
	{
		return -1;
	}

	char* src_bak  = src;
	char* flag_len = NULL;
	char* dst_bak  = (char*)malloc(DSTLEN);		// ��ʱ�������dst��ָ�����ͨ��*dst = dst_bak ��ɵ�ַת��
	// ��¼������һ�β����Ӵ��ļ������
	int n;

	while (src_bak != NULL)
	{
		src_bak = strstr(src_bak, sub);
		if (src_bak == NULL)
		{
			return -2;
		}
		src_bak += sizeof(sub);

		flag_len = strstr(src_bak, sub);
		// ���flag_len ΪNULL ˵��֪���ַ���β��û��ƥ����ַ�������֮�������Ӵ�ȫ����Ҫƴ����dst_bak��
		if (flag_len == NULL)
		{
			n = strlen(src);
		}
		else
		{
			n = (flag_len - src_bak);
		}

		// err �޷������ַ������ñ�����
		//char* sub_tmp = NULL;
		//sub_tmp = (char*)malloc((n) * sizeof(char));
		//if (sub_tmp == NULL)
		//{
		//	return -3;
		//}
		char sub_tmp[100] = { 0 };
		// ������Ŀ���Ӵ��м�ı���ȡ����
		strncpy(sub_tmp, src_bak, n);
		// ��src�׵�ַ�ƶ���flag_len���ҵ�λ��֮��
		src_bak += n;

		sprintf(dst_bak, "%s%s", new_sub, sub_tmp);
		dst_bak += n;
	}

	*dst = dst_bak;

	return 0;
}
#endif

int replaceSubstr(/* in */char* src, /* out */char** dst, /* in */char* sub,  /* in */char* new_sub)
{
	if (src == NULL || sub == NULL || new_sub == NULL || dst == NULL)
	{
		return -1;
	}

	/**
	* src     = "abcd11111abcd2222abcdqqqqqabcd";
	* sub     = "abcd";
	* new_sub = "dcabbb";
	*/

	char* src_bak  = src;
	char* flag_len = NULL;
	char* dst_bak  = (char*)malloc(DSTLEN);		// ��ʱ�������dst��ָ�����ͨ��*dst = dst_bak ��ɵ�ַת��
	//char dst_bak[100] = {0};
	int sstr2str_len; // ��¼������Ҫ�����ַ����м��Ӵ��ĳ���
	char sub_tmp[100] = { 0 }; // �������Ҫ���ҵ�Ŀ���Ӵ��м���ַ���
	int n = 0;		// �����ж��ַ�����ǰ���ǲ���ƥ���Ӵ�

	*dst = dst_bak;
	flag_len = src;

	while (*src_bak != 0)
	{
		src_bak = strstr(src_bak, sub);
		// ���û��ƥ���Ӵ�����ֱ�ӽ��ַ���ԭ�ⲻ�����Ƶ�src_bak�У����ҽ���
		if (src_bak == NULL)
		{
			strcpy(dst_bak, src);
			break;
		}

		// �����ж� ��Ҫ���ҵ��ַ��� �ǲ�������ǰ�ˣ������������ǰ�ˣ���˵��ǰ���������ַ�����Ҫ���Ƶ�dst��
		if (src != src_bak && n == 0)
		{
			n = src_bak - src;
			strncpy(dst_bak, src, n);
			dst_bak += n;
		}
		n++;		// ��������¼ѭ�����������ҷ�ֹ�ڶ����ж�Ϊ��ǰ�ˡ�

		// �ܽ����϶���ƥ���Ӵ�
		src_bak += strlen(sub);
		// ��������ַ�����β��������ѭ��
		if (src_bak == NULL)
		{
			break;
		}

		flag_len = strstr(src_bak, sub);
		if (flag_len == NULL)
		{
			sstr2str_len = strlen(src);
		}
		else
		{
			sstr2str_len = (flag_len - src_bak);
		}

		strncpy(sub_tmp, src_bak, sstr2str_len);
		sprintf(dst_bak, "%s%s", new_sub, sub_tmp);

		src_bak += sstr2str_len;
		dst_bak += (sstr2str_len + strlen(new_sub));
	}

	return 0;
}

void print_str(char *str)
{
	printf("%s\b", str);
}

int main()
{
	char* str		   = "abcd11111abcd2222abcdqqqqqabcd";
	char* fill_str	   = NULL;		// ��replaceSubstr()�����з���ռ�
	char* serch		   = "abcd";
	char* change_str   = "dsatggg";
	int ret = 0;

	ret = replaceSubstr(str, &fill_str, serch, change_str);
	if (ret != 0)
	{
		printf("replaceSubstr err:%d", ret);
		return ret;
	}

	printf("�滻ǰ�ַ�����\n");
	print_str(str);

	printf("\n�滻���ַ�����\n");
	print_str(fill_str);

	if (fill_str != NULL)
	{
		free(fill_str);
		fill_str = NULL;
	}

	printf("\n");
	return 0;
}