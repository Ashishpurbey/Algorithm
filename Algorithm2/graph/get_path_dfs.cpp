#include<bits/stdc++.h>
using namespace std; 
#define ll long long
void dfs(int root,vector<vector<int>>adj,vector<int>&visit,vector<int>&path,vector<int>&store){
  visit[root]=1;
  for(int i=0;i<adj[root].size();i++){
      if(visit[adj[root][i]]==1) continue;
      else {
          visit[adj[root][i]]=1;
          store[adj[root][i]]=root;
          dfs(adj[root][i],adj,visit,path,store);
        }
    } 
}
int main(){
 //freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
  int v,e;
  cin>>v>>e;
  int find;
  cin>>find;
  int a,b;
  vector<vector<int>>adj(v+1);
  for(int i=1;i<=e;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int>visit(v+1,0);
  vector<int>path;
  vector<int>store(v+1,-1);
  dfs(1,adj,visit,path,store);
   if(find==0) cout<<0;
  else if(store[find]==-1) cout<<"not find";
  else {
     int p=store[find];
     cout<<find<<endl;
      while(p!=-1){
          cout<<p<<endl;
          p=store[p];
        }
        cout<<0;
  }
  return 0;
}