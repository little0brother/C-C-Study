#include <stdio.h>

typedef struct Node
{
	int id;

	struct Node* next;	// 指针域
}Node;

// 创建头节点
// 链表的头节点地址由函数值返回
Node* SListCreat()
{
	Node* head = NULL;

	// 头节点作为标志，不存储有效数据
	head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	// 给head的成员变量赋值
	head->id = 1;
	head->next = NULL;

	Node* pCur = head;
	Node* pNew = NULL;

	int data;

	while (1)
	{
		printf("请输入数据:");
		scanf("%d", &data);

		if (data == -1)		// 输入-1，退出
		{
			break;
		}

		// 新节点动态分配内存空间
		pNew = (Node*)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			continue;
		}

		// 给pNew成员变量赋值
		pNew->id = data;
		pNew->next = NULL;

		// 链表建立关系

		// 当前节点指向pNew
		pCur->next = pNew;

		// pNew下一个节点指向NULL
		pNew->next = NULL;

		// 把pCur移动到pNew，pCur指向pNew
		pCur = pNew;
	}

	return head;
}

//链表节点排序
int SListNodeSort(Node* pHead)
{
	Node* pPre = pHead->next;
	Node* pCur = NULL;
	Node pTmp;

	// 冒泡法排序
	// pPre != NULL   链表倒数第二个结点
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

			// 指向下一个元素位置
			pCur = pCur->next;
		}

		pPre = pPre->next;
	}

	return 0;
}

//链表节点排序2 for循环
int SListNodeSort2(Node* pHead)
{
	Node* pPre = NULL;
	Node* pCur = NULL;
	Node pTmp;

	// 冒泡法排序
	// pPre != NULL   链表倒数第二个结点
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			if (pPre->id > pCur->id)
			{
				// 因为只有一个值，所以只交换数据域
				pTmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = pTmp.id;

#if 0
				// 交换数据域(同时也交换了指针域，造成指针域指向混乱，在下方重新做一次指针域的交换就可以恢复正常)
				pTmp = *pPre;
				*pPre = *pCur;
				*pCur = pTmp;

				// 交换指针域
				pTmp.next = pPre->next;
				pPre->next = pCur->next;
				pCur->next = pTmp.next;
#endif
			}
		}
	}		

	return 0;
}

// 在值为x的结点前，插入值为y的结点，若值为x的结点不存在，则插在表尾
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
		if (pCur->id == x)		// 找到了匹配结点
		{
			break;
		}

		pPre = pCur;	// pPer指向pCur位置
		pCur = pCur->next;  //pCur指向下一个结点
	}

	// 2中情况
	// 1.找到匹配的结点，pCur为匹配结点，pPer为pCur上一个结点
	// 2.没有找到匹配结点，pCur为空结点，pPer为最后一个结点

	// 给新节点动态分配空间
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}

	// 给pNew成员变量赋值
	pNew->id = y;
	pNew->next = NULL;

	// 插入到指定位置
	pPre->next = pNew;	// pPre下一个指向pNew
	pNew->next = pCur;	// pNew下一个指向pCur

	return 0;
}

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(Node* pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	// 保证插入前链表有序
	int ret = SListNodeSort(pHead);


	Node* pPre = pHead;
	Node* pCur = pHead->next;

	Node* pNew = (Node*)malloc(sizeof(Node));
	pNew->id = x;

	// 1 2 3 5 6, 插入4
	// 3:pre, 5:cur
	while (pCur != NULL)
	{
		// 顺序比对元素，如果找到位置，则跳出循环
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
int SListNodeReverse(Node* pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	Node* pPre = pHead;
	Node* pCur = pPre->next;
	Node* Next = pCur->next;

	// 尾结点空，第二种方法，因为现在的pPre会是链表反转后的最后一个元素，所以让next指针指向null
	pPre->next = NULL;

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

// 删除第一个值为x的结点
int SListNodeDel(Node* head, int x)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* pPre = head;
	Node* pCur = head->next;

	int flag = 0; // 0代表没有找到，1代表找到

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			// pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur == NULL;

			flag = 1;

			break;
		}

		pPre = pPre->next;	// pPer指向pCur位置
		pCur = pCur->next;  //pCur指向下一个结点
	}

	if (flag == 0)
	{
		printf("没有值为%d的结点\n", x);
		return -2;
	}

	return 0;
}

//删除值为x的所有结点
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

//删除值为x的所有结点
int SListNodeDelPro2(Node* head, int x)
{
	if (head == NULL)
	{
		return -1;
	}

	Node* pPre = head;
	Node* pCur = head->next;

	int flag = 0; // 0代表没有找到，1代表找到

	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			// pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur == NULL;

			flag = 1;

			pCur = pPre->next;

			continue; // 不执行下方语句
		}

		pPre = pPre->next;	// pPer指向pCur位置
		pCur = pCur->next;  //pCur指向下一个结点
	}

	if (flag == 0)
	{
		printf("没有值为%d的结点\n", x);
		return -2;
	}

	return 0;
}

// 清空链表，释放所有结点
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
		// 保存head的下一个结点
		tmp = head->next;
		free(head);

		// head指向tmp
		head = tmp;

		i++;
	}

	printf("i = %d\n", i);

	return 0;
}

// 链表的遍历
int SListPrint(Node* head)
{
	if (head == NULL)
	{
		return -1;
	}

	// 去除第一个有效节点（头节点的next）
	Node* pCur = head->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		// 把当前节点往下移动一位，pCUr指向下一个
		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;
}

int main()
{
	Node* pHead = SListCreat();

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
	SListNodeInsertPro(pHead, 10);
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
	SListNodeDestory(pHead);
	pHead = NULL;
	SListPrint(pHead);

	return 0;
}