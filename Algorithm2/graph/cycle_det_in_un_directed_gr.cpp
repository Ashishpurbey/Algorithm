#include<bits/stdc++.h>
using namespace std;

// detect cycle in undirected graph
int find_parent(int root,vector<int>&parent){
   int p1=parent[root];
   int root1=root;
   while(root1!=p1){
     root1=p1;
     p1=parent[root1];
   }   
   // path compression
   root1=root;
   int p2=parent[root];
   parent[root1]=p1;

   while(p2!=root1){
       root1=p2;
       p2=parent[root1];
        parent[root1]=p1;

   }
   //upto that path compression
   return p1;
}



int main(){
    freopen("input.txt","r",stdin);
    int V,E;
    cin>>V>>E;
    vector<pair<int,int>>adj;
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        adj.push_back({a,b});
    }
    vector<int>parent(V+1,0);
    for(int i=1;i<=V;i++)parent[i]=i;
    
    for(auto it:adj){
        int a=it.first,b=it.second;
        int p1=find_parent(a,parent);
        int p2=find_parent(b,parent);
        if(p1==p2){
            cout<<"YES"<<endl;
            return 0;
        }else {
            parent[p1]=p2;
        }
    }

    cout<<"NO"<<endl;
    return 0;
}