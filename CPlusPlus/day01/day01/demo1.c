/**
* ���ǲ����Ƴ���һ��γ̣���������һ�δ������������˵���ǣ�
�γ̵ĳ�ʼ����Ϊ vv Ԫ��ÿ���� mm ��ѧԱ���γ̵Ķ��۾�Ҫ���� aa Ԫ�����ڿγ��ܹ����ɵ�ѧ�����ޣ���˱����� nn �˵�ʱ���ֹͣ������

������ʦ��֪�������γ�ֹͣ����ʱ��һ�����Ի�ö���ѧ���أ�
*/

#include <stdio.h>

int main()
{
	int n=0, v=0, m=0, a=0;
	int sum = 0;
	int count = 0;

	scanf("%d %d %d %d", n, v, m, a);

	printf("%d %d %d %d", n, v, m, a);

	while (count < n)
	{
		sum += v;
		printf("%d", sum);
		
		count++;
		v += a;
	}

	printf("%d", sum);

	return 0;
}