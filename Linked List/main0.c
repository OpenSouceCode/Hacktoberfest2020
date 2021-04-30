#include <stdio.h>
#include <stdlib.h>

struct node *create(int value);
void insert(struct node **h, struct node **t, int pos);
void display(struct node *h);

struct node
{
	int val;
	struct node *next;
};

int main()
{
	struct node *head = NULL;
	struct node *temp = NULL;

	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	temp = create(value);
	head = insert(&head, &temp);

	temp = head;
	
	display(temp);
	
	printf("\n");

	return 0;
}

struct node *create(int value)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->val = value;
	newnode->next = NULL;

	return newnode;

}

void insert(struct node **h, struct node **t, int pos)
{
	if (h != NULL)
		t->next = h;
	h = t;

	return h;
}

void display(struct node *h)
{
	while (h != NULL)
	{
		printf("%d\t", (h->val));
		h = h->next;
	}
	printf("NULL");
}
