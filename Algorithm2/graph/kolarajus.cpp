#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vii vector<vector<int>>
void dfs(int root,vii adj,vi &vis,stack<int> &st){
    vis[root]=1;
    for(int i=0;i<adj[root].size();i++){
        if(!vis[adj[root][i]]){
            dfs(adj[root][i],adj,vis,st);
        }
    }
    st.push(root);
}


int main(){
    freopen("input.txt","r",stdin);
    int V,E;
    cin>>V>>E;
    vii adj(V);
    vii revadj(V);
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        revadj[b].push_back(a);
    }
    stack<int>st;
    vi vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0;



}