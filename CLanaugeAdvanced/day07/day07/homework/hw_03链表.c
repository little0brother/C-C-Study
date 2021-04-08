/*
	//����ͷ�ڵ㣬�����ͷ����ַ�ɺ���ֵ���ء�
	SLIST* SListCreat();

	//�����ڵ�
	//˳�������������������������е�����
	int SListPrint(SLIST* pHead);

	//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
	//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
	int SListNodeInsert(SLIST* pHead, int x, int y);

	//ɾ����һ��ֵΪx�Ľ��
	int SListNodeDel(SLIST* pHead, int x);

	//�ͷ����нڵ�
	int SListDestroy(SLIST* pHead);

	//ɾ��ֵΪx�����н��
	int SListNodeDelPro(SLIST *pHead, int x);

	//����ڵ�����
	int SListNodeSort(SLIST *pHead);
*/

#include <stdio.h>

typedef struct SLIST
{
	int id;
	struct SLIST* next;
}SLIST;

/* ͷ�ڵ㲻�洢�κ����ݣ���Ϊ����ͷ */

//����ͷ�ڵ㣬�����ͷ����ַ�ɺ���ֵ����
SLIST* SListCreat()
{
	SLIST* pHead = NULL;

	// ͷ�ڵ㲻�洢�κ���Ч���ݣ�����Ϊ��ͷ
	pHead = (SLIST*)malloc(sizeof(SLIST));

	SLIST* pCur = pHead;
	SLIST* pNew = NULL;

	int data;

	while (1)
	{
		printf("please input num(-1 type end):");
		scanf("%d", &data);

		if (data == -1)
		{
			break;
		}

		// �����½��
		pNew = (SLIST*)malloc(sizeof(SLIST));
		pNew->id = data;

		// ��ǰ���ָ���½ڵ㣬�����½ڵ����һ����㸳ΪNULL
		pCur->next = pNew;
		pNew->next = NULL;

		// ��ǰ���ָ���½��
		pCur = pNew;
	}

	return pHead;
}

//����ڵ�����
int SListNodeSort(SLIST* pHead)
{
	SLIST* pPre = pHead->next;
	SLIST* pCur = NULL;
	SLIST pTmp;

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

			pCur = pCur->next;
		}

		pPre = pPre->next;
	}

	return 0;
}

//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
int SListNodeInsert(SLIST* pHead, int x, int y)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST* pPer = pHead;
	SLIST* pCur = pHead->next;

	SLIST* pNew = (SLIST*)malloc(sizeof(SLIST));
	pNew->id = y;
	pNew->next = NULL;

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			break;
		}

		pPer = pCur;
		pCur = pCur->next;
	}

	pPer->next = pNew;
	pNew->next = pCur;

	return 0;
}

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(SLIST* pHead, int x)
{
	if (pHead == NULL)
	{
		return - 1;
	}

	SLIST* pPre = pHead;
	SLIST* pCur = pHead->next;

	SLIST* pNew = (SLIST*)malloc(sizeof(SLIST));
	pNew->id = x;

	while (pCur != NULL)
	{
		// ˳��ȶ�Ԫ�أ�����ҵ�λ�ã�������
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
int SListNodeReverse(SLIST* pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST* pPre = pHead;
	SLIST* pCur = pPre->next;
	SLIST* Next = pCur->next;

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

//ɾ����һ��ֵΪx�Ľ��
int SListNodeDel(SLIST* pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST* pPre = pHead;
	SLIST* pCur = pHead->next;

	int flag = 0;

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			pPre->next = pCur->next;

			free(pCur);
			pCur = NULL;

			flag = 1;

			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	if (flag == 0)
	{
		printf("û��ֵΪ%d��id\n", x);
	}

	return 0;
}

//ɾ��ֵΪx�����н��
int SListNodeDelPro(SLIST* pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST* pPre = pHead;
	SLIST* pCur = pHead->next;

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

//�ͷ����нڵ�
int SListDestroy(SLIST* pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST* tmp = NULL;

	int count = 0;

	while (pHead != NULL)
	{
		// ��ʱ�洢 ��ǰ����һ�����
		tmp = pHead->next;

		free(pHead);

		pHead = tmp;

		count++;
	}

	printf("count: %d\n", count);

	return 0;
}

int SListPrint(SLIST* pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	// ȥ����һ����Ч���
	SLIST* pCur = pHead->next;

	printf("head ->");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;
}

int main()
{
	SLIST* pHead = SListCreat();

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
	SListNodeInsertPro(pHead, 5);
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
	SListDestroy(pHead);
	pHead = NULL;
	SListPrint(pHead);

	return 0;
}