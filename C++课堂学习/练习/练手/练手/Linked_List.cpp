#include <iostream>
using namespace std;

#define Datatype char

typedef struct node {
	Datatype Data;
	struct node *next;
} Link_List;

Link_List *Initiate()
{
	Link_List *head;
	head = new Link_List;
	head->next = NULL;

	return (head);
}

Link_List *Rcreat()
{
	Link_List *head, *last, *p;
	char ch;

	head = new Link_List;
	head->next = NULL;
	last = head;

	while ((ch = getchar()) != '$')
	{
		if (ch != ' ') {
			p = new Link_List;
			p->Data = ch;
			last->next = p;
			last = p;
			p->next = NULL;
		}
	}

	return (head);
}

int Length(Link_List * head)
{
	int i;
	Link_List *p;
	p = head;
	i = 0;

	while (p->next != NULL)
	{
		p = p->next;
		if(p->Data != ' ' && p->Data != '$')
			i++;
	}

	return i;
}

Link_List *Get(Link_List *head, int i)
{
	int j;
	Link_List *p;
	j = 0;
	p = head;
	while (j < i && p)
	{
		p = p->next;
		j++;
	}

	return p;
}

Link_List *Locate(Link_List *head, Datatype x)
{
	Link_List *p;
	p = head->next;
	while (p && p->Data != x)
		p = p->next;

	return p;
}

void Insert(Link_List *head, int i, Datatype x)
{
	Link_List *h, *p;
	h = new Link_List;
	h->Data = x;
	h->next = NULL;
	p = Get(head, i - 1);

	if (p != NULL)
	{
		h->next = p->next;
		p->next = h;
	}
	else
		cout << "Insert Fail";
}

void Delete(Link_List *head, int i)
{
	Link_List *p, *q;
	p = Get(head, i - 1);

	if ((p != NULL) && (p->next != NULL))
	{
		q = p->next;
		p->next = q->next;
		free(q);
	}
	else
		cout << "Delete Fail";
}

int Empty(Link_List *head)
{
	if (head->next == NULL)
		return 1;
	else
		return 0;
}

void Printf(Link_List *head)
{
	Link_List *p;
	p = head->next;

	while (p != NULL)
	{
		printf("%4c", p->Data);
		p = p->next;
	}
}

int main()
{
	Link_List *head;

	//head = Initiate();
	head = Rcreat();
	cout << "Length:" << Length(head) << endl;
	//Link_List *locate = Locate(head, 'p');
	//cout << locate->Data << endl;
	Printf(head);

	Insert(head, 3, 'm');
	cout << endl;
	Printf(head);

	system("pause");
	return 0;
}