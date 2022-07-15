//stack using linked list

#include<bits/stdc++.h>
using namespace std;

//we can caluculate size ,by simply decalaring a global vairable size and remove pos from Node.
// and update size after every push and pop function.
//like we do in queue section;



struct Node{
  int pos=1;  
  int data;
  Node *next;
};

void push(Node * &head,int data){
    Node * p=new Node;
    p->data=data;
    if(head!=NULL)p->pos=p->pos+head->pos;
    p->next=head;
    head=p;
}

void pop(Node * &head){
    if(head == NULL){
        cout<<"Stack is already empty"<<endl;
    }else{
        head=head->next;
    }
}

int top(Node * &head){
    if(head==NULL)return -1;
    else return head->data;
}

int size(Node * &head){
    if(head==NULL)return 0;
    else return head->pos;
}

//if empty return 1;
int isempty(Node * &head){
    if(head==NULL)return 1;
    else return -1;
}



int main(){
   Node *head=NULL;

   push(head,1);
   push(head,3);
   push(head,5);
   push(head,7);
   push(head,9);
   pop(head);
   cout<<top(head)<<endl;
   cout<<size(head)<<endl;
   push(head,11);
   cout<<top(head)<<endl;
   cout<<size(head)<<endl;
   cout<<isempty(head)<<endl;
    return 0;
}