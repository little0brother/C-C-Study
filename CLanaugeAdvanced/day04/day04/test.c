/**
* ��� ��s= a + aa + aaa + �� + aa��a ��ֵ�����һ������ a �ĸ���Ϊ n ����
  ���� a ��һ��1~9�����֣����磺 2 + 22 + 222 + 2222 + 22222 ����ʱ a=2 n=5 �� 
  ���룺һ�У�����������������1��Ϊa����2��Ϊn��1 �� a �� 9��1 �� n �� 9������Ӣ�Ķ��ŷָ���
*/

#include <stdio.h>

int main()
{
	int inputa;
	int inputn;
	int tmp = 1;
	int tmp1;
	int a[10] = { 0 };
	int sum = 0;

	scanf("%d,%d", &inputa, &inputn);


	// 1. sum = 1;  inputa = 11;
	// 2. sum = 12; inputa = 111;
	// 3. sum = 123;inputa = 1111;
	tmp = inputa;
	for (int i = 0; i < inputn; i++)
	{
		sum += inputa;
		inputa = inputa * 10 + tmp;
		printf("%d\n", inputa);
	}


	/**
	* 1. a[0] = 1;
	* 2. a[1] = 11;   1 * 10 + 1;
	* 3. a[2] = 111;  1 * 100 + 1 * 10 + 1;
	*/
	for (int i = 1; i < inputn; i++)
	{
		tmp *= 10;
	}

	for (int i = 0; i < inputn; i++)
	{
		tmp1 = tmp;
		a[i] = inputa * tmp;
		while (tmp1 > 1)
		{
			tmp1 /= 10;
			a[i] += inputa * tmp1 ;
		}
		tmp /= 10;
		sum += a[i];
	}

	for (int i = 0; i < inputn; i++)
	{
		printf("%d\n", a[i]);
	}

	printf("\n%d\n", sum);
	
	return 0;
}