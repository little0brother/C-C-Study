#include <iostream>
#include <iomanip>
using namespace std;

#define Datatype int				//定义栈的数据类型
#define Size 10						//定义栈初始长度
#define AddSize 5					//定义增量

typedef struct {
	Datatype *data;					//定义数据存储的区域
	int top;						//记录栈顶位置
	int StackSize;					//记录栈当前大小
}SequenceStack;

void Init_Stack(SequenceStack *S)	//初始化
{
	S->data = new Datatype[Size];	//申请数据存储内存空间
	if (!(S->data))
		cout << "error";

	S->top = -1;					//初始化栈顶位置
	S->StackSize = Size;			//初始化栈的大小
}

int Stack_Length(SequenceStack *S)	//计算栈的长度
{
	return (S->top + 1);
}

void Clean_Stack(SequenceStack *S)	//清除栈
{
	S->top = -1;
}

Datatype Gettop_Stack(SequenceStack *S)	//栈顶元素
{
	if (S->top == -1)
		cout << "Stack empty!";

	Datatype elem = S->data[S->top];	//将栈顶元素取出

	return elem;
}

bool Stack_Empty(SequenceStack *S)		//判断栈是否为空
{
	if (S->top == -1)
		return false;
	else
		return true;
}

bool Increment(SequenceStack * S)		//扩容
{
	Datatype *AS = new Datatype[S->StackSize + AddSize];	//申请新的内存空间，大小为栈的当前大小加上增量
	if (!AS)
		return false;

	for (int i = 0; i <= S->top; i++)		//将老栈的元素复制到新的内存空间
		AS[i] = S->data[i];

	delete[]S->data;				//释放老栈空间
	S->data = AS;					//将数据指向新的内存块
	S->StackSize += AddSize;		//栈的大小为原大小加上增量
	return true;
}

void Push_Stack(SequenceStack *S, Datatype elem)	//入栈
{
	if ((S->top) == (S->StackSize - 1))		//判断栈是否已满
		Increment(S);

	S->top++;
	S->data[S->top] = elem;
}

Datatype Pop_Stack(SequenceStack *S)		//出栈
{
	Datatype elem; 

	if (S->top == -1)
		cout << "Stack empty!";
	else
		elem = S->data[--S->top];		//将栈顶元素赋给elem，栈顶下移
	
	return elem;
}

void Distory_Stack(SequenceStack *S)	//销毁栈
{
	if (S->top == -1)					//判断栈是否为空
		cout << "Stack emety";

	delete[] S->data;				//释放存储空间
	S->StackSize = 0;				//大小至为零
	S->top = -1;					//栈顶元素重新指向-1
}

void Traverse_SeqStack(SequenceStack *S)	//遍历
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

	cout << "栈顶元素：" << Gettop_Stack(&stack) << endl;

	Clean_Stack(&stack);
	Traverse_SeqStack(&stack);

	Distory_Stack(&stack);
	Traverse_SeqStack(&stack);

	system("pause");
	return 0;
}