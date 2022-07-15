#include<bits/stdc++.h>
using namespace std; 
#define ll long long
void bfs_print(vector<vector<int>>adj,int root,vector<int>&visit){
  visit[root]=1;
  queue<int>qu;
  qu.push(root);
  while(!qu.empty()){
    int current=qu.front();
    qu.pop();
    cout<<current<<" ";
    for(int i=0;i<adj[current].size();i++){
      if(!visit[adj[current][i]]){
        visit[adj[current][i]]=1;
        qu.push(adj[current][i]);
      }
    }
  }
}


int main(){
  freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
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
  bfs_print(adj,0,visit);
  return 0;
}