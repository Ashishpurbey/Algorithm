#include<bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  Node* next=NULL;
};

//gives the pointer of head
Node * takeInput(){
   //when user enters -1,at that time we terminate;
    Node *head=NULL;
    Node *pre=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        // we have to create our node dynamically,because after every iteration it will vanishes.
      Node * n=new Node;
      n->val=data; 
      if(head == NULL)head=n;

      if(pre==NULL)pre=n;
      else{
          pre->next=n;
          pre=n;
      }

      cin>>data; 
    }
   return head;
}

void insertNode(Node * &head ,int ind,int data){
    Node * newnode=new Node;
    newnode->val=data;
    //if we have to insert at start
    if(ind==1){
        newnode->next=head;
        head=newnode; 
        return;
    }
    //otherwise
    Node *p=head;
    for(int i=2;i<ind;i++){
      p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    return;
}


void Delete(Node * &head,int pos){
    
    //if we have to delete the first element
    if(pos==1){
        head=head->next;
        return;
    }
    Node *p=head;
    for(int i=2;i<pos;i++)p=p->next;
    p->next=p->next->next;
    return;
} 



//print linked list
void print(Node *head){
    Node *p=head;
    if(p==NULL)cout<<"No element is present"<<endl;
    else cout<<"present list : ";
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}

//merge two sorted linked list
Node *merge(Node * h1,Node * h2){
  Node * newhead=NULL;
  Node * pre=NULL;
  // if one is already null
  if(h1==NULL)return h2;
  else if(h2==NULL)return h1;
  
  //seat newhead
  if(h1!=NULL && h2!=NULL){
     if(h1->val<h2->val){
       newhead=h1;
       pre=h1;
       h1=h1->next;
     }
     else{
       newhead=h2;
       pre=h2;
       h2=h2->next;
     } 
  }
  //works until one becomes null
  while(h1!=NULL && h2!=NULL){
     if(h1->val<h2->val){
       pre->next=h1;
       pre=h1;
       h1=h1->next;
     }else{
       pre->next=h2;
       pre=h2;
       h2=h2->next;
     }
  }
  //connect the rem with the pre
  if(h1!=NULL)pre->next=h1;
  else pre->next=h2;
  return newhead;
}


//length of linked list
int length(Node *h1){
  if(h1==NULL)return 0;
  int ans=1+length(h1->next);
  return ans;
}

//merge sort
Node *sortll(Node* h1,int l){
  if(h1==NULL)return h1;
  if(l==1){
    h1->next=NULL;
    return h1;
  }
  
  Node *h2=h1;
  Node *h3=h1;
  int p=l/2;
  // p--;
  while(p--){
    h3=h3->next;
  }
  int l1=l/2,l2=l/2;
  if(l%2!=0)l2++;
  
  Node *p1=sortll(h2,l1);
  Node *p2=sortll(h3,l2);
  Node *p3=merge(p1,p2);
  return p3;
}

Node *reverse_helper(Node *head,Node *pre,Node * &newhead){
  if(head==NULL){
    newhead=pre;
    return pre;
  }
  Node *p=reverse_helper(head->next,head,newhead);
  p->next=pre;
  return pre;
}



//reverse a linked list
Node * reverse(Node *head){
  Node *newhead=NULL;
  Node *p=reverse_helper(head,NULL,newhead);
  return newhead;
}


int main(){
   freopen("input.txt","r",stdin);
    //statically
    Node *head;
    Node p1,p2;
    p1.val=20;
    p2.val=30;
    p1.next=&p2;
    head=&p1;
    Node * head1=takeInput();
    // Node * head2= takeInput();
    // insertNode(head1,1,300);
    // Delete(head1,2);
    // Node * headd=merge(head1,head2);
    // print(headd);
    // cout<<endl;
    // cout<<length(headd);
    // print(head1);
    // cout<<endl;
    // print(head2);
    // cout<<endl;
    // cout<<length(head1);
    Node *newhead=sortll(head1,length(head1));
    print(newhead);
    Node *p4=reverse(newhead);
    print(p4);


    //Dynamically
    // Node *n3=new Node;
    // Node *n4=new Node;
    // n3->val=5;
    // n4->val=6;
    // n3->next=n4;
    // Node *head=n3;
    // Node *val=head;
    //  while(val!=NULL){
    //     cout<<val->val<<" ";
    //     val=val->next;
    // }
  
  return 0;



}