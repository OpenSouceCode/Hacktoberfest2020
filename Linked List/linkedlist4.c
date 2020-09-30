//program to perform deletion operations on a linked list
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
void delete_from_begin(struct node **h);
void delete_from_end(struct node **h, struct node **p);
void delete_value(struct node **h, struct node **p, int value);
void delete_pos(struct node **h, struct node **p, int pos);
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
	printf("5.Delete from beginning of List\n");
	printf("6.Delete from end of List\n");
	printf("7.Delete a desired value from List\n");
	printf("8.Delete a desired position in List\n");

	int choice = 0;
	printf("Enter your choice: ");
	scanf("%d", &choice);

	int value = 0;
	int pos = 0;
	if (choice == 7)
	{
		printf("Enter Value to be operated: ");
		scanf("%d" , &value);
	}
	else if (choice == 8)
	{
		printf("Desired Position: ");
		scanf("%d", &pos);
	}

	switch(choice)
	{
		case 5: delete_from_begin(&head);
			break;
		
		case 6: delete_from_end(&head, &tail);
			break;

		case 7: delete_value(&head, &tail, value);
			break;

		case 8: delete_pos(&head, &tail, pos);
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

void delete_from_begin(struct node **h)
{
	if ((*h) != NULL)
	{
		(*h) = (*h)->next;
		printf("Successfully deleted the node at beginning:)\n");
	}
		
	else
		printf("List is already Empty!.:\n");

}

void delete_from_end(struct node **h, struct node **p)
{
	struct node *cur = NULL;
	struct node *pre = NULL;

	cur = *h;
	while (cur->next != NULL)
	{
		pre = cur;
		cur = cur->next;
	}

	(*p) = pre;
	pre->next = NULL;
	printf("Successfully deleted the node at end:)\n");

}

void delete_value(struct node **h, struct node **p, int value)
{
	int count = 0;
	struct node *cur = NULL;
	struct node *pre = NULL;

	cur = *h;

	while (cur->next != NULL)
	{
		pre = cur;
		cur = cur->next;
		count++;

		if (cur->val == value)
		{
			if (cur->next == NULL)
				delete_from_end(h, p);
			
			else if (count == 1)
				delete_from_begin(h);
			
			else
			{
				pre->next = cur->next;
				cur->next = NULL;
			}
		} 
		
	}
	printf("Successfully deleted %d from list:)\n", value);

}

void delete_pos(struct node **h, struct node **p, int pos)
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
	else 
		*p = pre;

	pre->next = cur->next;
	
	printf("Successfully deleted node %d :)\n", pos);
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