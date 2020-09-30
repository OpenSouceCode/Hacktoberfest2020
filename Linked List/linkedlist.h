#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int val;
	struct node *next;
};

int read();
struct node *create(int value);
void insert(struct node **h, struct node **p, int value);
struct node *list(struct node *h);
void display(struct node *h);
int isSorted(struct node *h);
struct node *sort(struct node *h);
struct node *CreateSortedlist(struct node *h);
struct node *merge(struct node *h, struct node *h1, struct node *h2);




