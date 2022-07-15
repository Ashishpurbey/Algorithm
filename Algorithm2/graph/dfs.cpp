#include<bits/stdc++.h>
using namespace std; 
#define ll long long
void dfs(int root,vector<vector<int>>&adj,vector<int>&visit){
  visit[root]=1;
  cout<<root<<" ";
  for(int i=0;i<adj[root].size();i++){
      if(visit[adj[root][i]]==0){ 
          // visit[adj[root][i]]=1;
          dfs(adj[root][i],adj,visit);
        }
    } 
}
int main(){
 //freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
 int v,e;
 cin>>v>>e;
 int a,b;
  vector<vector<int>>adj(v+1);
  for(int i=1;i<=e;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int>visit(v+1,0);
  dfs(1,adj,visit);
  return 0;
}