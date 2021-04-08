#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;
	struct Node *next; //指针域
}Node;

//创建头结点
//链表的头结点地址由函数值返回。
Node *SListCreat()
{
	Node *head = NULL;

	//头结点作为标志，不存储有效数据
	head = (Node *)malloc(sizeof(Node));
	if (head == NULL)
	{
		return NULL;
	}

	//给head的成员变量赋值
	head->id = -1;
	head->next = NULL;

	Node *pCur = head;
	Node *pNew = NULL;

	int data;

	while (1)
	{
		printf("请输入数据：");
		scanf("%d", &data);

		if (data == -1) //输入-1，退出
		{
			break;
		}

		//新结点动态分配空间
		pNew = (Node *)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			//continue;
			break;
		}

		//给pNew成员变量赋值
		pNew->id = data;
		pNew->next = NULL;

		//链表建立关系

		//当前结点的next指向pNew
		pCur->next = pNew;

		//pNew下一个结点指向NULL
		pNew->next = NULL;

		//把pCur移动到pNew,pCur指向pNew
		pCur = pNew;
	}


	return head;
}

//链表的遍历
int SListPrint(Node * head)
{
	if (head == NULL)
	{
		return -1;
	}

	//取出第一个有效结点（头结点的next）
	Node *pCur = head->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		//当前结点往下移动一位，pCur指向下一个
		pCur = pCur->next;
	}
	printf("NULL\n");


	return 0;
}

//在值为x的结点前，插入值为y的结点；若值为x的结点不存在，则插在表尾。
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
		if (pCur->id == x) //找到了匹配结点
		{
			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个结点

	}

	//2种情况
	//1. 找匹配的结点，pCur为匹配结点，pPre为pCur上一个结点
	//2. 没有找到匹配结点，pCur为空结点，pPre为最后一个结点

	//给新结点动态分配空间
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}
	//给pNew的成员变量赋值
	pNew->id = y;
	pNew->next = NULL;

	//插入指定位置
	pPre->next = pNew; //pPre下一个指向pNew
	pNew->next = pCur; //pNew下一个指向pCur

	return 0;
}

//删除第一个值为x的结点
int SListNodeDel(Node *head, int x)
{

	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0; //0没有找，1找到

	while (pCur != NULL)
	{
		if (pCur->id == x) //找到了匹配结点
		{
			//pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;


			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个结点

	}

	if (0 == flag)
	{
		printf("没有值为%d的结点\n", x);
		return -2;
	}

	return 0;
}

//清空链表，释放所有结点
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
		//保存head的下一个结点
		tmp = head->next;
		free(head);
		head = NULL;

		//head指向tmp
		head = tmp;
		i++;
	}

	printf("i = %d \n", i);


	return 0;
}

//删除值为x的所有结点
int SListNodeDelPro(Node *head, int x)
{
	if (head == NULL)
	{
		return -1;
	}
	Node *pPre = head;
	Node *pCur = head->next;
	int flag = 0; //0没有找，1找到

	while (pCur != NULL)
	{
		if (pCur->id == x) //找到了匹配结点
		{
			//pPre的下一个指向pCur的下一个
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;

			flag = 1;

			pCur = pPre->next;

			//break;
			continue; //跳出本次循环，重要
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个结点

	}

	if (0 == flag)
	{
		printf("没有值为%d的结点\n", x);
		return -2;
	}

	return 0;
}

//链表节点排序
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

	// pPre->next != NULL，链表倒数第2个结点
	for (pPre = head->next; pPre->next  != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			//注意，排序，除了数据域需要交换，next指针还需要交换
			if (pPre->id > pCur->id) //升序
			{

				//只交换数据域
				tmp.id = pCur->id;
				pCur->id = pPre->id;
				pPre->id = tmp.id;
#if 0
				//交换数据域
				tmp = *pCur;
				*pCur = *pPre;
				*pPre = tmp;

				//交换指针域（重要）
				tmp.next = pCur->next;
				pCur->next = pPre->next;
				pPre->next = tmp.next;
#endif
			}
		}
	}


	return 0;

}

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
int SListNodeInsertPro(Node *head, int x)
{
	//保证插入前是有序的
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

	//1 2 3 5 6， 插入4
	//3：pre, 5: cur
	while (pCur != NULL)
	{
		if (pCur->id > x) //找到了匹配结点
		{
			break;
		}

		//pPre指向pCur位置
		pPre = pCur;
		pCur = pCur->next; //pCur指向下一个结点

	}

	//2种情况
	//1. 找匹配的结点，pCur为匹配结点，pPre为pCur上一个结点
	//2. 没有找到匹配结点，pCur为空结点，pPre为最后一个结点

	//给新结点动态分配空间
	Node *pNew = (Node *)malloc(sizeof(Node));
	if (pNew == NULL)
	{
		return -2;
	}
	//给pNew的成员变量赋值
	pNew->id = x;
	pNew->next = NULL;

	//插入指定位置
	pPre->next = pNew; //pPre下一个指向pNew
	pNew->next = pCur; //pNew下一个指向pCur

	return 0;

	return 0;
}

//翻转链表的节点（不是排序，是翻转）
//把链表的指向反过来
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

	head = SListCreat();//创建头结点
	SListPrint(head);

	SListNodeInsert(head, 5, 4);
	printf("在5的前面插入4后\n");
	SListPrint(head);

	SListNodeDelPro(head, 5);
	printf("删除所有5结点后\n");
	SListPrint(head);

	SListNodeSort(head);
	printf("排序后\n");
	SListPrint(head);


	SListNodeInsertPro(head, 6);
	printf("升序插入6后\n");
	SListPrint(head);

	SListNodeReverse(head);
	printf("链表翻转后\n");
	SListPrint(head);



	SListNodeDestroy(head);
	head = NULL;


	printf("\n");
	system("pause");
	return 0;
}