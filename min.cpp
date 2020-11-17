#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	node* left; 
	node* right; 
}; 

/* Helper function that allocates a new node 
with the given data and NULL left and right 
pointers. */
struct node* newNode(int data) 
{ 
node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 

return(node); 
} 

/* Give a binary search tree and a number, 
inserts a new node with the given number in 
the correct place in the tree. Returns the new 
root pointer which the caller should then use 
(the standard trick to avoid using reference 
parameters). */
struct node* insert(struct node* node, int data) 
{ 
/* 1. If the tree is empty, return a new, 
	single node */
if (node == NULL) 
	return(newNode(data)); 
else
{ 
	/* 2. Otherwise, recur down the tree */
	if (data <= node->data) 
		node->left = insert(node->left, data); 
	else
		node->right = insert(node->right, data); 

	/* return the (unchanged) node pointer */
	return node; 
} 
} 

/* Given a non-empty binary search tree, 
return the minimum data value found in that 
tree. Note that the entire tree does not need 
to be searched. */
int minValue(struct node* node) 
{ 
struct node* current = node; 

/* loop down to find the leftmost leaf */
while (current->left != NULL) 
{ 
	current = current->left; 
} 
return(current->data); 
} 

/* Driver Code*/
int main() 
{ 
struct node* root = NULL; 
root = insert(root, 4); 
insert(root, 2); 
insert(root, 1); 
insert(root, 3); 
insert(root, 6); 
insert(root, 5); 

cout << "\n Minimum value in BST is " << minValue(root); 
getchar(); 
return 0; 
} 

// This code is contributed by Mukul Singh. 
