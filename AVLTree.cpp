
#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int h;
};


int hgt(Node *pres){
    int cnt=0;
    while(pres!=NULL){
        if(pres->left!=NULL && pres->right!=NULL)
            pres=(pres->left->h > pres->right->h)?pres->left:pres->right;
        else
        if(pres->left!=NULL)
            pres=pres->left;
        else
            pres=pres->right;
        cnt++;
    }
    return cnt;
}



int max(int a, int b);


int h(Node *N)
{
    if (N == NULL)
        return 0;
    return N->h;
}

int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->h = 1;
    return(node);
}


Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;


    x->right = y;
    y->left = T2;


    y->h = max(h(y->left),
                    h(y->right)) + 1;
    x->h = max(h(x->left),
                    h(x->right)) + 1;


    return x;
}


Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;


    y->left = x;
    x->right = T2;


    x->h = max(h(x->left),
                    h(x->right)) + 1;
    y->h = max(h(y->left),
                    h(y->right)) + 1;


    return y;
}


int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return h(N->left) - h(N->right);
}


Node* insert(Node* node, int key)
{

    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->h = 1 + max(h(node->left),
                        h(node->right));



    int bal = getBalance(node);





    if (bal > 1 && key < node->left->key)
        return rightRotate(node);


    if (bal < -1 && key > node->right->key)
        return leftRotate(node);


    if (bal > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (bal < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}
void pre(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        pre(root->left);
        pre(root->right);
    }
}


int main()
{
    Node *root = NULL;
    cout<<"Enter the number of nodes in AVL tree \n";
    int n;  cin>>n;
    cout<<"Enter the key values \n";
    for(int la=1;la<=n;la++){
        int num;
        cin>>num;
        root=insert(root, num);
    }

    cout << " Preorder traversal "<<endl;
    pre(root);
    cout<<endl;

    int height=hgt(root);
    cout<<" Height "<<height<<endl;

    return 0;
}
