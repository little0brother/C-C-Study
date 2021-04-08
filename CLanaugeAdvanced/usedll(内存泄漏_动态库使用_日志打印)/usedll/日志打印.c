#include <stdio.h>
#include "itcastlog.h"

int main()
{
	printf("file=%s\nline=%d\n", __FILE__, __LINE__);

	int a = 10;
	ITCAST_LOG(__FILE__, __LINE__, 4, -2, "a=%d\n", a);

	return 0;
}