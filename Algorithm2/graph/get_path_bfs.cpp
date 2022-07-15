#include<bits/stdc++.h>
using namespace std;
#define ll long long
void bfs_print(vector<vector<int>>adj,int root,vector<int>&visit,vector<int>&store){
  visit[root]=1;
  queue<int>qu;
  qu.push(root);
  store[root]=-1;
   while(!qu.empty()){
		int current=qu.front();
		qu.pop();
		for(int i=0;i<adj[current].size();i++){
			if(visit[adj[current][i]]==1) continue;
			else{
				visit[adj[current][i]]=1;
				qu.push(adj[current][i]);
				store[adj[current][i]]=current;
			}
		}
	}
}

int main(){
  // freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
   int v,e,find;
   cin>>v>>e>>find;
   int a,b;
   vector<vector<int>>adj(v+1);
   for(int i=1;i<=e;i++){
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
   }
   vector<int>visit(v+1,0);
   vector<int>store(v+1,-1);
   bfs_print(adj,0,visit,store);
   if(find==0) cout<<0;
   else if(store[find]==-1) cout<<"not find";
   else {
      int p=store[find];
      cout<<find<<endl;
      while(p!=-1){
         cout<<p<<endl;
         p=store[p];
      }
   }
   return 0;
}