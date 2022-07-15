//queue using linked list

#include<bits/stdc++.h>
using namespace std;

int sz=0;

struct Node {
    int data;
    Node * next=NULL;
};


int size(Node *head){
    return sz;
}


int isempty(Node *head){
    if(head==NULL)return 1;
    else return -1;
}

void push(Node * &head,Node * &tail,int data){
    Node * newnode = new Node;
    newnode->data=data;
    sz++;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}

void pop(Node * &head,Node * &tail){
    if(head==NULL){
        cout<<"Queueue is already empty"<<endl;
    }else if(head->next==NULL){
        head=NULL;
        tail=NULL;
        cout<<"Now queue become empty"<<endl;
        sz--;
    }else{
        head=head->next;
        sz--;
    }
}

int front(Node * &head,Node * &tail){
    if(head!=NULL){
        return head->data;
    }else return -1;
}

int back(Node * &head,Node * &tail){
    if(tail!=NULL)return tail->data;
    else return -1;
}



int main(){
    
    Node * head=NULL;
    Node * tail=NULL;

    push(head,tail,10);
    push(head,tail,20);
    push(head,tail,30);
    cout<<front(head,tail)<<endl;
    cout<<back(head,tail)<<endl;
    pop(head,tail);
    pop(head,tail);
    cout<<front(head,tail)<<endl;
    cout<<back(head,tail)<<endl;
    pop(head,tail);
    cout<<front(head,tail)<<endl;
    cout<<back(head,tail)<<endl;
    cout<<size(head)<<endl;



   return 0;
}