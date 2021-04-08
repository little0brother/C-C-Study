/**
* 求和 求s= a + aa + aaa + … + aa…a 的值（最后一个数中 a 的个数为 n ），
  其中 a 是一个1~9的数字，例如： 2 + 22 + 222 + 2222 + 22222 （此时 a=2 n=5 ） 
  输入：一行，包括两个整数，第1个为a，第2个为n（1 ≤ a ≤ 9，1 ≤ n ≤ 9），以英文逗号分隔。
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