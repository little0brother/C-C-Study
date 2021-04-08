#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int id;		//������
	struct Node *next;	//ָ����
}SLIST;

//����ͷ�ڵ�
SLIST *SListCreat() 
{
	SLIST *pCur = NULL;		//��ǰ�ڵ�
	SLIST *pHead = NULL;	//ͷ���
	SLIST *pNew = NULL;		//�½ڵ�

	//ͷ��㣬ֻ����Ϊ��־ʹ�ã���������Ч����
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}

	//pHead��Ա������ֵ�����������⼴�ɣ������ò���
	pHead->id = -1;
	pHead->next = NULL;

	//���浱ǰ�ڵ�
	//ָ��ָ��˭���Ͱ�˭�ĵ�ַ��ֵ��ָ��
	pCur = pHead;

	int data;

	//ѭ��������㣬����������е���ֵ�Ӽ������룬��-1��Ϊ���������־
	while (1)
	{
		printf("���������ݣ�");
		scanf("%d", &data); 

		if (data == -1)
		{//����-1���˳�ѭ��
			break;
		}

		//�½ڵ����ռ�
		pNew = (SLIST *)malloc(sizeof(SLIST));
		if (pNew == NULL)
		{//���û�з���ɹ�����������ѭ��
			continue;
		}

		//pNew��Ա������ֵ
		pNew->id = data;
		pNew->next = NULL;

		//��ǰ�ڵ�nextָ���½ڵ�
		pCur->next = pNew;

		//�½ڵ��nextָ��NULL
		pNew->next = NULL;

		//��ǰ�ڵ��λ���ƶ����½ڵ��λ�ã�pCurָ��pNew��
		pCur = pNew;
	}

	
	//�����ͷ����ַ�ɺ���ֵ���ء�
	return pHead;
}

//�����ڵ�
//˳�������������������������е�����
int SListPrint(SLIST *pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	//����ͷ������һ���ڵ�
	//��Ϊͷ��㲻����Ч���ݽڵ㣬��һ���ڵ������Ч���ݵĽ��
	SLIST *pCur = pHead->next;

	printf("head -> ");
	while (pCur != NULL)
	{
		printf("%d -> ", pCur->id);

		//�ڵ������ƶ�����ǰ�ڵ�ָ����һ���ڵ�
		pCur = pCur->next;
	}
	printf("NULL\n");

	return 0;
}

//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
int SListNodeInsert(SLIST *pHead, int x, int y)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pPre = pHead;		//��һ���ڵ�
	SLIST *pCur = pHead->next;	//��ǰ�ڵ�
	SLIST *pNew = NULL;         //�½ڵ�

	while (pCur != NULL)
	{
		//�����ǰ�ڵ����������x������ѭ��
		if (pCur->id == x)
		{
			break;
		}

		//���浱ǰ�ڵ�
		pPre = pCur;

		//��ǰ�ڵ������ƶ�����ǰ�ڵ�ָ����һ���ڵ�
		//pPre��pCur���һ���ڵ㣬pPreΪ��һ���ڵ㣬pCurΪ��ǰ�ڵ�
		pCur = pCur->next;
	}

	//����ִ�е��⣬���������
	//1. �ҵ�ֵΪx�Ľ�㣬pCurΪ��ǰƥ��ڵ㣬pPreΪ��һ���ڵ�
	//2. û���ҵ�x�Ľ�㣬�ڵ��ƶ�����β��pPreΪ���һ���ڵ㣬pCurΪNULL

	//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
	//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
	
	//�½ڵ����ռ�
	pNew = (SLIST *)malloc(sizeof(SLIST));
	if (pNew == NULL)
	{
		return -2;
	}

	//pNew��Ա������ֵ
	pNew->id = y;
	pNew->next = NULL;

	//pPre��nextָ��pNew
	pPre->next = pNew;

	//pNew��nextָ��pCur
	pNew->next = pCur;

	return 0;
}

//ɾ����һ��ֵΪx�Ľ��
int SListNodeDel(SLIST *pHead, int x)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pPre = pHead;		//��һ���ڵ�
	SLIST *pCur = pHead->next;	//��ǰ�ڵ�
	int flag = 0; //��־λ��0����û��ֵΪx�Ľ�㣬1������


	while (pCur != NULL)
	{
		if (pCur->id == x)
		{
			//��һ���ڵ�ָ��ǰ�ڵ����һ���ڵ�
			pPre->next = pCur->next;

			//��ʱ�ͷŽڵ�
			free(pCur);
			pCur = NULL;

			//��־λ��0����û��ֵΪx�Ľ�㣬1������
			flag = 1;

			//����ѭ��
			break;
		}

		//���浱ǰ�ڵ�
		pPre = pCur;

		//��ǰ�ڵ������ƶ�����ǰ�ڵ�ָ����һ���ڵ�
		//pPre��pCur���һ���ڵ㣬pPreΪ��һ���ڵ㣬pCurΪ��ǰ�ڵ�
		pCur = pCur->next;
	}


	if (flag == 0)
	{ //��־λ��0����û��ֵΪx�Ľ�㣬1������
		printf("û��ֵΪ%d�Ľ��\n", x);
		return -2;
	}

	return 0;
}

//�ͷ����нڵ�
int SListDestroy(SLIST *pHead)
{
	if (pHead == NULL)
	{
		return -1;
	}

	SLIST *pTmp = NULL;	//��ʱ�ͷŽڵ�

	while (pHead != NULL)
	{
		//��ʱ�ͷŽڵ�
		pTmp = pHead;

		//ͷ���ָ��ͷ���next�ڵ�
		pHead = pHead->next;
		
		free(pTmp);
		pTmp = NULL;

	}

	return 0;
}

int main()
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	
	SListNodeInsert(pHead, 4, 3);//��4ǰ�����3
	printf("\n��4ǰ�����3\n");
	SListPrint(pHead); //�������нڵ�

	
	SListNodeDel(pHead,  4);//ɾ����һ��ֵΪ4�Ľ��
	printf("\nɾ����һ��ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�


	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;
	SListPrint(pHead); //�������нڵ�

	printf("\n");
	system("pause");
	return 0;
}