#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&v,vector<int>&tree,int start,int end,int treeNode){
    if(start==end){ 
        tree[treeNode]=v[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(v,tree,start,mid,2*treeNode);
    buildTree(v,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
    return;
}

void updateTree(vector<int>&v,vector<int>&tree,int start,int end,int treeNode,int index,int val){
    if(start==end){
       v[index]=val;
       tree[treeNode]=val;
       return;
    }
    int mid=(start+end)/2;
    if(index<=mid){
        updateTree(v,tree,start,mid,2*treeNode,index,val);
    }else{
        updateTree(v,tree,mid+1,end,2*treeNode+1,index,val);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

  return;
}


int query(vector<int>&tree,int start,int end,int treeNode,int left ,int right){
    //completely outside the given range
     if(start>right || end<left){
         return 0;
     }
    //completely inside the given range
      if(start>=left && end<=right){
          return tree[treeNode];
      }

    //partially inside and partially outside
     int mid=(start+end)/2;
     int ans1=query(tree,start,mid,2*treeNode,left,right);
     int ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
     return ans1+ans2;

}





int main(){
   vector<int>v={1,2,3,4,5,6,7,8,9};
   vector<int>tree(4*v.size());
   // build Tree
   buildTree(v,tree,0,8,1);
   // update Tree
   updateTree(v,tree,0,8,1,5,10);
  //find query
   cout<<query(tree,0,8,1,4,6)<<endl;
   
    return 0;
}