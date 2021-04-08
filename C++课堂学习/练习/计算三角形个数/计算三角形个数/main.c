/*++

TriNum.c, 2018/06/08
function: Get the number of triangle from the graph.

--*/
#include <conio.h>
#include <stdio.h>

#define BASESIZE    32
#define DELTA       32
#define NUM			11

typedef union Tri
{
	int val;
	char ch[3];
} Tri;

typedef struct Result
{
	Tri*	ptr;
	int     num;
	int		total;
} Result;

char mat[NUM][NUM] =
{
		  /*0, 1, 2, 3, 4, 5, 6, 7,   8, 9, 10*/
	/*0*/	0, 1, 1, 1, 1, 1, 1, 1,   1, 1, 1,
	/*1*/	1, 0, 1, 1, 1, 0, 0, 1,   0, 0, 0,
	/*2*/   1, 1, 0, 1, 1, 0, 1, 0,   1, 0, 0,
	/*3*/   1, 1, 1, 0, 1, 1, 0, 0,   0, 1, 0,
	/*4*/   1, 1, 1, 1, 0, 1, 1, 1,   0, 0, 1,
	/*5*/   1, 0, 0, 1, 1, 0, 1, 1,   0, 1, 0,
	/*6*/   1, 0, 1, 0, 1, 1, 0, 1,   1, 0, 0,
	/*7*/   1, 1, 0, 0, 1, 1, 1, 0,   1, 1, 1,
	/*8*/   1, 0, 1, 0, 0, 0, 1, 1,   0, 1, 1,
	/*9*/   1, 0, 0, 1, 0, 1, 0, 1,   1, 0, 1,
	/*10*/  1, 0, 0, 0, 1, 0, 0, 1,   1, 1, 0
};

char line[][NUM] =
{
	{ 0, 1,  7,     -1 },
	{ 0, 2,  6,  8, -1 },
	{ 0, 3,  5,  9, -1 },
	{ 0, 4, 10,     -1 },
	{ 1, 2,  3,  4, -1 },
	{ 4, 5,  6,  7, -1 },
	{ 7, 8,  9, 10, -1 }
};

int init(Result* rp)
{
	rp->ptr = (Tri*)malloc(BASESIZE * sizeof(Tri));
	rp->num = 0;

	if (rp->ptr)
	{
		rp->total = BASESIZE;
		return 1;
	}
	return 0;
}

int release(Result* rp)
{
	if (rp && rp->ptr)
	{
		free(rp->ptr);
		rp->ptr = NULL;
		return 1;
	}
	return 0;
}

int online(char line[][NUM], int rows, Tri tri)
{
	int m, n, i;
	char* p;

	for (m = 0; m < rows; m++)
	{
		n = 0;
		for (i = 0; i < 3; i++)
		{
			p = line[m];
			while (*p != -1)
			{
				if (*p++ == tri.ch[i])
				{
					n++;
					break;
				}
			}
		}

		if (n >= 3)
			break;
	}
	return n >= 3;
}

int insert(Result* rp, Tri tri)
{
	int i;
	for (i = 0; i < rp->num; i++)
	{
		if (rp->ptr[i].val == tri.val)
			break;
	}

	if (i >= rp->num)
	{
		// 新三角形加入，检查存储空间是否够用。
		if (rp->num >= rp->total)
		{
			// 扩大存储空间
			rp->ptr = (Tri*)realloc(rp->ptr, (rp->total + DELTA) * sizeof(Tri));
			if (!rp->ptr)
			{
				// 内存空间不足，程序无法运行。
				exit(1);
			}
			rp->total += DELTA;
		}

		// 存储新加入三角形
		rp->ptr[rp->num++] = tri;
		return 1;
	}
	return 0;
}

void sort(Tri* ptri)
{
	char i, j, k, t;
	for (i = 0; i < 2; i++)
	{
		k = i;
		for (j = i + 1; j < 3; j++)
		{
			if (ptri->ch[k] > ptri->ch[j])
				k = j;
		}

		if (k != i)
		{
			t = ptri->ch[i];
			ptri->ch[i] = ptri->ch[k];
			ptri->ch[k] = t;
		}
	}
}

void prt(Result* rp)
{
	int i;
	for (i = 0; i < rp->num; i++)
	{
		printf("%2d: %4d%4d%4d\n",
			i + 1, rp->ptr[i].ch[0], rp->ptr[i].ch[1], rp->ptr[i].ch[2]);
	}
}

void ReadMat(char mat[][NUM], char line[][NUM], int rows, Result* rs)
{
	int i, j, k;
	Tri tri;

	for (i = 0; i < NUM; i++)
	{
		for (j = i + 1; j < NUM; j++)
		{
			for (k = j + 1; k < NUM; k++)
			{
				if (mat[i][j] && mat[i][k] && mat[j][k])
				{
					tri.ch[0] = i;
					tri.ch[1] = j;
					tri.ch[2] = k;
					tri.ch[3] = 0;

					if (!online(line, rows, tri))
					{
						sort(&tri);
						insert(rs, tri);
					}
				}
			}
		}
	}
}

int main()
{
	Result rs;

	init(&rs);
	ReadMat(mat, line, 7, &rs);
	prt(&rs);
	release(&rs);

	getch();
	return 0;
}