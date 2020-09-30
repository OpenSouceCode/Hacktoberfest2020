//Functions for insertion and deletion operations
#include "linkedlist2.h"

int read()
{
	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	return value; 
}

struct node *create(int value)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	
	assert (newnode != NULL);

	newnode->val = value;
	newnode->next = NULL;

	return newnode;
}

void insert(struct node **h, struct node **p, int value)
{

	struct node *newnode = create(value); 
	
	if ((*h) != NULL)
	{
		(*p)->next = newnode;	
	}
	else
	{
		*h = newnode;	
	}
		
	*p = newnode;
	// count++;
}

void insert_at_begin(struct node **h, struct node **t)
{
	if ((*h) != NULL)
		(*t)->next = *h;
	
	(*h) = *t;
	// count++;
}

void insert_at_end(struct node **h, struct node **t, struct node **p)
{
	if ((*h) == NULL)
		*h = *t;

	(*p)->next = (*t);
	// count++;		
}

void insert_in_between(struct node **h, struct node **t, struct node **p, int pos, int cnt)
{
	int counter = 0;
	struct node *cur = NULL;
	struct node *pre = NULL;
	
	cur = *h;
	if (pos > cnt)
	{
		printf("Invalid Position!!.:\n");
		exit(0);
	}

	else if (pos < cnt)
	{
		counter = 1;
		while(counter != pos)
		{
			pre = cur;
			cur = cur->next;
			counter++; 
		}
		printf("Successfully added to list:)\n");
	}

	(*t)->next = pre->next;
	pre->next = *t;
	
	if (pos == cnt) 
	{
		(*p) = (*p)->next;
	}
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
	
	if ((*h) == NULL)
	{
		printf("List is already empty!!\n");
		exit(0);
	}

	else
	{
		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
		}

		(*p) = pre;
		pre->next = NULL;
		printf("Successfully deleted the node at end:)\n");
	}
}

void delete_value(struct node **h, struct node **p, int value, int cnt)
{
	int counter = 0;
	struct node *cur = NULL;
	struct node *pre = NULL;

	cur = *h;

	if ((*h) == NULL)
	{
		printf("List is empty!!");
		exit(0);
	}
	else
	{

		while (cur->next != NULL)
		{
			pre = cur;
			cur = cur->next;
			counter++;

			if (cur->val == value)
			{
				if (cur->next == NULL)
					delete_from_end(h, p);
				
				else if (counter == 1)
					delete_from_begin(h);
				
				else
				{
					pre->next = cur->next;
					cur->next = NULL;
				}
				cnt--;
				break;
			}	
		}
		if (cnt == cnt - 1)
			printf("Successfully deleted %d from list:)\n", value);
		else
		{
			printf("Value doesn't exists in then list!!\n");
			exit(0);
		}
	}
}

void delete_pos(struct node **h, struct node **p, int pos, int cnt)
{
	int counter = 0;
	struct node *cur = NULL;
	struct node *pre = NULL;
	
	cur = *h;
	if (pos > cnt)
		printf("Invalid Position!!.:\n");

	else if (pos < cnt)
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
	printf("NULL\n");
}

//Creating a list

void list(struct node **h)
{
	struct node *t = NULL;
	t = *h;

	while (1)
	{
		int no;
		no = read();
		if (no != -1)
		{
			insert(&(*h), &t, no);
		}
		else 
			break;
	}
}

//Sorting

void sort(struct node **h, struct node **t)
{
	struct node *min = NULL;
	struct node *pre = NULL;
	struct node *cur = NULL;

	if ((*t)->next != NULL)
	{
		pre = *h;
		cur = pre->next;

		while ((*t)->next != NULL)
		{
			while (cur != NULL)
			{
				int mins = (*t)->val;
				min = *t;

				if (cur->val < mins)
				{
					mins = cur->val;	
					min = cur;
				// 	pre = cur
				// 	cur = cur->next; 
				}

				// else 
				// {
					pre = cur;
					cur = cur->next;
				// }
			}

			(*t)->next = min->next;
			pre->next = *t;

			if (*t == *h)
				*h = *t;

			min = *t = min->next;
		}

	}

	*t = *h;
}
