#include <iostream>
#include <iomanip>
using namespace std;

#define Datatype int				//����ջ����������
#define Size 10						//����ջ��ʼ����
#define AddSize 5					//��������

typedef struct {
	Datatype *data;					//�������ݴ洢������
	int top;						//��¼ջ��λ��
	int StackSize;					//��¼ջ��ǰ��С
}SequenceStack;

void Init_Stack(SequenceStack *S)	//��ʼ��
{
	S->data = new Datatype[Size];	//�������ݴ洢�ڴ�ռ�
	if (!(S->data))
		cout << "error";

	S->top = -1;					//��ʼ��ջ��λ��
	S->StackSize = Size;			//��ʼ��ջ�Ĵ�С
}

int Stack_Length(SequenceStack *S)	//����ջ�ĳ���
{
	return (S->top + 1);
}

void Clean_Stack(SequenceStack *S)	//���ջ
{
	S->top = -1;
}

Datatype Gettop_Stack(SequenceStack *S)	//ջ��Ԫ��
{
	if (S->top == -1)
		cout << "Stack empty!";

	Datatype elem = S->data[S->top];	//��ջ��Ԫ��ȡ��

	return elem;
}

bool Stack_Empty(SequenceStack *S)		//�ж�ջ�Ƿ�Ϊ��
{
	if (S->top == -1)
		return false;
	else
		return true;
}

bool Increment(SequenceStack * S)		//����
{
	Datatype *AS = new Datatype[S->StackSize + AddSize];	//�����µ��ڴ�ռ䣬��СΪջ�ĵ�ǰ��С��������
	if (!AS)
		return false;

	for (int i = 0; i <= S->top; i++)		//����ջ��Ԫ�ظ��Ƶ��µ��ڴ�ռ�
		AS[i] = S->data[i];

	delete[]S->data;				//�ͷ���ջ�ռ�
	S->data = AS;					//������ָ���µ��ڴ��
	S->StackSize += AddSize;		//ջ�Ĵ�СΪԭ��С��������
	return true;
}

void Push_Stack(SequenceStack *S, Datatype elem)	//��ջ
{
	if ((S->top) == (S->StackSize - 1))		//�ж�ջ�Ƿ�����
		Increment(S);

	S->top++;
	S->data[S->top] = elem;
}

Datatype Pop_Stack(SequenceStack *S)		//��ջ
{
	Datatype elem; 

	if (S->top == -1)
		cout << "Stack empty!";
	else
		elem = S->data[--S->top];		//��ջ��Ԫ�ظ���elem��ջ������
	
	return elem;
}

void Distory_Stack(SequenceStack *S)	//����ջ
{
	if (S->top == -1)					//�ж�ջ�Ƿ�Ϊ��
		cout << "Stack emety";

	delete[] S->data;				//�ͷŴ洢�ռ�
	S->StackSize = 0;				//��С��Ϊ��
	S->top = -1;					//ջ��Ԫ������ָ��-1
}

void Traverse_SeqStack(SequenceStack *S)	//����
{
	if (S->top == -1)
		cout << "Stack empty!";
	
	for (int i = 0; i <= S->top; i++)
		cout << setw(4) << S->data[i];
	cout << endl;
}

int main()
{
	SequenceStack stack;
	Init_Stack(&stack);

	Push_Stack(&stack, 1);
	Push_Stack(&stack, 2);
	Push_Stack(&stack, 3);
	Push_Stack(&stack, 4);
	Push_Stack(&stack, 5);
	Push_Stack(&stack, 6);
	Push_Stack(&stack, 7);
	Push_Stack(&stack, 8);
	Push_Stack(&stack, 9);
	Push_Stack(&stack, 10);
	Push_Stack(&stack, 11);
	Push_Stack(&stack, 12);
	Traverse_SeqStack(&stack);

	Pop_Stack(&stack);
	Traverse_SeqStack(&stack);
	Pop_Stack(&stack);
	Traverse_SeqStack(&stack);

	Push_Stack(&stack, 7);
	Push_Stack(&stack, 9);
	Traverse_SeqStack(&stack);

	cout << "ջ��Ԫ�أ�" << Gettop_Stack(&stack) << endl;

	Clean_Stack(&stack);
	Traverse_SeqStack(&stack);

	Distory_Stack(&stack);
	Traverse_SeqStack(&stack);

	system("pause");
	return 0;
}