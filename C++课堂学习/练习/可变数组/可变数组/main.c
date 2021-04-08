#include <stdio.h>
#include <stdlib.h>

const Block_size = 10;

typedef struct {
	int* array;
	int size;
} Array;

Array array_create(int init_size);
void array_free(Array *a);
int* array_size(Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

Array array_create(int init_size)
{
	Array a;
	a.array = (int*)malloc(sizeof(int) * init_size);
	a.size = init_size;

	return a;
}

void array_free(Array *a)
{
	free(a->array);
	a->array = NULL;
	a->size = 0;
}

int* array_size(Array *a)
{
	return a->size;
}

int* array_at(Array *a, int index)
{
	if (index >= a->size)
		array_inflate(a, (index / Block_size + 1) * Block_size - a->size);

	return &(a->array[index]);
}

void array_inflate(Array *a, int more_size)
{
	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));

	for (int i = 0; i < a->size; i++)
		p[i] = a->array[i];

	free(a->array);
	a->array = p;
	a->size = a->size + more_size;
}

int main()
{
	int number = 0, cnt = 0;
	Array a = array_create(5);

/*	printf("%d\n", array_size(&a));
	*array_at(&a, 0) = 10;
	printf("%d\n", *array_at(&a, 0));
*/

	while (number != -1) {
		scanf_s("%d", &number);

		if(number != -1)
		*array_at(&a, cnt++) = number;
	}

	for (int i = 0; i < cnt; i++)
		printf("%d ", a.array[i]);
	array_free(&a);

	system("pause");
	return 0;
}