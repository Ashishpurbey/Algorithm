#include<bits/stdc++.h>
using namespace std;

    int indp[100000];
    int outdp[100000];
    int sz[100000];
    //no of vertices
    int n;

    void indfs(int node,int par,vector<vector<int>>&adj){
        indp[node]=0;
        sz[node]=1;
        for(auto it:adj[node]){
            if(it!=par){
                indfs(it,node,adj);
                sz[node]+=sz[it];
                indp[node]+=indp[it]+sz[it];
            }
        }
    }

    void outdfs(int node,int par,vector<vector<int>>&adj){
        if(node==1)outdp[node]=0;
        else outdp[node]=outdp[par]+indp[par]-(indp[node]+sz[node])+(n-sz[node]);
        for(auto it:adj[node]){
            if(it!=par){
                outdfs(it,node,adj);
            }
        }
    }





int main(){
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;i++){
       int a,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }
    indfs(1,0,adj);
    outdfs(1,0,adj);
}



