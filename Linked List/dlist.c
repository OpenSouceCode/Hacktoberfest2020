//FUNCTIONS

#include "dlist.h"

int read()
{
	int value = 0;
	printf("Number: ");
	scanf("%d", &value);

	return value; 
}

struct dnode *create(int value)
{
	struct dnode *newnode = (struct dnode *)malloc(sizeof(struct dnode));

	assert (newnode != NULL);
	
	newnode->next = NULL;
	newnode->val = value;
	newnode->prev = NULL;

	return newnode;
	
}

void insertDnode(struct dnode **h, struct dnode **p, int value)
{
	struct dnode *t = create(value);

	assert (t != NULL);
	
	if (*h == NULL)
	{
		*h = t;
		*p = t;
	}

	else
	{
		(*p)->next = t;
		t->prev = *p;
		*p = t;
	}

	// free(t);
}

void CreateDList(struct dnode **h, struct dnode **p)
{
	while (1)
	{
		int v = read();
		
		if (v != -1)
		{
			insertDnode(&(*h), &(*p), v);
		}

		else
			break;
	}
}

void display(struct dnode *h)
{
	printf("List: ");
	while (h != NULL)
	{
		printf("%d\t", h->val);
		h = h->next;
	}
	printf("NULL\n");
}