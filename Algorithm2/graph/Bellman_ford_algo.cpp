// kisi bhi index se kisi bhi index tak jane ka shorttest path batata hai
//complexity v*e;
// it also works for negative value
//if there is a  negative cycle then it fails;

//if we update nth times,and at that time its wt value is also change,it means that it has at lest one negative cycle


#include<bits/stdc++.h>
using namespace std;

#define vi vector<ll>
#define pii pair<ll,ll>
#define ll long long

int  bellman_ford(vector<vector<pii>>adj,vector<ll>&wt,int vertix){
   int cnt=0;
   for(int i=0;i<vertix;i++){
      for(int j=0; j<adj[i].size();j++){
          if(wt[adj[i][j].first]>wt[i]+adj[i][j].second){
              wt[adj[i][j].first]=wt[i]+adj[i][j].second;
              cnt++;
          }
      }
   }
   return cnt;
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
    int root=0;
    wt[root]=0;
    for(int i=0;i<V-1;i++){
        int val= bellman_ford(adj,wt,V);
    }
    for(ll i=0;i<V+1;i++)
    cout<<i<<" "<<wt[i]<<endl;

    // this is for finding the negative cycle in the graph
    // if(lg1>0)then there is a negative cylce,else not;
    // int lg1 = bellman_ford(adj,wt,V);
    // cout<<endl<<lg1<<endl;
    
    return 0;
}


