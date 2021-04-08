#include <iostream>
using namespace std;

const int n = 20;

typedef struct
{
	int num;
	char name[20];
	char sex;
	float english;
	float math;
}Stu;

typedef struct BiTreeNodee //姓名的二叉树 
{
	char nam;
	struct BiTreeNodee *lchild,*rchild;
}BiTreeNode, *BiTree; 

void InitBiTree(BiTreeNode *tr)
{
	BiTree p;
	p = tr;

	p->nam = '#';
	p->lchild = NULL;
	p->rchild = NULL;
}

void Initlist(Stu *s)
{
	s=(Stu*)malloc(sizeof(Stu)*n);
}

void getlistinfo(Stu *s)
{
	Stu *p = s;
	FILE *f;
	int i;
	f=fopen("xx.txt","r");
	for (i = 1; i <= n; i++)
	{
		fscanf(f, "%d %s %c %f %f\n", &p->num, &p->name, &p->sex, &p->english, &p->math);
		p++;	 
	}
	fclose(f);
}

void Printlist(Stu *s)
{
	Stu *p = s;

	int i;
	for (i = 1; i <= n; i++) {
		printf("%d %s %c %.2f %.2f\n", p->num, p->name, p->sex,p->english, p->math);
		p++;
	}
}

void qksortenglish(Stu *s,int t=0,int w=20)
{
	Stu *p = s;
	int i, j,k;
	Stu x;
	if(t>=w) return;
	i=t;j=w;x=p[i];
	while(i<j)
	{
		while ((i<j)&&(p[j].english<=x.english)) 
			j--;
		if(i<j) 
		{
			p[i]=p[j];
			i++;	
		}
		while ((i<j)&&(p[i].english>=x.english)) 
			i++;
		if(i<j)
		{
			p[j]=p[i];
			j--;
		}
	}
	p[i]=x;
	qksortenglish(s,t,j-1);
	qksortenglish(s,j+1,w);
} 

int BinarySearch(Stu *s,int key,int u=20)//返回位置 
{
	Stu *p = s;
	int low=1;
	int high=u;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key == p[mid].english)
			return mid;
		else if(key>p[mid].english)
			high=mid-1;
		else low=mid+1;
	}
	return 0;
}

BiTree SortBiTree(BiTreeNode *tr)
{
	char tname;
	BiTreeNode *t = tr;

	FILE *f;
	int i,j;
	int n1; char s3; float e4,m5;//不需要的 存入但不使用 
	f=fopen("xx.txt","r");
	for (i = 1; i <= n; i++)
	{
		fscanf(f, "%d %c %c %f %f\n", &n1, &tname, &s3, &e4, &m5);
	
		j=i;
		while(j--)
		{
			if(t->nam == '#')
			{
				t=(BiTreeNode *)malloc(sizeof(BiTreeNode));
				t->nam=tname;
			}
			else if(tname < t->nam)
			{
				t->lchild->nam=tname;
			}
			else if(tname > t->nam)
			{
				t->rchild->nam=tname;
			}
		}
	}

	return tr;
}

void Preorder(BiTreeNode *t)
{
	BiTree root = t;
	if(root != NULL)
	{
		cout << root->nam << endl;
		Preorder(root->lchild); 
		Preorder(root->rchild); 
	}
}

int main()
{
	Stu liststu[n];

	Initlist(liststu);
	getlistinfo(liststu);
	Printlist(liststu);
/*	qksortenglish(liststu,0,20);
	printf("\n英语成绩排序：\n");
	Printlist(liststu);

	printf("\n输入你想查找的成绩；\n");
	int a,key;
	scanf("%d",&key);
	a=BinarySearch(liststu,key,20);
	if(a==0) 
		printf("\n没找到哦\n");
	else 
		printf("此人信息为：\n%d %s\n",liststu[a].num,liststu[a].name);
*/	
	BiTreeNode tr;
	InitBiTree(&tr);
	
	Preorder(SortBiTree(&tr));

	system("pause");
	return 0;
}