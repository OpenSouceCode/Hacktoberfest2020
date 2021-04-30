#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
	int val;
	struct node *next;
};

int count = 0;
int read();
struct node *create(int value);
void insert(struct node **h, struct node **t, struct node **p, int value);
void insert_at_begin(struct node **h, struct node **t);
void insert_at_end(struct node **h, struct node **t, struct node **p);
void insert_in_between(struct node **h, struct node **t, struct node **p, int pos);
void display(struct node *h);

int main()
{
	struct node *head = NULL;
	struct node *tail = NULL;
	struct node *temp = NULL;

	tail = head;

	while (1)
	{
		int no;
		no = read();
		if (no != -1)
		{
			insert(&head, &temp, &tail, no);
		}
		else 
			break;
	}

	printf("Linked List Operations.\n");
	printf("1.Create List\t\t");
	printf("2.Insert at beginning of List\n");
	printf("3.Insert at end of List\t");
	printf("4.Insert at a desired position in List\n");

	int choice = 0;
	printf("Enter your choice: ");
	scanf("%d", &choice);

	int values = 0;
	int pos = 0;
	if ((choice >= 2 && choice <= 4))
	{
		printf("Enter Value to be operated: ");
		scanf("%d" , &values);

		if (choice == 4)
		{
			printf("Desired Position: ");
			scanf("%d", &pos);
		}
	}

	switch(choice)
	{
		case 2: temp = create(values);
				insert_at_begin(&head, &temp);
			break;
		
		case 3: temp = create(values);
				insert_at_end(&head, &temp, &tail);
			break;

		case 4: temp = create(values);
				insert_in_between(&head, &temp, &tail, pos); 
			break;

		default : printf("Invalid Choice!!\n");
			break;
	}

	temp = head;
	
	display(temp);
	
	printf("\n");
	return 0;	
}

int read()
{
	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	return value; 
}

struct node *create(int value)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->val = value;
	newnode->next = NULL;

	return newnode;

}

void insert(struct node **h, struct node **t, struct node **p, int value)
{

	struct node *newnode = NULL;
	newnode = create(value); 
	
	if ((*h) != NULL)
	{
		(*t)->next = newnode;	
	}
	else
	{
		*h = newnode;	
	}
	
	*p = newnode;	
	*t = newnode;
	count++;
	
}

void insert_at_begin(struct node **h, struct node **t)
{
	if ((*h) != NULL)
		(*t)->next = *h;
	
	(*h) = *t;
	count++;
}

void insert_at_end(struct node **h, struct node **t, struct node **p)
{
	if ((*h) == NULL)
		*h = *t;

	(*p)->next = (*t);
	count++;		
}
											
void insert_in_between(struct node **h, struct node **t, struct node **p, int pos)
{
	int counter = 0;
	struct node *cur = NULL;
	struct node *pre = NULL;
	
	cur = *h;
	if (pos > count)
		printf("Invalid Position!!.:\n");

	else if (pos < count)
	{
		counter = 1;
		while(counter != pos)
		{
			pre = cur;
			cur = cur->next;
			counter++; 
		}
	}

	(*t)->next = pre->next;
	pre->next = *t;
	
	if (pos == count) 
	{
		(*p) = (*p)->next;
	}
	count++;

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
