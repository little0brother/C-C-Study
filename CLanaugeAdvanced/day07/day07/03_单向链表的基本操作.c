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

// ɾ����һ��ֵΪx�Ľ��
int SlistNodeDel(Node* head, int x)
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
	Node* head = NULL;

	head = SListCreat();	// ����ͷ�ڵ�
	SListPrint(head);

	SListNodeInsert(head, 5, 4); // ������
	printf("\n��5��ǰ�����4��\n");
	SListPrint(head);

	SlistNodeDel(head, 5);	// ɾ���ڵ�
	printf("ɾ��5����\n");
	SListPrint(head);

	SListNodeDestory(head);
	head = NULL;
	printf("�ͷ����н���\n");
	SListPrint(head);

	return 0;
}