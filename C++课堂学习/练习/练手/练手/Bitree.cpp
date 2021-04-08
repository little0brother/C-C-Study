#include <iostream>
using namespace std;

#define DateLen 20
typedef char ElemType[DateLen];				//定义数据的最大长度

typedef struct BiTreeNode					//定义二叉树的存储类型
{
	ElemType data;							//定义数据域
	BiTreeNode *lchild, *rchild;			//定义左孩子，右孩子
}BiTreeNode, *BiTree;						//BiTree为可以指向BiTreeNode的指针

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
	Line 13:定义带参宏定义，将几点存入合适位置
	Line 14:为节点申请内存空间
	Line 15:检查内存空间是否申请成功
	Line 19:将字符存入数据中
	Line 21:置空左孩子，右孩子
*/

void CreatBiTree(BiTree* tree)				//创建二叉树
{
	BiTree pTemp;							//定义临时变量
	BiTree parent;				

	CreatNode(pTemp, 'A')					//调用宏定义，将字符A存入根节点
	*tree = pTemp;	

	CreatNode(pTemp, 'B')					//将B存入左子树，并将父节点定义为B，以便存入B的孩子们
	(*tree)->lchild = pTemp;
	parent = (*tree)->lchild;

	CreatNode(pTemp, 'C')
	(*tree)->rchild = pTemp;

	CreatNode(pTemp, 'D')					//将D存入B的左子树
	parent->lchild = pTemp;

	CreatNode(pTemp, 'E')
	parent->rchild = pTemp;
	parent = parent->rchild;				//将父节点变为E

	CreatNode(pTemp, 'F')
	parent->lchild = pTemp;

	CreatNode(pTemp, 'G')
	parent->rchild = pTemp;
}

//前序遍历
void preorder(BiTree tree)
{
	if (tree != NULL)
	{
		cout << tree->data;
		preorder(tree->lchild);
		preorder(tree->rchild);
	}
}

//后序遍历
void postorder(BiTree tree)
{
	if (tree != NULL)
	{
		postorder(tree->lchild);
		postorder(tree->rchild);
		cout << tree->data;
	}
}

//中序遍历
void inorder(BiTree tree)
{
	if (tree != NULL)
	{
		inorder(tree->lchild);
		cout << tree->data;
		inorder(tree->rchild);
	}
}

//采用后续遍历的方法销毁二叉树
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