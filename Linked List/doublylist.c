#include "dlist.h"

int main()
{
	struct dnode *head = NULL;
	struct dnode *tail = NULL;

	CreateDList(&head, &tail);

	struct dnode *temp = head;

	display(temp);

	return 0;
}