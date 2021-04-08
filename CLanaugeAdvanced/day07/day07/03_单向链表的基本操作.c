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

// 删除第一个值为x的结点
int SlistNodeDel(Node* head, int x)
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
	Node* head = NULL;

	head = SListCreat();	// 创建头节点
	SListPrint(head);

	SListNodeInsert(head, 5, 4); // 插入结点
	printf("\n在5的前面插入4后：\n");
	SListPrint(head);

	SlistNodeDel(head, 5);	// 删除节点
	printf("删除5结点后：\n");
	SListPrint(head);

	SListNodeDestory(head);
	head = NULL;
	printf("释放所有结点后：\n");
	SListPrint(head);

	return 0;
}