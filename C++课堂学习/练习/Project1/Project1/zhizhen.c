#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cnt = 0;
	void* p;
	
	while ((p = malloc(100 * 1024 * 1024))) 
	//����ռ�  ���������ֵ��P 
	//�����P����һ����Чֵ �����������ȥ  ÿ������100M�ռ�
	{
		cnt++;
	}
	printf("%d00\n", cnt);

	system("pause");
	return 0;
}