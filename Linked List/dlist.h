#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct dnode
{
	struct dnode *next;
	int val;
	struct dnode *prev;
};

int read();
struct dnode *create(int value);
void insertDnode(struct dnode **h, struct dnode **p, int value);
void CreateDList(struct dnode **h, struct dnode **p);
void display(struct dnode *h);



