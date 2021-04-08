#include <iostream>
#include <iomanip>
using namespace std;

#define Datatype int						//定义数据类型
#define MaxSize 10							//定义队列长度

typedef struct {
	Datatype *data;							//定义数据存储
	int front;								//队列头
	int rear;								//队列尾
} CirQueue;

void Init_Queue(CirQueue *Q)				//初始化函数
{
	Q->data = new Datatype[MaxSize];		//申请数据存储区域
	if (!(Q->data))
		cout << "failde";

	Q->front = 0;							//队列头初始化
	Q->rear  = 0;							//队列尾初始化
}

bool Queue_Empty(CirQueue *Q)				//队列是否为空
{
	if (Q->front == Q->rear)				//队头、队尾指向同一位置，队列为空
		return true;
	else
		return false;
}

void Clean_Queue(CirQueue *Q)				//清空队列
{
	Q->front = Q->rear = 0;
}

int Queue_Length(CirQueue *Q)				//计算队列长度
{
	int len;
	len = (Q->rear - Q->front + MaxSize) % MaxSize;		//长度为“（队尾 - 队头 + 队列长度） % 队列长度”

	return len;
}

void Add_Queue(CirQueue *Q, Datatype elem)				//像队列中填加元素
{
	if ((Q->rear + 1) % MaxSize == Q->front)			//判断队列是否满
		cout << "Overflow" << endl;
	else
	{
		Q->data[Q->rear] = elem;						//写入元素
		Q->rear = (Q->rear + 1) % MaxSize;				//移动队尾指针
	}
}

void Del_Queue(CirQueue *Q, Datatype *elem)				//删除队列元素
{
	if (Queue_Empty(Q))
		cout << "Quene empty!";
	else
	{
		*elem = Q->data[Q->front];						//将删除的队头元素赋给elem
		Q->front = (Q->front + 1) % MaxSize;
	}
}

void Gethead_Queue(CirQueue *Q, Datatype *elem)			//获得队列头部元素
{
	if (Queue_Empty(Q))
		cout << "Queue empty!";
	else
		*elem = Q->data[(Q->front) % MaxSize];		//取队列头部元素
}

bool Distory_Queue(CirQueue *Q)						//销毁队列
{
	if (Queue_Empty(Q))
		return false;
	
	delete[] Q->data;								//释放数据存储地址
	Q->front = Q->rear = 0;							//队列头指向队列首
	return true;
}

void Traverse_queue(CirQueue *Q)					//遍历队列
{
	if (Queue_Empty(Q))
		cout << "Queue empty!" << endl;

	else 
	{
		for (int i = Q->front; i != Q->rear; i = (i + 1) % MaxSize)		//将I指向队列首，I！=队尾
			cout << setw(4) << Q->data[i];			//输出数据占四位宽度
		cout << endl;
	}
}

int main()
{
	CirQueue queue;
	Init_Queue(&queue);

	Add_Queue(&queue, 1);
	Add_Queue(&queue, 2);
	Add_Queue(&queue, 3);
	Add_Queue(&queue, 4);
	Add_Queue(&queue, 5);
	Add_Queue(&queue, 6);
	Add_Queue(&queue, 7);
	Add_Queue(&queue, 8);
	Add_Queue(&queue, 9);
	//Add_Queue(&queue, 10);
	//Add_Queue(&queue, 11);
	Traverse_queue(&queue);

	cout << "length:" << Queue_Length(&queue) << endl;

	Datatype elem;
	Gethead_Queue(&queue, &elem);
	cout << "Head:" << elem << endl;

	Del_Queue(&queue, &elem);
	Del_Queue(&queue, &elem);
	Traverse_queue(&queue);

	Add_Queue(&queue, 1);
	Add_Queue(&queue, 2);
	Add_Queue(&queue, 3);
	Traverse_queue(&queue);

	Distory_Queue(&queue);

	system("pause");
	return 0;
}
