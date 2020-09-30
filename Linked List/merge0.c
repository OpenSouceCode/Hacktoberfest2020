// program to merge two sorted linked list 

#include "linkedlist.h"

int count = 0; 

int main()
{
	struct node *head = NULL;
	struct node *head1 = NULL;
	struct node *head2 = NULL;
	
	// struct node *temp = NULL;

	head1 = CreateSortedlist(head1); 
	
	head2 = CreateSortedlist(head2);

	head = merge(head, head1, head2);

	display(head);
	
	return 0;
}


