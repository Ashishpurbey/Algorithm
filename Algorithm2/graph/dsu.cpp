#include<bits/stdc++.h>
using namespace std;
#define ll long long

//dsu is used for determining that two element from the same component

ll findparent(ll index,vector<ll>&parent){
    if(parent[index]==index)return index;
    return parent[index]=findparent(parent[index],parent);//path compression
}


int main(){
    ll v,e;
    cin>>v>>e;
    vector<vector<ll>>adj(v+1);
    for(int i=0;i<e;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
     
    vector<ll>rank(v+1,1),parent(v+1); 
    for(int i=0;i<=v;i++){
        parent[i]=i;
    }
     
    for(int i=1;i<=v;i++){
        for(auto it:adj[i]){
            ll x=findparent(i,parent);
            ll y=findparent(it,parent);
            //rank compression
            if(x!=y){
                if(rank[x]>rank[y]){
                   parent[y]=x;
                   rank[x]+=rank[y];
                }else{
                   parent[x]=y;
                   rank[y]+=rank[x];
                }
            }     
        }
    } 



    return 0;
}