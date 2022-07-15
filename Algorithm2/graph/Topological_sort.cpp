#include<bits/stdc++.h>
using namespace std;

// detect cycle in undirected graph
bool detect_cycle_in_directed_graph(int root,vector<vector<int>>&adj,vector<int>&visit,vector<int>&order,int V){
    visit[root]=1;
    order[root]=1;
    bool ans1=false;
    for(int i=0;i<adj[root].size();i++){
        if(visit[adj[root][i]]==0){
           bool ans = detect_cycle_in_directed_graph(adj[root][i],adj,visit,order,V);
           ans1=ans1|ans;
        }else{
            if(order[adj[root][i]]==1){
               ans1=true;
               return ans1;
            }
        }
    }
    order[root]=0;
    return ans1;
}

void topo(int root,vector<vector<int>>&adj,vector<int>&visit,stack<int>&st){
   visit[root]=1;
   for(int i=0;i<adj[root].size();i++){
       if(visit[adj[root][i]]==0){
           topo(adj[root][i],adj,visit,st);
       }
   }
   st.push(root);
}

void Topological_sort(vector<vector<int>>&adj,vector<int>&visit,stack<int>&st,int vertix){
   for(int i=1;i<=vertix;i++){
       if(visit[i]==0){
           topo(i,adj,visit,st);
       }
   }
   return;
}

int main(){
    freopen("input.txt","r",stdin);
    int V,E;
    cin>>V>>E;
    vector<vector<int>>adj(V+1);
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    

    vector<int>visit(V+1,0);
    // for finding that the grap is DAG or not,if not then return 0,else proceed
    for(int i=1;i<V+1;i++){
        vector<int>order(V+1,0);
        if(visit[i]==0){
            bool ans=detect_cycle_in_directed_graph(i,adj,visit,order,V);
            if(ans){
                cout<<"it has directed cyclic graph";
                return 0;
            }
        }
    }
  // if the function reaches here that means  it's directed acyclic graph

  stack<int>st;
  for(int i=0;i<=V;i++)visit[i]=0;
  Topological_sort(adj,visit,st,V);
  
  while(st.size()!=0){
    cout<<st.top()<<" ";
    st.pop();
  }

    return 0;
}