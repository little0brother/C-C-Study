#include <stdio.h>

/*
* c����û���ַ������ͣ�ͨ���ַ�����ģ��
* C�����ַ��������ַ� '\0', ���� 0 ����
*/

#if(0)
int main()
{
	// ��ָ�����ȣ�û�� 0 ���������ж��ٸ�Ԫ�ؾ��ж೤
	char buf[] = { 'a', 'b', 'c' };
	printf("buf=%s\n", buf);

	// ָ�����ȣ�����û�и�ֵ��Ԫ���Զ��� 0 
	char buf1[100] = { 'a', 'b', 'c' };
	printf("buf1=%s\n", buf1);

	// ����Ԫ�ظ�ֵΪ 0
	char buf2[100] = { 0 };

	//char buf3[2] = { '1', '2', '3' };	// ����Խ��


	// �ַ���0����������0��acsiiֵ��ͬ��������Ҳ��ͬ
	char buf4[50] = { '1', 'a', 'b', '0', '7' };
	printf("buf4 = %s\n", buf4);

	char buf5[50] = { '1', 'a', 'b', 0, '7' };
	printf("buf5 = %s\n", buf5);

	char buf6[50] = { '1', 'a', 'b', '\0', '7' };
	printf("buf6 = %s\n", buf6);


	// ʹ���ַ�����ʼ��������
	char buf7[] = "fadfa dasfddasfdas";
	// strlen(); ���ַ������ȣ�����������0���ַ�'\0'
	// sizeof(); �����鳤�ȣ���������0���ַ�'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf7), sizeof(buf7));

	char buf8[100] = "fadfa dasfddasfdas";
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));


	printf("test:");
	// ת���ַ�
	char str[] = "\0129";	//  '\012'='\n'
	printf("%s\n", str);

	printf("\n");
	return 0;
}
#endif

int main()
{
	/*
	* ������ʷ�ʽ
	* 1.[]��ʽ
	* 2.ָ�뷽ʽ
	*/
	char buf[] = "hgdsauifasdojfd";
	int n = strlen(buf);

	// 1.[]��ʽ
	for (int i = 0; i < n; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	// 2.ָ�뷽ʽ
	char* p = NULL;
	p = buf; // ��������Ϊ����Ԫ���׵�ַ
	for (int i = 0; i < n; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%c", *(p + i));
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%c", *(buf + i));
	}
	printf("\n");

	// buf��p��ȫ�ȼ���
	// p++;
	// buf++;
	// bufֻ��һ�������������޸�
	
	// �����ڴ���ʱ�������Ѿ�ȷ�ϣ����shuzu�����޸ģ�ӦΪ���鳤�ȹ̶���
	// ����޸����飬��ô������ָ�ĵ�ַ�ռ�ͻ�仯����ϵͳ�Զ��ͷ��ڴ�ʱ���ᵼ���ͷű������ͷŵ�λ��


	printf("\n");
	return 0;
}