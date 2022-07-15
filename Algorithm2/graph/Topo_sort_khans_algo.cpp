#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
vector<vector<int>>g(100100);
vector<int>indegree(100100,0);
vector<int>topo;

// also used to detect cycle in directed graph
// all the node which is not available in topo vector,that definatley be a part of cycle


void kahn(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        topo.push_back(x);
        for(auto v:g[x]){
           indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return;
}





int main(){
    freopen("input.txt","r",stdin);
    int v,e;
    cin>>v>>e;
    while(e--){
       int a,b;
       cin>>a>>b;
       g[b].push_back(a);
       indegree[a]++;
    }
    kahn();
    if(topo.size()==v){
       cout<<"Topological order possible"<<endl;
       reverse(topo.begin(),topo.end());
       for(auto it:topo)cout<<it<<" ";
       cout<<endl;
    }else{
        cout<<"Topological order not possible"<<endl;
    }

    return 0;
}