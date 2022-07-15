#include<bits/stdc++.h>
using namespace std;

void kosaraju(int root,vector<vector<int>>&adj,vector<int>&visit,stack<int>&st){
    visit[root]=1;
    for(int i=0;i<adj[root].size();i++){
        if(!visit[adj[root][i]]){
            kosaraju(adj[root][i],adj,visit,st);
        }
    }
    st.push(root);
}

void print(int root,vector<int>&vis,vector<vector<int>>&revadj){
    cout<<root<<" ";
    vis[root]=1;
    for(int i=0;i<revadj[root].size();i++){
        if(!vis[revadj[root][i]])print(revadj[root][i],vis,revadj);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj(v);
    vector<vector<int>>revadj(v);
    for(int i=0;i<e;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
   
    revadj[b].push_back(a);
    }
    stack<int>st;
    vector<int>visit(v,0);
    for(int i=0;i<v;i++){
        if(!visit[i]){
            kosaraju(i,adj,visit,st);
        }
     }

    vector<int>vis(v,0);
    while(!st.empty()){
        if(vis[st.top()]==1)st.pop();
        else {
            print(st.top(),vis,revadj);
            cout<<endl;
        }
    }

    return 0;
}