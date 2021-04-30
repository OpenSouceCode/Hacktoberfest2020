// program to insert  or delete a node in a linked list 

#include "linkedlist2.h"

int count = 0;

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
			insert(&head, &temp, no);
			count++;
		}
		else 
			break;
	}

	printf("Linked List Operations.\n");
	printf("1.Create List\n");
	printf("2.Insert at beginning of List\n");
	printf("3.Insert at end of List\n");
	printf("4.Insert at a desired position in List\n");
	
	printf("\n5.Delete from beginning of List\n");
	printf("6.Delete from end of List\n");
	printf("7.Delete a desired value from List\n");
	printf("8.Delete from a desired position in List\n");

	int choice = 0;
	printf("Enter your choice: ");
	scanf("%d", &choice);

	int values = 0;
	int pos = 0;
	if ((choice >= 2 && choice <= 4) || choice == 7 || choice == 8)
	{
		count++;
		if (choice != 8)
		{
			printf("Enter Value to be operated: ");
			scanf("%d" , &values);
		}

		if (choice == 4 || choice == 8)
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
				insert_in_between(&head, &temp, &tail, pos, count); 
			break;

		case 5: delete_from_begin(&head);
			break;
		
		case 6: delete_from_end(&head, &tail);
			break;

		case 7: delete_value(&head, &tail, values, count);
			break;

		case 8: delete_pos(&head, &tail, pos, count);
			break;

		default : printf("Invalid Choice!!\n");
			break;		
	}
	
	temp = head;
	
	display(temp);
	
	printf("\n");
	return 0;	
}



