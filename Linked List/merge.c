// program to merge two linked list by index

#include <stdio.h>
#include <stdlib.h>
#include <linkedlist2.h> 

struct node
{
	int val;
	struct node *next;
};

int main()
{
	struct node *head = NULL;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	struct node *temp = NULL;
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;

	list(&head1);
	temp1 = head1;

	display(temp1);
	
	sort(&head1, &temp1);
	printf("Sorted List: ");
	display(head1);

	// list(&head2);
	// temp2 = head2;

	// sort(&head2);
	// printf("Sorted List: ");
	// display(head2);


	// for (int  i = 0; i < count; i++)
	// {
	// 	if (temp1 != NULL && temp2 != NULL)
	// 	{
	// 		if (temp1->val >= temp2->val)
	// 		{
	// 			temp->next = temp1;
	// 			temp1 = temp1->next;
	// 		}
	// 		else
	// 		{
	// 			temp->next = temp2;
	// 			temp2 = temp2->next;
	// 		}
	// 	}
	// 	else 
	// 	{
	// 		if (temp1 == NULL)
	// 		{
	// 			while (temp2 != NULL)
	// 			{
	// 				temp->next = temp2;
	// 				temp2 = temp2->next;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			while (temp1 != NULL)
	// 			{
	// 				temp->next = temp1;
	// 				temp1 = temp1->next;
	// 			}
	// 		}
	// 	}
	// }

	// temp = head;
	// printf("List: ");
	// display(temp);

	return 0;
}

int read()
{
	int value;
	printf("Enter number: ");
	scanf("%d", &value);

	return value; 
}

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


struct node *create(int value)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	newnode->val = value;
	newnode->next = NULL;

	return newnode;
}

void insert(struct node **h, struct node **p, int value)
{

	struct node *newnode = NULL;
	newnode = create(value); 
	
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

void display(struct node *h)
{
	while (h != NULL)
	{
		printf("%d\t", (h->val));
		h = h->next;
	}
	printf("NULL\n");
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




