#include<bits/stdc++.h> 

using namespace std; 

/* A binary tree node has data, 
pointer to left child and 
a pointer to right child */
class node 
{ 
	public: 
	int value; 
	node* left; 
	node* right; 
	
	/* Constructor that allocates 
	a new node with the given data 
	and NULL left and right pointers. */
    node()
    {
        value=0;
        left=NULL;
        right=NULL;
    }
	node(int val) 
	{ 
		value = val; 
		left = NULL; 
		right = NULL; 
	} 
}; 

class BST
{   public:
        node *root;

        BST()
        {
            root=NULL;
        }
        
        bool isempty()
        {
            if(root==NULL)
                return true;
            else
                return false;
        }

        void insert(node *new_node)
        {
            if(root==NULL)
            {   
                root=new_node;
                cout<<"value inserted at the root";
            }
            else
            {
                node *temp=root;
                while(temp!=NULL)
                {

                    if(new_node->value < temp->value && temp->left ==NULL)
                        {
                            temp->left=new_node;
                            cout<<"value inserted at left";
                            break;
                        }
                    else if (new_node->value <temp->value)
                    {
                        temp=temp->left;
                    }
                    else if(new_node->value > temp->value && temp->right ==NULL)
                        {   
                            temp->right=new_node;
                            cout<<"value inserted at right";
                            break;
                        }
                    else if (new_node->value >temp->value)
                    {
                        temp=temp->right;
                    }
                    else if(new_node->value==temp->value)
                    {   cout<<"no duplicates!!!";
                        return ;
                    }
                }
            }
            
        }
        void printinorder(node *r)
        {
            if(r==NULL)
                return;
            printinorder(r->left);
            cout<<r->value<<" ";
            printinorder(r->right);
        }
        void printpreorder(node *r)
        {
            if(r==NULL)
                return ;
            cout<<r->value<<" ";
            printpreorder(r->left);
            printpreorder(r->right);
        }
        void printpostorder(node *r)
        {
            if(r==NULL)
                return;
            printpostorder(r->left);
            printpostorder(r->right);
            cout<<r->value<<" ";
        }
        
        void search(node *r,int ele)
        {
            if(r==NULL)
                return;
            if(r->value==ele)
            {   
                cout<<"element exixts\n";
                return;
            }
            else if(ele<r->value && r->left!=NULL)
                search(r->left,ele);
            else if(ele>r->value && r->right!=NULL)
                search(r->right,ele);
            else
                cout<<"element does not exist\n";
        }

        
    void deletion(node* r)
    {
        // Base case: empty tree
        if (r == nullptr)
            return;
      	queue<node*> queue;
    	queue.push(r);

	    node *temp;

	// loop till queue is empty
	    while (!queue.empty())
	    {
		// delete each node in the queue one by one after pushing their
		// non-empty left and right child to the queue
		temp = queue.front();
		queue.pop();

		if (temp->left)
		   queue.push(temp->left);

		if (temp->right)
		   queue.push(temp->right);

		// Important - delete front node ONLY after enqueuing its children
		delete temp;
	    }

        r = nullptr;
    }


        /* Returns true if the given 
        tree is a BST and its values 
        are >= min and <= max. */
        int isBSTUtil(node* node, int min, int max) 
        { 
            /* an empty tree is BST */
            if (node==NULL) 
                return 1; 
                    
            /* false if this node violates 
            the min/max constraint */
            if (node->value < min || node->value > max) 
                return 0; 
            
            /* otherwise check the subtrees recursively, 
            tightening the min or max constraint */
            return
                isBSTUtil(node->left, min, node->value-1) && // Allow only distinct values 
                isBSTUtil(node->right, node->value+1, max); // Allow only distinct values 
        } 
        /* Returns true if the given 
        tree is a binary search tree 
        (efficient version). */
        int isBST(node* node) 
        { 
            return(isBSTUtil(node, INT_MIN, INT_MAX)); 
        } 

        node *Array_toBST(int arr[],int start,int end)
        {   
            /* Base Case */
        if (start > end)  
            return NULL;  
  
        /* Get the middle element and make it root */
        int mid = (start + end)/2;  
        node *temp = newNode(arr[mid]);  
  
        /* Recursively construct the left subtree  
        and make it left child of root */
        temp->left = Array_toBST(arr, start,  
                                    mid - 1);  
  
        /* Recursively construct the right subtree  
        and make it right child of root */
        temp->right = Array_toBST(arr, mid + 1, end);  
  
        return temp;

            
        }
        node *newNode(int data)  
        {  
            node *new_node = new node(); 
            new_node->value = data;  
            new_node->left = NULL;  
            new_node->right = NULL;  
    
            return new_node;  
        } 

};



/* Driver code*/
int main() 
{ 

    BST obj;
    int val,choice;

	do
    {
        /* code */
        cout<<"enter 1 for insertion"<<endl;
        cout<<"enter 2 to print in the bst"<<endl;
        cout<<"enter 3 to print post the bst"<<endl;
        cout<<"enter 4 to print pre the bst"<<endl;
        cout<<"enter 5 to check whether a bst"<<endl;
        cout<<"enter 6 to search for the element\n";
        cout<<"enter 7 for deletion of the desired node\n";
        cout<<"enter 8 for making an array to bst\n";

        cout<<"enter 0 to exit the program"<<endl;

    cin>>choice;
    //why didnt we use stack initialization like Node n1 just to make this new_node to be globaaly available   
    switch(choice)
    {
        case 1:
        {
        cout<<"insert"<<endl;
        cout<<"enter the value to be inserted"<<endl;
        cin>>val;
        node *new_node=new node();//heap type of RAM allocation
        new_node->value=val;
        obj.insert(new_node);
        cout<<endl;
        break;
        }
        case 2:
        {
        cout<<"printinorder"<<endl;
        obj.printinorder(obj.root);
        cout<<endl;
        break;
        }
        case 3:
        {
        cout<<"printpostorder"<<endl;
        obj.printpostorder(obj.root);
        cout<<endl;
        break;
        }
        case 4:
        {cout<<"printpreoreder"<<endl;
        obj.printpreorder(obj.root);
        cout<<endl;
        break;
        }
        case 5:
        {
                if(obj.isBST(obj.root))
                    cout<<"yes a bst\n";
                else
                {
                cout<<"not a bst\n";
                }
        break;
        }
        case 6:
        {   int element;
            cin>>element;
            obj.search(obj.root,element);
        }
        case 7://not yet completed
        {
            // int element;
            // cin>>element;
            obj.deletion(obj.root);
        }
        case 8:
        {   int len;
            cin>>len;
            int arr[len];
            for (int i=0;i<len;i++)
            {
                cin>>arr[i];
            }
            int n=sizeof(arr)/sizeof(arr[0]);
            sort(arr,arr+n);

            obj.Array_toBST(arr,0,len);
        }

    }
    } while (choice !=0);

		
	return 0; 
} 



