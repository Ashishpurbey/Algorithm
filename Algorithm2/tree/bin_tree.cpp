#include<bits/stdc++.h>
using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode * left=NULL;
    BinaryTreeNode * right=NULL;
};

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

void printInOrder(BinaryTreeNode * root){
    if(root==NULL)return;
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}



BinaryTreeNode * takeInput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1)return NULL;

    BinaryTreeNode * root=new BinaryTreeNode;
    root->data=rootData;
    BinaryTreeNode * left=takeInput();
    BinaryTreeNode * right=takeInput();
    root->left=left;
    root->right=right;
    return root;
}

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

//no of nodes
int noOfNodes(BinaryTreeNode * root){
   if(root==NULL)return 0;
   int ans=1+noOfNodes(root->left)+noOfNodes(root->right);
   return ans;
}







//build tree with inorder and preorder array
BinaryTreeNode * buildTreeHelper(int *in,int *pre,int inl,int inr,int prel,int prer){
    if(inl>inr || prel>prer){
      return NULL;
    }
    int rootData=pre[prel];
    BinaryTreeNode * root=new BinaryTreeNode;
    root->data=rootData;
    int rootIndex=-1;
    for(int i=inl;i<=inr;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    int l=rootIndex-1-inl+1;
    BinaryTreeNode * left=buildTreeHelper(in,pre,inl,rootIndex-1,prel+1,prel+l);
    BinaryTreeNode *right = buildTreeHelper(in,pre,rootIndex+1,inr,prel+l+1,prer); 
    root->left=left;
    root->right=right;
    return root;
}









BinaryTreeNode * buildTree(int *in,int *pre,int size){
    BinaryTreeNode *root = buildTreeHelper(in,pre,0,size-1,0,size-1);
    return root;
}

// find diameter
pair<int,int>diameterHelper(BinaryTreeNode * root){
    if(root==NULL){
        pair<int,int>p={0,0};
        return p;
    }
    pair<int,int>leftAns=diameterHelper(root->left);
    pair<int,int>rightAns=diameterHelper(root->right);
    int ld=leftAns.second;
    int lh=leftAns.first;
    int rd=rightAns.second;
    int rh=rightAns.first;
  
    int height=1+max(lh,rh);
    int diameter = max(lh+rh,max(ld,rd));
    cout<<height<<" "<<diameter<<" "<<root->data<<endl;
    return {height,diameter};
}

int Diameter(BinaryTreeNode * root){
    pair<int,int>ans=diameterHelper(root);
    // cout<<ans.first<<" "<<ans.second<<endl;
    return ans.second;
}






int main(){
    // freopen("input.txt","r",stdin);
    // BinaryTreeNode * root =new BinaryTreeNode;
    // BinaryTreeNode * node1 =new BinaryTreeNode;
    // BinaryTreeNode * node2 =new BinaryTreeNode;
    // root->data=1;
    // node1->data=2;
    // node2->data=3;
    // root->left=node1;
    // root->right=node2;
    // BinaryTreeNode * root=takeInput();
    // printTree(root);
    // cout<<endl;
    // BinaryTreeNode * root1=takeInputLevelWise();
    // printTree(root1);
    // cout<<endl;
    // printInOrder(root1);
    // cout<<noOfNodes(root1)<<endl;
    int pre[]={1,2,4,8,5,3,6,9,7,10};
    int po[]={1,3,7,10,6,9,2,5,4,8}; // in reverse order
    int in[]={5,4,6,2,1,7,3,9,8,10};


   BinaryTreeNode * root= buildTreeHelper1(po,pre,0,9,0,9);
   printPreOrder(root);
//    cout<<endl;
//    cout<<Diameter(root)<<endl;
   return 0;
}