// kisi bhi index se kisi bhi index tak jane ka shorttest path batata hai
// this is the best method for distra,it works on both positive and negative weight

#include<bits/stdc++.h>
using namespace std;

#define vi vector<ll>
#define pii pair<ll,ll>
#define ll long long

void Dijkstra(ll root,vector<vector<pii>>adj,vector<ll>&wt){
    priority_queue<pii,vector<pii>,greater<pii>>qu;
    qu.push({0,root});
    wt[root]=0;
    while(!qu.empty()){
        pii current=qu.top();
        qu.pop();
        ll a=current.second;
        for(ll i=0;i<adj[a].size();i++){
            ll wt2=wt[adj[a][i].first];
            if(wt2>wt[a]+adj[a][i].second){
                wt[adj[a][i].first]=wt[a]+adj[a][i].second;
                qu.push({wt[a]+adj[a][i].second,adj[a][i].first});
            }
        }
    }
}


int main(){
    freopen("input.txt","r",stdin);
    ll V,E,a,b,weight;
    cin>>V>>E;
    vector<vector<pair<ll,ll>>>adj(V+1);
    for(ll i=0;i<E;i++){
        cin>>a>>b>>weight;
        adj[a].push_back({b,weight});
        // adj[b].push_back({a,weight});
    }
    vector<ll>wt(V+1,INT_MAX);
    int root=1;
    wt[root]=0;
    Dijkstra(root,adj,wt);
    for(ll i=0;i<V+1;i++)
    cout<<i<<" "<<wt[i]<<endl;
    return 0;
}


