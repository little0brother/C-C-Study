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

//ɾ��ֵΪx�����н��
int SListNodeDelPro(Node *head, int x)
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

			pCur = pPre->next;

			//break;
			continue; //��������ѭ������Ҫ
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

//����ڵ�����
int SListNodeSort(Node *head)
{
	if(head == NULL || head->next == NULL)
	{
		return -1;
	}

#if 0
	int a[] = { 1, 5, 4, 7, 9, 0, 10, 9, 3, 8, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++) //for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				//
			}
		}
	}
#endif

	Node *pPre = NULL;
	Node *pCur = NULL;
	Node tmp;

	// pPre->next != NULL����������2�����
	for (pPre = head->next; pPre->next  != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			//ע�⣬���򣬳�����������Ҫ������nextָ�뻹��Ҫ����
			if (pPre->id > pCur->id) //����
			{

				//ֻ����������
				tmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = tmp.id;
#if 0
				//����������
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//����ָ������Ҫ��
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;
#endif
			}
		}
	}


	return 0;

}

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(Node *head, int x)
{
	//��֤����ǰ�������
	int ret = SListNodeSort(head);
	if (ret != 0)
	{
		return ret;
	}

	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;

	//1 2 3 5 6�� ����4
	//3��pre, 5: cur
	while (pCur != NULL)
	{
		if (pCur->id > x) //�ҵ���ƥ����
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
	pNew->id = x;
	pNew->next = NULL;

	//����ָ��λ��
	pPre->next = pNew; //pPre��һ��ָ��pNew
	pNew->next = pCur; //pNew��һ��ָ��pCur

	return 0;

	return 0;
}

//��ת����Ľڵ㣨���������Ƿ�ת��
//�������ָ�򷴹���
int SListNodeReverse(Node *head)
{
	if (head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return -1;
	}

	Node *pPre = head->next;
	Node *pCur = pPre->next;
	pPre->next = NULL;
	Node *tmp = NULL;

	while (pCur != NULL)
	{
		tmp = pCur->next;
		pCur->next = pPre;

		pPre = pCur;
		pCur = tmp;
	}

	//head->next->next = NULL;
	head->next = pPre;


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

	SListNodeDelPro(head, 5);
	printf("ɾ������5����\n");
	SListPrint(head);

	SListNodeSort(head);
	printf("�����\n");
	SListPrint(head);


	SListNodeInsertPro(head, 6);
	printf("�������6��\n");
	SListPrint(head);

	SListNodeReverse(head);
	printf("����ת��\n");
	SListPrint(head);



	SListNodeDestroy(head);
	head = NULL;


	printf("\n");
	system("pause");
	return 0;
}