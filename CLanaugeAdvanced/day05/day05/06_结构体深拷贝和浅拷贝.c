#include <stdio.h>

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

// 浅拷贝触发条件：
// 1.结构体中嵌套指针，而且动态分配空间
// 2.同类型结构体变量赋值
// 3.不同结构体成员指针变量指向同一块内存
int main()
{
	Teacher t1;
	t1.name = (char*)malloc(30);
	strcpy(t1.name, "Alice");
	t1.age = 22;

	Teacher t2;

#if(0)
/*******************浅拷贝*****************************/
	// 浅拷贝
	t2 = t1;
	printf("[t2] %s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)
	{
		free(t1.name);
		t1.name = NULL;
	}

	// err 因为同一内存块释放了两次，导致内存出错
	//if (t2.name != NULL)
	//{
	//	free(t2.name);
	//	t2.name = NULL;
	//}
/***************************************************/
#endif

#if(1)
	/*******************深拷贝*****************************/

	t2 = t1;
	// 深拷贝, 人为增加内存，重新拷贝一次
	t2.name = (char*)malloc(30);
	strcpy(t2.name, t1.name);

	printf("[t2] %s, %d\n", t2.name, t2.age);

	if (t1.name != NULL)
	{
		free(t1.name);
		t1.name = NULL;
	}

	if (t2.name != NULL)
	{
		free(t2.name);
		t2.name = NULL;
	}
#endif

	return 0;
}