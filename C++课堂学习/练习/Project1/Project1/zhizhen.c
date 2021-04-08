#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cnt = 0;
	void* p;
	
	while ((p = malloc(100 * 1024 * 1024))) 
	//申请空间  把算出来的值给P 
	//如果给P的是一个有效值 则程序运行下去  每次申请100M空间
	{
		cnt++;
	}
	printf("%d00\n", cnt);

	system("pause");
	return 0;
}