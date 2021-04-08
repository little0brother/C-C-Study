#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;
	struct Node *next; //ָ����
}Node;

//����ͷ���
//�����ͷ����ַ�ɺ���ֵ���ء�
Node *SListCreat()
{
	Node *head = NULL;

	//ͷ�����Ϊ��־�����洢��Ч����
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//��head�ĳ�Ա������ֵ
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;

	while (1)
	{
		printf("���������ݣ�");
		scanf("%d", &data);

		if (data == -1) //����-1���˳�
		{
			break;
		}

		//�½�㶯̬����ռ�
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			//continue;
			break;
		}
		 
		//��pNew��Ա������ֵ
		pNew->id = data;
		pNew->next = NULL;

		//��������ϵ

		//��ǰ����nextָ��pNew
		pCur->next = pNew;

		//pNew��һ�����ָ��NULL
		pNew->next = NULL;

		//��pCur�ƶ���pNew,pCurָ��pNew
		pCur = pNew;
	}


	return head;
}

//����ı���
int SListPrint(Node * head)
{
	if (head == NULL)
	{
		return -1;
	}

	//ȡ����һ����Ч��㣨ͷ����next��
	Node *pCur = head->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		//��ǰ��������ƶ�һλ��pCurָ����һ��
		pCur = pCur->next;
	}
	printf("NULL\n");


	return 0;
}

//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻��ֵΪx�Ľ�㲻���ڣ�����ڱ�β��
int SListNodeInsert(Node * head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x) //�ҵ���ƥ����
		{
			break;
		}
		
		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next; //pCurָ����һ�����

	}

	//2�����
	//1. ��ƥ��Ľ�㣬pCurΪƥ���㣬pPreΪpCur��һ�����
	//2. û���ҵ�ƥ���㣬pCurΪ�ս�㣬pPreΪ���һ�����

	//���½�㶯̬����ռ�
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}
	//��pNew�ĳ�Ա������ֵ
	pNew->id = y;
	pNew->next = NULL;

	//����ָ��λ��
	pPre->next = pNew; //pPre��һ��ָ��pNew
	pNew->next = pCur; //pNew��һ��ָ��pCur

	return 0;
}

//ɾ����һ��ֵΪx�Ľ��
int SListNodeDel(Node *head, int x)
{

	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0; //0û���ң�1�ҵ�

	while (pCur != NULL)
	{
		if (pCur->id == x) //�ҵ���ƥ����
		{
			//pPre����һ��ָ��pCur����һ��
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;


			break;
		}

		//pPreָ��pCurλ��
		pPre = pCur;
		pCur = pCur->next; //pCurָ����һ�����

	}

	if (0 == flag)
	{
		printf("û��ֵΪ%d�Ľ��\n", x);
		return -2;
	}

	return 0;
}

//��������ͷ����н��
int SListNodeDestroy(Node *head)
{
	if (head == NULL)
	{
		return -1;
	}

	Node * tmp = NULL;
	int i = 0;

	while (head != NULL)
	{
		//����head����һ�����
		tmp = head->next;
		free(head);
		head = NULL;
		
		//headָ��tmp
		head = tmp;
		i++;
	}

	printf("i = %d \n", i);


	return 0;
}

int main(void)
{
	Node *head = NULL;
	
	head = SListCreat();//����ͷ���
	SListPrint(head);



	SListNodeInsert(head, 5, 4);
	printf("��5��ǰ�����4��\n");
	SListPrint(head);

	SListNodeDel(head, 5);
	printf("ɾ��5����\n");
	SListPrint(head);

	SListNodeDestroy(head);
	head = NULL;


	printf("\n");
	system("pause");
	return 0;
}