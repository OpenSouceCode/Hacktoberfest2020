#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int val;
	struct node *next;
};

int read();
struct node *create(struct node *h, int value);
void insert(struct node **h, struct node **p, int value);
void display(struct node *h);

//Creating a list
struct node *list(struct node *h);

// Circular list
struct node *Circularlist(struct node *h);

//Creating a sorted list
struct node *CreateSortedlist(struct node *h)

//Sorting
int isSorted(struct node *h);
struct node *sort(struct node *h);

// Merging twwo linked list
struct node *merge(struct node *h, struct node *h1, struct node *h2)

//Reverse a Singly LInked list
struct node *Reverse(struct node *h)
