#include<bits/stdc++.h>
using namespace std;
#define ll long long

//method 1
// detect cycle in undirected graph
bool detect_cycle_in_directed_graph(int root,vector<vector<int>>&adj,vector<int>&visit,vector<int>&order,int V){
   visit[root]=1;
   order[root]=1;
   bool ans1=false;
//  cout<<adj[root].size()<<endl;
   for(int i=0;i<adj[root].size();i++){
       if(visit[adj[root][i]]==0){
           bool ans = detect_cycle_in_directed_graph(adj[root][i],adj,visit,order,V);
           ans1=ans1|ans;
        //    cout<<ans1<<" "<<adj[root][i]<<" "<<"from if"<<endl;
       }else{
           if(order[adj[root][i]]==1){
               ans1=true;
            //    cout<<ans1<<" "<<adj[root][i]<<" "<<"from else"<<endl;
               return ans1;
           }
       }
   }
   order[root]=0;
//    cout<<root<<" "<<ans1<<endl;
   return ans1;
}
void method1(ll V,ll E,vector<vector<int>>&adj){
   vector<int>visit(V+1,0);
    for(int i=1;i<V+1;i++){
        vector<int>order(V+1,0);
        if(visit[i]==0){
            bool ans=detect_cycle_in_directed_graph(i,adj,visit,order,V);
            if(ans){
                cout<<"YES"<<endl;
                return ;
            }
        }
    }
    cout<<"NO"<<endl;
    return;
}

// method2
//easy method
void dfs(ll node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(vis[adj[node][i]]==0){
            //Edge from (node-adj[node][i]) is a forward edge.
            dfs(adj[node][i],adj,vis);
        }else if(vis[adj[node][i]]==1){
            //Edge from (node-adj[node][i]) is a back edge.
            // if there is a back edge,that means graph has cycle.
        }else{
            //Edge from (node-adj[node][i]) is a cross edge.
            //cross edge doesn't from a cycle.
        }
    }
    vis[node]=2;
}




void method2(ll V,ll E,vector<vector<int>>&adj){
   vector<int>vis(V+1,0);
   for(int i=1;i<=V;i++){
       if(vis[i]==0){
          dfs(i,adj,vis);
       }
   }

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
    method1(V,E,adj);
    //easy method
    //concept of forward edge,back edge,cross edge
    //back edge means it has cycle
    // cross edge means it does not have cycle
    method2(V,E,adj);


   
    return 0;
}