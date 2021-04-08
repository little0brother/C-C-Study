#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* p = NULL;
	char* q = NULL;

	char buf[100] = "akfakdfjkdjsa";

	p = &buf[0];
	printf("p1=%d,%c\n", p, *p);

	p = &buf[1];
	printf("p2=%d,%c\n\n", p, *p);

	for (int i = 0; i < strlen(buf); i++)
	{
		//p = &buf[i];
		p = buf + i;
		printf("p3=%d,%c\n", p, *p);
	}



	q = (char*)malloc(100);
	if (q == NULL)
	{
		return 0;
	}

	strcpy(q, "fdagdafa");
	printf("\n\n");
	for (int i = 0; i < strlen(q); i++)
	{
		p = q + i;
		printf("%c ", *p);
	}

	printf("\n");
	return 0;
}