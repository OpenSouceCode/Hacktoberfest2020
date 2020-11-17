#include <iostream>
using namespace std;

class TreeNode
{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode()
        {
            value=0;
            left =NULL;
            right = NULL;
        }
        TreeNode(int val)
        {
            value =val;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public:
        TreeNode *root;

        bool isempty()
        {
            if(root==NULL)
                return true;
            else
                return false;
        }
        void insert(TreeNode *new_node)
        {
            if(root==NULL)
            {   cout<<"y";
                root=new_node;
            }
            else
            {
                TreeNode *temp=root;
                while(temp!=NULL)
                {
                    if(new_node ->value==temp->value)
                    {   cout<<"no duplicates!!!";
                        return ;
                    }
                    else if(new_node->value < temp->value && temp->left ==NULL)
                        {
                            temp->left=new_node;
                            break;
                        }
                    else if (new_node->value <temp->value)
                    {
                        temp=temp->left;
                    }
                    else if(new_node->value > temp->value && temp->right ==NULL)
                        {
                            temp->right=new_node;
                            break;
                        }
                    else if (new_node->value >temp->value)
                    {
                        temp=temp->right;
                    }
                }
            }
            
        }
        void printinorder(TreeNode *r)
        {
            if(r==NULL)
                return ;
            printinorder(r->left);
            cout<<r->value;
            printinorder(r->right);
        }
};

int main()
{   
    int choice;
    BST obj;
    int val;
 
    do
    {
        /* code */
        cout<<"enter 1 for insertion"<<endl;
        cout<<"enter 2 for deletion"<<endl;
        cout<<"enter 3 search "<<endl;
        cout<<"enter 4 to clear the screen"<<endl;
        cout<<"enter 5 to print the bst"<<endl;
        cout<<"enter 0 to exit the program"<<endl;

    cin>>choice;
    TreeNode *newnode=new TreeNode();//heap type of RAM allocation
    cout<<endl<<newnode->value;
    //why didnt we use stack initialization like Node n1 just to make this new_node to be globaaly available   
    switch(choice)
    {
        case 1:
        cout<<"insert";
        cin>>val;
        newnode->value=val;
        obj.insert(newnode);
        cout<<endl;
        break;
        case 2: cout<<"del";
        break;
        case 3:
        cout<<"search";
        break;
        case 4:
        system("cls");
        break;
        case 5:
        obj.printinorder(obj.root);
        cout<<endl;
        cout<<"print";
        break;
    }
    } while (choice !=0);

    return 0;
}