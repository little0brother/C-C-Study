#include <iostream>
#include <iomanip>
using namespace std;

#define Datatype int						//������������
#define MaxSize 10							//������г���

typedef struct {
	Datatype *data;							//�������ݴ洢
	int front;								//����ͷ
	int rear;								//����β
} CirQueue;

void Init_Queue(CirQueue *Q)				//��ʼ������
{
	Q->data = new Datatype[MaxSize];		//�������ݴ洢����
	if (!(Q->data))
		cout << "failde";

	Q->front = 0;							//����ͷ��ʼ��
	Q->rear  = 0;							//����β��ʼ��
}

bool Queue_Empty(CirQueue *Q)				//�����Ƿ�Ϊ��
{
	if (Q->front == Q->rear)				//��ͷ����βָ��ͬһλ�ã�����Ϊ��
		return true;
	else
		return false;
}

void Clean_Queue(CirQueue *Q)				//��ն���
{
	Q->front = Q->rear = 0;
}

int Queue_Length(CirQueue *Q)				//������г���
{
	int len;
	len = (Q->rear - Q->front + MaxSize) % MaxSize;		//����Ϊ������β - ��ͷ + ���г��ȣ� % ���г��ȡ�

	return len;
}

void Add_Queue(CirQueue *Q, Datatype elem)				//����������Ԫ��
{
	if ((Q->rear + 1) % MaxSize == Q->front)			//�ж϶����Ƿ���
		cout << "Overflow" << endl;
	else
	{
		Q->data[Q->rear] = elem;						//д��Ԫ��
		Q->rear = (Q->rear + 1) % MaxSize;				//�ƶ���βָ��
	}
}

void Del_Queue(CirQueue *Q, Datatype *elem)				//ɾ������Ԫ��
{
	if (Queue_Empty(Q))
		cout << "Quene empty!";
	else
	{
		*elem = Q->data[Q->front];						//��ɾ���Ķ�ͷԪ�ظ���elem
		Q->front = (Q->front + 1) % MaxSize;
	}
}

void Gethead_Queue(CirQueue *Q, Datatype *elem)			//��ö���ͷ��Ԫ��
{
	if (Queue_Empty(Q))
		cout << "Queue empty!";
	else
		*elem = Q->data[(Q->front) % MaxSize];		//ȡ����ͷ��Ԫ��
}

bool Distory_Queue(CirQueue *Q)						//���ٶ���
{
	if (Queue_Empty(Q))
		return false;
	
	delete[] Q->data;								//�ͷ����ݴ洢��ַ
	Q->front = Q->rear = 0;							//����ͷָ�������
	return true;
}

void Traverse_queue(CirQueue *Q)					//��������
{
	if (Queue_Empty(Q))
		cout << "Queue empty!" << endl;

	else 
	{
		for (int i = Q->front; i != Q->rear; i = (i + 1) % MaxSize)		//��Iָ������ף�I��=��β
			cout << setw(4) << Q->data[i];			//�������ռ��λ���
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
