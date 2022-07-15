#include<bits/stdc++.h>
using namespace std;

//prims algo is also to be done in the similar way of dijkstra
int getmin(vector<int>&weight,vector<int>&visit,int v){
	int ans=-1;
	for(int i=0;i<v;i++){
      if(visit[i]==0 && ( ans==-1 || weight[ans]>weight[i])) ans=i;
	}
	return ans;
}

void prims(vector<vector<pair<int,int>>>&adj,int v){
	vector<int>parent(v);
	vector<int>weight(v,INT_MAX);
	vector<int>visit(v,0);
	weight[0]=0;
	parent[0]=-1;
	for(int j=0;j<v;j++){
		int minvertex=getmin(weight,visit,v);
		visit[minvertex]=1;
		// cout<<minvertex<<endl;
		for(int i=0;i<adj[minvertex].size();i++){
			if(adj[minvertex][i].second<weight[adj[minvertex][i].first] && visit[adj[minvertex][i].first]==0){
            weight[adj[minvertex][i].first]=adj[minvertex][i].second;
				parent[adj[minvertex][i].first]=minvertex;
				// cout<<adj[minvertex][i].second;
				// cout<<endl<<adj[minvertex][i].first<<endl;
			}
		}
	}
	for(int i=1;i<v;i++){
		cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
	}
}

int main(){
	freopen("input.txt","r",stdin);
  int v,e;
  cin>>v>>e;
   vector<vector<pair<int,int>>>adj(v);
   for(int i=0;i<e;i++){
      int a,b,c;
      cin>>a>>b>>c;
      adj[a].push_back({b,c});
	  adj[b].push_back({a,c});
   }
	prims(adj,v);
   return 0;
}
