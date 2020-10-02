#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *rmvDup(struct Node *head){
    if(head == NULL)
        return head;
    struct Node *ptr = head;
    struct Node *p = ptr->next;

    while (ptr->next != NULL)
    {
        
        if(ptr->data == p->data){
            
            p = p -> next;
            
            
            if(p == NULL){
                ptr->next = p;
                
            }
        }
        else
        {
            ptr->next = p;
            ptr = p;
            p = p->next;
            


        }
        
    }
    
    return head;
    
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *four;
    struct Node *five;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    four = (struct Node *)malloc(sizeof(struct Node));
    five = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    (*head).next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = four;

    four->data = 3;
    four->next = five;

    five->data = 3;
    five->next = NULL;
    head = rmvDup(head);
    linkedlisttraversal(head);

    return 0;
}