//inserting at the beg
#include <bits/stdc++.h>
using namespace std ;
struct Node{
    int data;
    Node* next;
};

struct Node* head;//means head stores the address of our first node ie the head node

void insert(int x){
    Node* temp=new Node();
    temp-> data=x;
    temp-> next=head;
    head=temp;
    
}
void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
int main(){
    head=NULL;//means our pointer variable head do not store any address ie NULL
    int n,x;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cout<<"enter the num";
        cin>>x;
        insert(x);
        
    }
    print();
}