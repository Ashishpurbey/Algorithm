#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define si set<int>

 void dfs(int  root,vector<vi>&adj,si&comp,vi&visit){
   visit[root]=1;
   comp.insert(root);
   for(int i=0;i<adj[root].size();i++){
       if(!visit[adj[root][i]]){
           visit[adj[root][i]]=1;
           dfs(adj[root][i],adj,comp,visit);
        }
    }
 }
 void getcomponent(vector<vi>&adj,int V,set<si>&component){ 
    vector<int>visit(V+1,0);
    for(int i=1;i<V+1;i++){
        if(!visit[i]){
            set<int>comp;
       
            dfs(i,adj,comp,visit);
            component.insert(comp);
        }
    }
 }
int main(){
    freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
    int V,E;
    cin>>V>>E;
    vector<vi>adj(V+1);
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
      //  adj[b].push_back(a);
    }
    set<si>component;
    getcomponent(adj,V,component);
    for(auto it:component){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}




