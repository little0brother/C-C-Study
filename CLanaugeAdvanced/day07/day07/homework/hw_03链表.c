/*
	//创建头节点，链表的头结点地址由函数值返回。
	SLIST* SListCreat();

	//遍历节点
	//顺序输出单向链表各项结点数据域中的内容
	int SListPrint(SLIST* pHead);

	//在值为x的结点前，插入值为y的结点；
	//若值为x的结点不存在，则插在表尾
	int SListNodeInsert(SLIST* pHead, int x, int y);

	//删除第一个值为x的结点
	int SListNodeDel(SLIST* pHead, int x);

	//释放所有节点
	int SListDestroy(SLIST* pHead);

	//删除值为x的所有结点
	int SListNodeDelPro(SLIST *pHead, int x);

	//链表节点排序
	int SListNodeSort(SLIST *pHead);
*/

#include <stdio.h>

typedef struct SLIST
{
	int id;
	struct SLIST* next;
}SLIST;

/* 头节点不存储任何数据，仅为链表开头 */

//创建头节点，链表的头结点地址由函数值返回
SLIST* SListCreat()
{
	SLIST* pHead = NULL;

	// 头节点不存储任何有效数据，仅作为开头
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

		// 创建新结点
		pNew = (SLIST*)malloc(sizeof(SLIST));
		pNew->id = data;

		// 当前结点指向新节点，并给新节点的下一个结点赋为NULL
		pCur->next = pNew;
		pNew->next = NULL;

		// 当前结点指向新结点
		pCur = pNew;
	}

	return pHead;
}

//链表节点排序
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
				// 交换数据域(同时也交换了指针域，造成指针域指向混乱，在下方重新做一次指针域的交换就可以恢复正常)
				pTmp = *pPre;
				*pPre = *pCur;
				*pCur = pTmp;

				// 交换指针域
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

//在值为x的结点前，插入值为y的结点；
//若值为x的结点不存在，则插在表尾
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

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
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
		// 顺序比对元素，如果找到位置，则跳出
		if (pCur->id >= x)
		{
			break;
		}

		pPre = pCur;
		pCur = pCur->next;
	}

	// 改变指针指向
	pPre->next = pNew;
	pNew->next = pCur;

	return 0;
}

//翻转链表的节点（不是排序，是翻转）
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
		// 暂存下一个结点
		Next = pCur->next;

		// 就地反转
		pCur->next = pPre;

		pPre = pCur;
		pCur = Next;
	}

	// 循环完毕后，pCur指向位置为最后的NULL，pPre为最后一个有效id，

	//printf("head->next:%d\n", *(pHead->next));
	//printf("head->next->next:%d\n", *(pHead->next->next));

	// pHead->next = node; 但是node的指向已经翻转，node->next指向head   node->next = head
	// pHead->next->next ==  head = null  // phead->next = node(node->next = head) pHead->next->next = (node->next = head)
	// 尾结点(因为链表翻转完后，head指针指向还没有发生变化，但head->next的指向已经翻转，所以pHead->next->next指向当前)
	pHead->next->next = NULL;
	
	// 头节点
	pHead->next = pPre;

	return 0;
}

//删除第一个值为x的结点
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
		printf("没有值为%d的id\n", x);
	}

	return 0;
}

//删除值为x的所有结点
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
		// 遍历链表时，如果找到值，并进行释放后，注意pPer->(pCur->next);不执行else中内容，如果连续执行会导致隔位搜索，不能清除连续值
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

//释放所有节点
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
		// 临时存储 当前的下一个结点
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

	// 去除第一个无效结点
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

	printf("\n创建后:\n");
	SListPrint(pHead);

	printf("插入值后:\n");
	ret = SListNodeInsert(pHead, 4, 3);
	if (ret != 0)
	{
		printf("SListNodeInsert err:%d\n", ret);
		return ret;
	}
	SListPrint(pHead);

	printf("升序排序后:\n");
	SListNodeSort(pHead);
	SListPrint(pHead);

	printf("按照顺序插值:\n");
	SListNodeInsertPro(pHead, 5);
	SListPrint(pHead);

	printf("翻转链表:\n");
	SListNodeReverse(pHead);
	SListPrint(pHead);

	printf("删除第一个指定值后:\n");
	SListNodeDel(pHead, 8);
	SListPrint(pHead);

	printf("删除所有相同值后:\n");
	SListNodeDelPro(pHead, 2);
	SListPrint(pHead);

	printf("释放链表:\n");
	SListDestroy(pHead);
	pHead = NULL;
	SListPrint(pHead);

	return 0;
}