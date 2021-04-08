#include <iostream>
using namespace std;

#define DateLen 20
typedef char ElemType[DateLen];				//�������ݵ���󳤶�

typedef struct BiTreeNode					//����������Ĵ洢����
{
	ElemType data;							//����������
	BiTreeNode *lchild, *rchild;			//�������ӣ��Һ���
}BiTreeNode, *BiTree;						//BiTreeΪ����ָ��BiTreeNode��ָ��

#define CreatNode(pTemp, v)				\
	pTemp = new BiTreeNode;				\
	if (!pTemp)							\
		cout << "error:" << __LINE__;	\
	else								\
	{									\
		pTemp->data[0] = v;				\
		pTemp->data[1] = '\0';			\
		pTemp->lchild = NULL;			\
		pTemp->rchild = NULL;			\
	}							
/*
	Line 13:������κ궨�壬������������λ��
	Line 14:Ϊ�ڵ������ڴ�ռ�
	Line 15:����ڴ�ռ��Ƿ�����ɹ�
	Line 19:���ַ�����������
	Line 21:�ÿ����ӣ��Һ���
*/

void CreatBiTree(BiTree* tree)				//����������
{
	BiTree pTemp;							//������ʱ����
	BiTree parent;				

	CreatNode(pTemp, 'A')					//���ú궨�壬���ַ�A������ڵ�
	*tree = pTemp;	

	CreatNode(pTemp, 'B')					//��B�������������������ڵ㶨��ΪB���Ա����B�ĺ�����
	(*tree)->lchild = pTemp;
	parent = (*tree)->lchild;

	CreatNode(pTemp, 'C')
	(*tree)->rchild = pTemp;

	CreatNode(pTemp, 'D')					//��D����B��������
	parent->lchild = pTemp;

	CreatNode(pTemp, 'E')
	parent->rchild = pTemp;
	parent = parent->rchild;				//�����ڵ��ΪE

	CreatNode(pTemp, 'F')
	parent->lchild = pTemp;

	CreatNode(pTemp, 'G')
	parent->rchild = pTemp;
}

//ǰ�����
void preorder(BiTree tree)
{
	if (tree != NULL)
	{
		cout << tree->data;
		preorder(tree->lchild);
		preorder(tree->rchild);
	}
}

//�������
void postorder(BiTree tree)
{
	if (tree != NULL)
	{
		postorder(tree->lchild);
		postorder(tree->rchild);
		cout << tree->data;
	}
}

//�������
void inorder(BiTree tree)
{
	if (tree != NULL)
	{
		inorder(tree->lchild);
		cout << tree->data;
		inorder(tree->rchild);
	}
}

//���ú��������ķ������ٶ�����
void DestoryBiTree(BiTree tree)
{
	if (tree)
	{
		DestoryBiTree(tree->lchild);
		DestoryBiTree(tree->rchild);
		delete tree;
	}
}

int main()
{
	BiTree tree;
	CreatBiTree(&tree);

	preorder(tree);
	cout << endl;

	inorder(tree);
	cout << endl;

	postorder(tree);
	cout << endl;

	cout << __TIME__ << endl << __FILE__ << endl << __LINE__ << endl;

	system("pause");
	return 0;
}