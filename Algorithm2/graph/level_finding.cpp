#include<bits/stdc++.h>
using namespace std;


int level_finding(int root,vector<vector<int>>&adj,vector<int>&vis){
    vis[root]=1;
    if(adj[root].size()==1) return 1;
    int a=0;
    for(auto it:adj[root]){
        if(vis[it]==0){
            vis[it]=1;
            int b=level_finding(it,adj,vis);
            a=max(a,b);
        }
    }
    return a+1;
}


int main(){
    freopen("input.txt","r",stdin);
    int v,e;
    cin>>v>>e;
    int root;
    cin>>root;
    vector<vector<int>>adj(v+1);
   cout<<v<<" "<<e<<" "<<root<<endl;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(auto it:adj){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
    vector<int>vis(v+1,0);
    int ans=level_finding(root,adj,vis);
    cout<<ans;
    return 0;
}
