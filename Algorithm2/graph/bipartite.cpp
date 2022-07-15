#include<bits/stdc++.h>
using namespace std; 
#define ll long long
bool is_bipartite=true;
void dfs(int root,vector<vector<int>>adj,vector<int>&visit,ll color,vector<ll>&bipartite_color){
    visit[root]=1;
    bipartite_color[root]=color;
    for(int i=0;i<adj[root].size();i++){
        if(visit[adj[root][i]]==0){ 
          // visit[adj[root][i]]=1;
          dfs(adj[root][i],adj,visit,!color,bipartite_color);
        }else if(bipartite_color[adj[root][i]]==bipartite_color[root]){
          is_bipartite=false;
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
  vector<ll>bipartite_color(v+1,-1);
  vector<int>visit(v+1,0);
  dfs(1,adj,visit,0,bipartite_color);
  if(is_bipartite){
	  for(auto it:bipartite_color)cout<<it<<" ";
  }else{
	cout<<"NOT_BIPARTITE"<<endl;
  }
  return 0;
}