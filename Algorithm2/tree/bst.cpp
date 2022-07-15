#include<bits/stdc++.h>
using namespace std;
//inorder traversal is sorted in bst





            ////////////// making the node of the tree /////////////////
struct BinaryTreeNode{
    int data;
    BinaryTreeNode * left=NULL;
    BinaryTreeNode * right=NULL;
};


  /////////////take input level wise in tree ////////////////
BinaryTreeNode * takeInputLevelWise(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    BinaryTreeNode *root = new BinaryTreeNode;
    root->data=rootData;
    queue<BinaryTreeNode *>qt;
    qt.push(root);
    while(qt.size()!=0){
        BinaryTreeNode * top=qt.front();
        qt.pop();
        int left,right;
        cin>>left>>right;
        if(left!=-1){
           BinaryTreeNode * leftnode=new BinaryTreeNode;
           leftnode->data=left;
           top->left=leftnode;
           qt.push(leftnode);
        }
        if(right!=-1){
           BinaryTreeNode * rightnode=new BinaryTreeNode;
           rightnode->data=right;
           top->right=rightnode;
           qt.push(rightnode);
        }
    }
    return root;
}

                ////////////// print preorder of the tree ///////////////////

void printPreOrder(BinaryTreeNode * root){
    if(root==NULL)return;
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<":"<<root->left->data<<" ";
    }

    if(root->right!=NULL){
        cout<<"R"<<":"<<root->right->data<<" ";
    }
    cout<<endl;
    printPreOrder(root->left);
    printPreOrder(root->right);
    return; 
}


 ////////////////return sum of the value of node which is in the range of l to r. ///////////////
int sumOfNode(BinaryTreeNode * root,int l,int r){
   int ans=0;
   if(root->data>=l && root->data<=r)ans+=root->data;
   if(root->data<=r)ans+=sumOfNode(root->right,l,r);
   if(root->data>=l)ans+=sumOfNode(root->left,l,r);
   return ans;
}



           /////////// search if the data in present in the tree of not //////////////
BinaryTreeNode * searchNode(BinaryTreeNode * root,int data){
    if(root==NULL)return NULL;
    if(data==root->data)return root;
    else if(data>root->data)return searchNode(root->right,data);
    else return searchNode(root->left,data);
}




                /////////////// build bst with sorted array ////////////

BinaryTreeNode * BST_with_sorted_array_helper(int *ar,int l,int r){
    if(l>r)return NULL;
    int mid=(l+r)/2;
    BinaryTreeNode * root= new BinaryTreeNode;
    root->data=ar[mid];
    BinaryTreeNode * left=BST_with_sorted_array_helper(ar,l,mid-1);
    BinaryTreeNode * right=BST_with_sorted_array_helper(ar,mid+1,r);
    root->left=left;
    root->right=right;
    // cout<<root->data<<" "<<mid<<endl;
    return root;
}

BinaryTreeNode * BST_with_sorted_array(int *ar,int n){
    BinaryTreeNode * root=BST_with_sorted_array_helper(ar,0,n-1);
    return root;
}




                    ////////////// is BST /////////////
struct bin{
    int minimum=INT_MAX,maximum=INT_MIN;
    bool val=true;
};

bin isBST_Helper(BinaryTreeNode * root){
    if(root==NULL){
        bin p;
        return p;
    }
    bin left=isBST_Helper(root->left);
    bin right=isBST_Helper(root->right);
    bin ans;
    if(left.maximum<root->data && right.minimum>root->data && left.val && right.val){
        ans.minimum=min(root->data,min(left.minimum,right.minimum));
        ans.maximum=max(root->data,max(left.maximum,right.maximum));
        ans.val=true;
        // cout<<root->data<<" "<<ans.minimum<<" "<<ans.maximum<<" "<<ans.val<<endl;
        return ans;
    }else{
        ans.minimum=min(root->data,min(left.minimum,right.minimum));
        ans.maximum=max(root->data,max(left.maximum,right.maximum));
        // cout<<root->data<<" "<<ans.minimum<<" "<<ans.maximum<<" "<<ans.val<<endl;
        ans.val=false;
        return ans;
    }
}

bool isBST(BinaryTreeNode *root){
   bin ans=isBST_Helper(root);
   return ans.val;
}




//making sorted linked list with a bst
struct LLNode{
  int data;
  LLNode * next=NULL;
};

//print linked list
void printLL(LLNode *head){
    LLNode *p=head;
    if(p==NULL)cout<<"No element is present"<<endl;
    else cout<<"present list : ";
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}


pair<LLNode*,LLNode*>BST_to_LL_helper(BinaryTreeNode * root){
    if(root==NULL)return {NULL,NULL};

    pair<LLNode*,LLNode*> left=BST_to_LL_helper(root->left);
    pair<LLNode*,LLNode*> right=BST_to_LL_helper(root->right);
    if(left.first==NULL && right.first==NULL){
        LLNode * p=new LLNode;
       p->data=root->data;
       return {p,p};
    }else if(left.first==NULL && left.second==NULL){
       LLNode * head=new LLNode;
       head->data=root->data;
       head->next=right.first;
       return {head,right.second};
    }else if(right.first==NULL && right.second==NULL){
       LLNode * p=new LLNode;
       p->data=root->data;
       left.second->next=p;
       return {left.first,p};
    }else{ 
        LLNode * p=new LLNode;
        p->data=root->data;
        left.second->next=p;
        p->next=right.first;
        return{left.first,right.second};
    }
}



LLNode *BST_to_LL(BinaryTreeNode * root){
    
    pair<LLNode*,LLNode*>head=BST_to_LL_helper(root);
    return head.first;
}


//print path from root to val
void printPath(BinaryTreeNode * root ,int data){
   cout<<root->data<<" ";
   if(root->data==data)return;
   if(data>root->data)printPath(root->right,data);
   if(data<root->data)printPath(root->left,data);
   return;
}





int main(){
    freopen("input.txt","r",stdin);
    // BinaryTreeNode * root=takeInputLevelWise();
    // if(isBST(root))cout<<"TRUE"<<endl;
    // else cout<<"FALSE"<<endl;

    int ar[]={1,2,3,4,5,6,7,8,9,10};
    BinaryTreeNode * root=BST_with_sorted_array(ar,10);
    printPath(root,1);
    // printPreOrder(root);
    // LLNode * p=  BST_to_LL(root);
    // printLL(p);
 


    return 0;
}