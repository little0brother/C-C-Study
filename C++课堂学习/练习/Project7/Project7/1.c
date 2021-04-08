#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node *next;
} Node;

void add(int number);

int main()
{
	Node * head = NULL;
	int number;

	do {
		scanf("%d", &number);
		if (number != -1) {
			add(number);
		}
	} while (number != -1);

	system("pasue");
	return 0;
}

void add(int number)
{
	//add to linked-list
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	// find the last
	Node *last = head;
	if (last) {
		while (last->next) {
			last = last->next;
		}
		// attach
		last->next = p;
	}
	else
		head = p;
	}
}