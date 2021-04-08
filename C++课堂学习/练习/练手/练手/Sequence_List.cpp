#include <iostream>
using namespace std;

#define DataType int					//����˳��������
#define Size 10							//����˳���ĳ���
#define AddSize 5						//����˳���ÿ�����ӵĳ���

typedef struct {
	DataType *data;						//˳��������ָ��
	int len;							//˳���ǰ�ĳ���
	int size;							//˳����ѷ���Ĵ�С
} SequenList;

void Initiate(SequenList *L)			//��ʼ������
{ 
	L->data = new DataType[Size];		//�������ݵĴ洢�ռ�
	if (!(L->data))						//�жϿռ��Ƿ�����ɹ���ʧ���˳�����
		exit(1);

	L->len = 0;							//��ʼ����ǰ����Ϊ0
	L->size = Size;						//��ʼ���ѷ���Ĵ�С
}

int Length(SequenList *L)				//����˳���ĳ���
{ 
	return (L->len);
}

DataType Get(SequenList *L, int i)		//������ǰλ�õ�Ԫ��
{
	if (i < 1 || i > L->len)			//�ж�λ���Ƿ�Ƿ�
		return (NULL);
	else
		return (L->data[i - 1]);		//���ص�ǰԪ��
}

int Locate(SequenList *L, DataType x)	//����Ԫ���Ƿ�����ڱ��У�������Ԫ������λ��
{
	int k;
	k = 1;
	while (k <= L->len && L->data[k - 1] != x)		//�ж�Ԫ���Ƿ�Ϊ��ǰλ��Ԫ��
		k++;
	if (k <= L->len)
		return k;
	else
		return 0;
}

bool Dilatation(SequenList *L)			//����
{
	DataType *p = new DataType[L->size + AddSize];		//����һ�����ڴ�ռ䣬��СΪ���ѷ���ռ�Ĵ�С��������
	if (!p) {							//�жϷ���ռ��Ƿ�ɹ�
		return false;
		exit(1);
	}

	for (int i = 0; i < L->len; i++)	//��ԭ�������е����ݰ��������ڴ�ռ�
		p[i] = L->data[i];

	delete[]L->data;					//�ͷ�ԭ���Ϳռ䰴
	L->data = p;						//��ָ������ָ���µ��ڴ�ռ�
	L->size += AddSize;					//�ı��ѷ���Ĵ�С
}

void Insert(SequenList *L, int i, DataType b)	//������������в����ı�����λ�ã������Ԫ�أ�
{
	int k;
	if (i < 1 || i > L->len + 1)		//�жϲ���λ���Ƿ��ڱ���
		cout << "error";

	if (L->len >= L->size)				//�жϱ�ĳ����Ƿ񹻣����������ӿռ�
		Dilatation(L);

	for (k = L->len; k >= i; k--)		//������λ�õ�Ԫ�غ���
		L->data[k] = L->data[k - 1];

	L->data[i - 1] = b;					//��Ԫ�ط������
	L->len++;							//��ĳ�������
}	

void Delete(SequenList *L, int i)		//ɾ��ѡ��λ�õ�����Ԫ��
{
	int k;
	if (i < 1 || i > L->len || L->len == 0)		//���ɾ��λ�ò��ڱ��У����Ϊ��ʧ��
		cout << "error";
	else
	{
		for (k = i + 1; k <= L->len; k++)		//��ɾ��λ���Ԫ��ǰ��һλ
			L->data[k - 2] = L->data[k - 1];
		L->len--;
	}
}

int Empty(SequenList *L)			//�жϱ��Ƿ�Ϊ��
{
	if (L->len == 0)
		return 1;
	else
		return 0;
}

void Distory(SequenList *L)			//���ٱ�
{
	if (!L)
		cout << "NULL";

	delete[]L->data;				//�ͷſռ�
	L->len = 0;						//���ȳ�ʼ��Ϊ 0
	L->size = 0;					//�ѷ����СΪ0
}

void traverse_seqList(SequenList *L)		//����������
{
	if (!L)
		exit(1);

	for (int i = 0; i < L->len; i++)
		printf("%4d ", L->data[i]);
	cout << endl;
}

int main()
{
	SequenList L;				//����˳���
	Initiate(&L);				//���г�ʼ������

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