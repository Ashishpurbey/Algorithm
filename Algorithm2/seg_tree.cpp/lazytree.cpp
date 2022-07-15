#include<bits/stdc++.h>
using namespace std;

// find minimum element from range {l,r},
// update is also from {l1,r1};
void buildTree(vector<int>&arr,vector<int>&tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
    return;
}

void updateSegmentTreeLazy(vector<int>&tree,vector<int>&lazy,int low,int high,int startR,int endR,int curPos,int inc){
    if(low>high)return;
    if(lazy[curPos]!=0)tree[curPos]+=lazy[curPos];
    // update lazy tree
    if(low!=high){
        lazy[2*curPos]+=lazy[curPos];
        lazy[2*curPos+1]+=lazy[curPos];
    }
    lazy[curPos]=0;
    // No overlap 
       if(startR>high ||endR<low)return;
    //complete overlap
       if(startR <=low && high<=endR){
           tree[curPos]+=inc;
           if(low!=high){
               lazy[2*curPos]+=inc;
               lazy[2*curPos+1]+=inc;
           }
           return;
       }
    // partial overlap
    int mid=(low+high)/2;
    updateSegmentTreeLazy(tree,lazy,low,mid,startR,endR,2*curPos,inc);
    updateSegmentTreeLazy(tree,lazy,mid+1,high,startR,endR,2*curPos+1,inc);
    tree[curPos]=min(tree[2*curPos],tree[2*curPos+1]);
    return;
}
// query(tree,lazy,0,3,1,1,2);
int query(vector<int>&tree,vector<int>&lazy,int start,int end,int treeNode,int left ,int right){
    if(lazy[treeNode]!=0)tree[treeNode]+=lazy[treeNode];
        if(start!=end){
          lazy[2*treeNode]+=lazy[treeNode];
          lazy[2*treeNode+1]+=lazy[treeNode];
        } 
        lazy[treeNode]=0;
    //completely outside the given range
     if(start>right || end<left){

         return INT_MAX;
     }
    //completely inside the given range
      if(start>=left && end<=right){
          return tree[treeNode];
      }

    //partially inside and partially outside
     int mid=(start+end)/2;
     int ans1=query(tree,lazy,start,mid,2*treeNode,left,right);
     int ans2=query(tree,lazy,mid+1,end,2*treeNode+1,left,right);
     return min(ans1,ans2);

}

int main(){
   vector<int>arr={1,3,-2,4};
   vector<int>tree(4*arr.size());
   buildTree(arr,tree,0,3,1);
   vector<int>lazy(4*arr.size(),0);
      for(auto it:tree)cout<<it<<" ";cout<<endl;

   updateSegmentTreeLazy(tree,lazy,0,3,0,3,1,3);
      for(auto it:tree)cout<<it<<" ";cout<<endl;

   updateSegmentTreeLazy(tree,lazy,0,3,0,1,1,2);

   for(auto it:tree)cout<<it<<" ";cout<<endl;
   for(auto it:lazy)cout<<it<<" ";cout<<endl;

  int ans= query(tree,lazy,0,3,1,1,3);
  cout<<ans<<endl;

    return 0;
}