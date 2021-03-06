#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;		//数据域
	struct Node *next;	//指针域
}SLIST;

//创建头节点
SLIST *SListCreat() 
{
	SLIST *pCur = NULL;		//当前节点
	SLIST *pHead = NULL;	//头结点
	SLIST *pNew = NULL;		//新节点

	//头结点，只是作为标志使用，不保存有效数据
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}

	//pHead成员变量赋值，数据域任意即可，后面用不上
	pHead->id = -1;
	pHead->next = NULL;

	//保存当前节点
	//指针指向谁，就把谁的地址赋值给指针
	pCur = pHead;

	int data;

	//循环创建结点，结点数据域中的数值从键盘输入，以-1作为输入结束标志
	while (1)
	{
		printf("请输入数据：");
		scanf("%d", &data); 

		if (data == -1)
		{//输入-1，退出循环
			break;
		}

		//新节点分配空间
		pNew = (SLIST *)malloc(sizeof(SLIST));
		if (pNew == NULL)
		{//如果没有分配成功，跳出本次循环
			continue;
		}

		//pNew成员变量赋值
		pNew->id = data;
		pNew->next = NULL;

		//当前节点next指向新节点
		pCur->next = pNew;

		//新节点的next指向NULL
		pNew->next = NULL;

		//当前节点的位置移动到新节点的位置（pCur指向pNew）
		pCur = pNew;
	}

	
	//链表的头结点地址由函数值返回。
	return pHead;
}

//遍历节点
//顺序输出单向链表各项结点数据域中的内容
int SListPrint(SLIST *pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	//保存头结点的下一个节点
	//因为头结点不是有效数据节点，下一个节点才是有效数据的结点
	SLIST *pCur = pHead->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		//节点往后移动，当前节点指向下一个节点
		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;
}

//在值为x的结点前，插入值为y的结点；
//若值为x的结点不存在，则插在表尾
int SListNodeInsert(SLIST *pHead, int x, int y)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pPre = pHead;		//上一个节点
	SLIST *pCur = pHead->next;	//当前节点
	SLIST *pNew = NULL;         //新节点

	while (pCur != NULL)
	{
		//如果当前节点数据域等于x，跳出循环
		if (pCur->id == x)
		{
			break;
		}

		//保存当前节点
		pPre = pCur;

		//当前节点往后移动，当前节点指向下一个节点
		//pPre和pCur相差一个节点，pPre为上一个节点，pCur为当前节点
		pCur = pCur->next;
	}

	//程序执行到这，有两种情况
	//1. 找到值为x的结点，pCur为当前匹配节点，pPre为上一个节点
	//2. 没有找到x的结点，节点移动到结尾，pPre为最后一个节点，pCur为NULL

	//在值为x的结点前，插入值为y的结点；
	//若值为x的结点不存在，则插在表尾
	
	//新节点分配空间
	pNew = (SLIST *)malloc(sizeof(SLIST));
	if (pNew == NULL)
	{
		return -2;
	}

	//pNew成员变量赋值
	pNew->id = y;
	pNew->next = NULL;

	//pPre的next指向pNew
	pPre->next = pNew;

	//pNew的next指向pCur
	pNew->next = pCur;

	return 0;
}

//删除第一个值为x的结点
int SListNodeDel(SLIST *pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pPre = pHead;		//上一个节点
	SLIST *pCur = pHead->next;	//当前节点
	int flag = 0; //标志位，0代表没有值为x的结点，1代表有


	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			//上一个节点指向当前节点的下一个节点
			pPre->next = pCur->next;

			//临时释放节点
			free(pCur);
			pCur = NULL;

			//标志位，0代表没有值为x的结点，1代表有
			flag = 1;

			//跳出循环
			break;
		}

		//保存当前节点
		pPre = pCur;

		//当前节点往后移动，当前节点指向下一个节点
		//pPre和pCur相差一个节点，pPre为上一个节点，pCur为当前节点
		pCur = pCur->next;
	}


	if (flag == 0)
	{ //标志位，0代表没有值为x的结点，1代表有
		printf("没有值为%d的结点\n", x);
		return -2;
	}

	return 0;
}

//释放所有节点
int SListDestroy(SLIST *pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pTmp = NULL;	//临时释放节点

	while (pHead != NULL)
	{
		//临时释放节点
		pTmp = pHead;

		//头结点指向头结点next节点
		pHead = pHead->next;
		
		free(pTmp);
		pTmp = NULL;

	}

	return 0;
}

int main()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //创建头结点
	printf("\n创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	
	SListNodeInsert(pHead, 4, 3);//在4前面插入3
	printf("\n在4前面插入3\n");
	SListPrint(pHead); //遍历所有节点

	
	SListNodeDel(pHead,  4);//删除第一个值为4的结点
	printf("\n删除第一个值为4的结点\n");
	SListPrint(pHead); //遍历所有节点


	SListDestroy(pHead);//释放所有节点
	pHead = NULL;
	SListPrint(pHead); //遍历所有节点

	printf("\n");
	system("pause");
	return 0;
}