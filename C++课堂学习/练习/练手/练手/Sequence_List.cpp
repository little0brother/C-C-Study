#include <iostream>
using namespace std;

#define DataType int					//定义顺序表的类型
#define Size 10							//定义顺序表的长度
#define AddSize 5						//定义顺序表每次增加的长度

typedef struct {
	DataType *data;						//顺序表的数据指针
	int len;							//顺序表当前的长度
	int size;							//顺序表已分配的大小
} SequenList;

void Initiate(SequenList *L)			//初始化操作
{ 
	L->data = new DataType[Size];		//申请数据的存储空间
	if (!(L->data))						//判断空间是否申请成功，失败退出程序
		exit(1);

	L->len = 0;							//初始化当前长度为0
	L->size = Size;						//初始化已分配的大小
}

int Length(SequenList *L)				//计算顺序表的长度
{ 
	return (L->len);
}

DataType Get(SequenList *L, int i)		//搜索当前位置的元素
{
	if (i < 1 || i > L->len)			//判断位置是否非法
		return (NULL);
	else
		return (L->data[i - 1]);		//返回当前元素
}

int Locate(SequenList *L, DataType x)	//搜索元素是否存在在表中，并返回元素所在位置
{
	int k;
	k = 1;
	while (k <= L->len && L->data[k - 1] != x)		//判断元素是否为当前位置元素
		k++;
	if (k <= L->len)
		return k;
	else
		return 0;
}

bool Dilatation(SequenList *L)			//扩容
{
	DataType *p = new DataType[L->size + AddSize];		//申请一块新内存空间，大小为：已分配空间的大小加上增量
	if (!p) {							//判断分配空间是否成功
		return false;
		exit(1);
	}

	for (int i = 0; i < L->len; i++)	//将原来链表中的数据搬移至心内存空间
		p[i] = L->data[i];

	delete[]L->data;					//释放原来就空间按
	L->data = p;						//将指针重新指向新的内存空间
	L->size += AddSize;					//改变已分配的大小
}

void Insert(SequenList *L, int i, DataType b)	//插入操作（进行操作的表，插入位置，插入的元素）
{
	int k;
	if (i < 1 || i > L->len + 1)		//判断插入位置是否在表中
		cout << "error";

	if (L->len >= L->size)				//判断表的长度是否够，不够则增加空间
		Dilatation(L);

	for (k = L->len; k >= i; k--)		//将插入位置的元素后移
		L->data[k] = L->data[k - 1];

	L->data[i - 1] = b;					//将元素放入表中
	L->len++;							//表的长度增加
}	

void Delete(SequenList *L, int i)		//删除选定位置的数据元素
{
	int k;
	if (i < 1 || i > L->len || L->len == 0)		//如果删除位置不在表中，或表为空失败
		cout << "error";
	else
	{
		for (k = i + 1; k <= L->len; k++)		//将删除位后的元素前移一位
			L->data[k - 2] = L->data[k - 1];
		L->len--;
	}
}

int Empty(SequenList *L)			//判断表是否为空
{
	if (L->len == 0)
		return 1;
	else
		return 0;
}

void Distory(SequenList *L)			//销毁表
{
	if (!L)
		cout << "NULL";

	delete[]L->data;				//释放空间
	L->len = 0;						//长度初始化为 0
	L->size = 0;					//已分配大小为0
}

void traverse_seqList(SequenList *L)		//遍历整个表
{
	if (!L)
		exit(1);

	for (int i = 0; i < L->len; i++)
		printf("%4d ", L->data[i]);
	cout << endl;
}

int main()
{
	SequenList L;				//定义顺序表
	Initiate(&L);				//进行初始化操作

	Insert(&L, 1, 1);
	Insert(&L, 1, 2);
	Insert(&L, 1, 3);
	Insert(&L, 1, 4);
	Insert(&L, 1, 5);
	Insert(&L, 1, 6);
	Insert(&L, 1, 7);
	Insert(&L, 1, 8);
	Insert(&L, 1, 9);
	Insert(&L, 1, 10);
	Insert(&L, 1, 11);
	Insert(&L, 1, 12);
	Insert(&L, 1, 13);
	traverse_seqList(&L);

	Delete(&L, 3);
	Delete(&L, 3);
	Delete(&L, 3);
	traverse_seqList(&L);

	cout << Get(&L, 11) << endl;
	cout << Length(&L) << endl;
	cout << Locate(&L, 14) << endl;

	/*Distory(&L);
	traverse_seqList(&L);*/

	system("pause");
}