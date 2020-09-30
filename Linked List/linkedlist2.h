#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
	int val;
	struct node *next;
};


int read();
struct node *create(int value);
void insert(struct node **h, struct node **p, int value);

//Creating a list
struct node *list(struct node *h);

//Dispaly of ist
void display(struct node *h);

// Insertion operations
void insert_at_begin(struct node **h, struct node **t);
void insert_at_end(struct node **h, struct node **t, struct node **p);
void insert_in_between(struct node **h, struct node **t, struct node **p, int pos, int cnt);

//Deletion Operations
void delete_from_begin(struct node **h);
void delete_from_end(struct node **h, struct node **p);
void delete_value(struct node **h, struct node **p, int value, int cnt);
void delete_pos(struct node **h, struct node **p, int pos, int cnt);

//Sorting of list
void sort(struct node **h, struct node **t);


