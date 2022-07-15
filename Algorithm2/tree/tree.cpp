#include<bits/stdc++.h>
using namespace std;





struct TreeNode{
    int data;
    vector<TreeNode *>children;
};

                               
//take input in a recursive manner                                                                      
TreeNode * takeInput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode * root = new TreeNode;
    root->data=rootData;
    int n;
    cout<<"Enter no of children of"<<rootData <<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode * child=takeInput();
        root->children.push_back(child);
        
    }
    return root;
}

TreeNode *takeInput1(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    TreeNode * root  = new TreeNode;
    root->data=rootData;
    queue<TreeNode *>qu;
    qu.push(root);
    while(qu.size()!=0){
        TreeNode * top=qu.front();
        qu.pop();
        // int p=qu.front()->data;
        int n;
        cout<<"Enter no of children of "<<top->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int child ;
            cin>>child;
            TreeNode * newnode=new TreeNode;
            newnode->data=child;
            top->children.push_back(newnode);
            qu.push(newnode);
        }
    }
    return root;
}

//print tree in level order
void printlevelorder(TreeNode * root){
    if(root==NULL)return ;
    queue<TreeNode *>qu;
    qu.push(root);
    while(qu.size()!=0){
        TreeNode * top=qu.front();
        qu.pop();
        cout<<top->data<<":"<<" ";
        for(auto it:top->children){
            qu.push(it);
            cout<<it->data<<" ";
        }
        cout<<endl;
    }
}


//pre order
void printpreorder(TreeNode * root){
    if(root==NULL)return ;//edge case not base case
    cout<<root->data<<":";
    // for(auto it:root->children)cout<<it->data<<" ";
    // cout<<endl; 
    for(auto it:root->children){
        printpreorder(it);
    }
}

//post order
void printpostorder(TreeNode * root){
    if(root==NULL)return ;//edge case not base case
    // for(auto it:root->children)cout<<it->data<<" ";
    // cout<<endl; 
    for(auto it:root->children){
        printpostorder(it);
    }
        cout<<root->data<<":";

}

//delete tree
void deletetree(TreeNode * root){
    for(auto it:root->children){
        deletetree(it);
    }
    delete root;
}



//no of nodes
int node(TreeNode * root){
  if(root==NULL)return 0;
  int ans=1;
    for(auto it:root->children){
        ans+=node(it);
    }
  return ans;

}

//find height of a tree
int height(TreeNode * root){
    if(root==NULL)return 0;
    int ans=0;
    
    for(auto it:root->children){
       ans=max(ans,height(it));
    }
    return ans+1;
}

//print all node a level k
void print_node_at_level_k(TreeNode * root,int k){
    if(root==NULL)return;
    if(k==0){
      cout<<root->data<<" ";
      return ;
    }
    for(auto it:root->children){
      print_node_at_level_k(it,k-1);
    }
    return;
}

//print no of leaf node
int leaf_node(TreeNode * root){
  if(root==NULL)return 0;
  if(root->children.size()==0)return 1;

  int ans=0;
  for(auto it:root->children){
      ans+=leaf_node(it);
  }
  return ans;

}





int main(){
    freopen("input.txt","r",stdin);
//   TreeNode * root=new TreeNode;
//   TreeNode * node1=new TreeNode;
//   TreeNode * node2=new TreeNode;

//  root->data=1;
//  node1->data=2;
//  node2->data=3;
 
//  root->children.push_back(node1);
//  root->children.push_back(node2);
  TreeNode * root=takeInput1();
//   printlevelorder(root);
//   cout<<endl;
//   cout<<node(root)<<endl;
//   cout<<height(root);
//   print_node_at_level_k(root,0);
cout<<leaf_node(root)<<endl;

    return 0;
}