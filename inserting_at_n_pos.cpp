#include <bits/stdc++.h>
using namespace std ;
struct Node{
    int data;
    Node* next;
};

struct Node* head;


void insert_n(int y,int pos){
    Node* temp=new Node();
    
    temp-> data=y;
temp-> next=NULL;
if(pos==1){
    temp->next=head;
    head=temp;
    return;
}
Node* temp2=head;
for(int i=0;i<pos-2;i++){
    temp2=temp2->next;
}
temp->next=temp2->next;
temp2->next=temp;
}
void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    
}
int main(){
    head=NULL;
    
   

    insert_n(2,1);
    insert_n(3,2);
    insert_n(4,1);
    print();
}