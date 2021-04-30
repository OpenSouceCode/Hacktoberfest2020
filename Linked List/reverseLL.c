#include "LL.h"

int main()
{
	struct node *head = NULL;

	head = list(head);

	// display(head);

	head = Reverse(head);

	printf("Reverse List: ");
	display(head);

	return 0;
}
