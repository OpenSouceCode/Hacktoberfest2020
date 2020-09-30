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
struct node *insert(struct node *h, int value);

// Creating a list
struct node *list(struct node *h);

//Display list
void display(struct node *h);

//
struct node *Reverse(struct node *h);


