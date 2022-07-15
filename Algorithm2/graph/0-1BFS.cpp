#include<bits/stdc++.h>
using namespace std;
#define ll long long

//complexity O(V+E);


vector<vector<pair<int,int>>>g(100100);
vector<int>dis(100100);
   int n,m;


void BFS01(ll sc){
    deque<int>dq;
    for(int i=1;i<=n;i++)dis[i]=1e9;
    dis[sc]=0;
    dq.push_back(sc);
    while(!dq.empty()){
        int xx=dq.front();
        dq.pop_front();
        for(auto v:g[xx]){
            int neigh=v.first;
            int weigh=v.second;
            if(dis[neigh]>dis[xx]+weigh){
               dis[neigh]=dis[xx]+weigh;
               if(weigh==0)dq.push_front(neigh);
               else dq.push_back(neigh);
            }
        }
    }

}


int main(){
    freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    int sc;
    cin>>sc;
    BFS01(sc);
    return 0;
}