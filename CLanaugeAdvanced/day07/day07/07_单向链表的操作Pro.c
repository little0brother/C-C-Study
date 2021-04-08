#include <stdio.h>

typedef struct Node
{
	int id;

	struct Node* next;	// ָ����
}Node;

// ����ͷ�ڵ�
// �����ͷ�ڵ��ַ�ɺ���ֵ����
Node* SListCreat()
{
	Node* head = NULL;

	// ͷ�ڵ���Ϊ��־�����洢��Ч����
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	// ��head�ĳ�Ա������ֵ
	head->id = 1;
	head->next = NULL;

	Node* pCur = head;
	Node* pNew = NULL;

	int data;

	while (1)
	{
		printf("����������:");
		scanf("%d", &data);

		if (data == -1)		// ����-1���˳�
		{
			break;
		}

		// �½ڵ㶯̬�����ڴ�ռ�
		pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			continue;
		}

		// ��pNew��Ա������ֵ
		pNew->id = data;
		pNew->next = NULL;

		// ��������ϵ

		// ��ǰ�ڵ�ָ��pNew
		pCur->next = pNew;

		// pNew��һ���ڵ�ָ��NULL
		pNew->next = NULL;

		// ��pCur�ƶ���pNew��pCurָ��pNew
		pCur = pNew;
	}

	return head;
}

//����ڵ�����
int SListNodeSort(Node* pHead)
{
	Node* pPre = pHead->next;
	Node* pCur = NULL;
	Node pTmp;

	// ð�ݷ�����
	// pPre != NULL   �������ڶ������
	while (pPre != NULL)
	{
		pCur = pPre->next;
		while (pCur != NULL)
		{
			if (pPre->id > pCur->id)
			{
				// ����������(ͬʱҲ������ָ�������ָ����ָ����ң����·�������һ��ָ����Ľ����Ϳ��Իָ�����)
				pTmp = *pPre;
				*pPre = *pCur;
				*pCur = pTmp;

				// ����ָ����
				pTmp.next = pPre->next;
				pPre->next = pCur->next;
				pCur->next = pTmp.next;
			}

			// ָ����һ��Ԫ��λ��
			pCur = pCur->next;
		}

		pPre = pPre->next;
	}

	return 0;
}

//����ڵ�����2 forѭ��
int SListNodeSort2(Node* pHead)
{
	Node* pPre = NULL;
	Node* pCur = NULL;
	Node pTmp;

	// ð�ݷ�����
	// pPre != NULL   �������ڶ������
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			if (pPre->id > pCur->id)
			{
				// ��Ϊֻ��һ��ֵ������ֻ����������
				pTmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = pTmp.id;

#if 0
				// ����������(ͬʱҲ������ָ�������ָ����ָ����ң����·�������һ��ָ����Ľ����Ϳ��Իָ�����)
				pTmp = *pPre;
				*pPre = *pCur;
				*pCur = pTmp;

				// ����ָ����
				pTmp.next = pPre->next;
				pPre->next = pCur->next;
				pCur->next = pTmp.next;
#endif
			}
		}
	}		

	return 0;
}

// ��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣬��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
int SListNodeInsert(Node* head, int x, int y)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* pPre = head;
	Node* pCur = head->next;

	while (pCur != NULL)
	{
		if (pCur->id == x)		// �ҵ���ƥ����
		{
			break;
		}

		pPre = pCur;	// pPerָ��pCurλ��
		pCur = pCur->next;  //pCurָ����һ�����
	}

	// 2�����
	// 1.�ҵ�ƥ��Ľ�㣬pCurΪƥ���㣬pPerΪpCur��һ�����
	// 2.û���ҵ�ƥ���㣬pCurΪ�ս�㣬pPerΪ���һ�����

	// ���½ڵ㶯̬����ռ�
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}

	// ��pNew��Ա������ֵ
	pNew->id = y;
	pNew->next = NULL;

	// ���뵽ָ��λ��
	pPre->next = pNew;	// pPre��һ��ָ��pNew
	pNew->next = pCur;	// pNew��һ��ָ��pCur

	return 0;
}

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(Node* pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	// ��֤����ǰ��������
	int ret = SListNodeSort(pHead);


	Node* pPre = pHead;
	Node* pCur = pHead->next;

	Node* pNew = (Node*)malloc(sizeof(Node));
	pNew->id = x;

	// 1 2 3 5 6, ����4
	// 3:pre, 5:cur
	while (pCur != NULL)
	{
		// ˳��ȶ�Ԫ�أ�����ҵ�λ�ã�������ѭ��
		if (pCur->id >= x)
		{
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	// �ı�ָ��ָ��
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;
}

//��ת����Ľڵ㣨���������Ƿ�ת��
int SListNodeReverse(Node* pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	Node* pPre = pHead;
	Node* pCur = pPre->next;
	Node* Next = pCur->next;

	// β���գ��ڶ��ַ�������Ϊ���ڵ�pPre��������ת������һ��Ԫ�أ�������nextָ��ָ��null
	pPre->next = NULL;

	while (pCur != NULL)
	{
		// �ݴ���һ�����
		Next = pCur->next;

		// �͵ط�ת
		pCur->next = pPre;

		pPre = pCur;
		pCur = Next;
	}

	// ѭ����Ϻ�pCurָ��λ��Ϊ����NULL��pPreΪ���һ����Чid��

	//printf("head->next:%d\n", *(pHead->next));
	//printf("head->next->next:%d\n", *(pHead->next->next));

	// pHead->next = node; ����node��ָ���Ѿ���ת��node->nextָ��head   node->next = head
	// pHead->next->next ==  head = null  // phead->next = node(node->next = head) pHead->next->next = (node->next = head)
	// β���(��Ϊ����ת���headָ��ָ��û�з����仯����head->next��ָ���Ѿ���ת������pHead->next->nextָ��ǰ)
	pHead->next->next = NULL;

	// ͷ�ڵ�
	pHead->next = pPre;

	return 0;
}

// ɾ����һ��ֵΪx�Ľ��
int SListNodeDel(Node* head, int x)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* pPre = head;
	Node* pCur = head->next;

	int flag = 0; // 0����û���ҵ���1�����ҵ�

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			// pPre����һ��ָ��pCur����һ��
			pPre->next = pCur->next;
			free(pCur);
			pCur == NULL;

			flag = 1;

			break;
		}

		pPre = pPre->next;	// pPerָ��pCurλ��
		pCur = pCur->next;  //pCurָ����һ�����
	}

	if (flag == 0)
	{
		printf("û��ֵΪ%d�Ľ��\n", x);
		return -2;
	}

	return 0;
}

//ɾ��ֵΪx�����н��
int SListNodeDelPro(Node* pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	Node* pPre = pHead;
	Node* pCur = pHead->next;

	while (pCur != NULL)
	{
		// ��������ʱ������ҵ�ֵ���������ͷź�ע��pPer->(pCur->next);��ִ��else�����ݣ��������ִ�лᵼ�¸�λ�����������������ֵ
		if (pCur->id == x)
		{
			pPre->next = pCur->next;

			free(pCur);

			pCur = pPre->next;
		}
		else
		{
			pPre = pCur;
			pCur = pCur->next;
		}
	}

	return 0;
}

//ɾ��ֵΪx�����н��
int SListNodeDelPro2(Node* head, int x)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* pPre = head;
	Node* pCur = head->next;

	int flag = 0; // 0����û���ҵ���1�����ҵ�

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			// pPre����һ��ָ��pCur����һ��
			pPre->next = pCur->next;
			free(pCur);
			pCur == NULL;

			flag = 1;

			pCur = pPre->next;

			continue; // ��ִ���·����
		}

		pPre = pPre->next;	// pPerָ��pCurλ��
		pCur = pCur->next;  //pCurָ����һ�����
	}

	if (flag == 0)
	{
		printf("û��ֵΪ%d�Ľ��\n", x);
		return -2;
	}

	return 0;
}

// ��������ͷ����н��
int SListNodeDestory(Node* head)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* tmp = NULL;
	int i = 0;

	while (head != NULL)
	{
		// ����head����һ�����
		tmp = head->next;
		free(head);

		// headָ��tmp
		head = tmp;

		i++;
	}

	printf("i = %d\n", i);

	return 0;
}

// ����ı���
int SListPrint(Node* head)
{
	if (head == NULL)
	{
		return -1;
	}

	// ȥ����һ����Ч�ڵ㣨ͷ�ڵ��next��
	Node* pCur = head->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		// �ѵ�ǰ�ڵ������ƶ�һλ��pCUrָ����һ��
		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;
}

int main()
{
	Node* pHead = SListCreat();

	int ret = 0;

	printf("\n������:\n");
	SListPrint(pHead);

	printf("����ֵ��:\n");
	ret = SListNodeInsert(pHead, 4, 3);
	if (ret != 0)
	{
		printf("SListNodeInsert err:%d\n", ret);
		return ret;
	}
	SListPrint(pHead);

	printf("���������:\n");
	SListNodeSort(pHead);
	SListPrint(pHead);

	printf("����˳���ֵ:\n");
	SListNodeInsertPro(pHead, 10);
	SListPrint(pHead);

	printf("��ת����:\n");
	SListNodeReverse(pHead);
	SListPrint(pHead);

	printf("ɾ����һ��ָ��ֵ��:\n");
	SListNodeDel(pHead, 8);
	SListPrint(pHead);

	printf("ɾ��������ֵͬ��:\n");
	SListNodeDelPro(pHead, 2);
	SListPrint(pHead);

	printf("�ͷ�����:\n");
	SListNodeDestory(pHead);
	pHead = NULL;
	SListPrint(pHead);

	return 0;
}