#include<bits/stdc++.h>
using namespace std;
#define ll long long


int aroot=0;

// normal bfs for find the larges distace from root
void bfs(vector<vector<ll>> adj, ll root, vector<ll> &visit)
{
    visit[root] = 1;
    queue<ll> qu;
    qu.push(root);
    while (!qu.empty())
    {
        ll current = qu.front();
        aroot=current;
        qu.pop();
        // cout<<current<<" ";
        for (ll i = 0; i < adj[current].size(); i++)
        {
            if (!visit[adj[current][i]])
            {
                visit[adj[current][i]] = visit[current] + 1;
                qu.push(adj[current][i]);
            }
        }
    }
}
 

// bfs used for finding the distace of every node from the node which is largest from the root 
 void bfs_dia(vector<vector<ll>> adj, ll root, vector<ll> &visit,vector<ll>&degree)
{
    visit[root] = 1;
    degree[root]=1;
    queue<ll> qu;
    qu.push(root);
    while (!qu.empty())
    {
        ll current = qu.front();
        aroot=current;
        qu.pop();
        // cout<<current<<" ";
        for (ll i = 0; i < adj[current].size(); i++)
        {
            if (!visit[adj[current][i]])
            {
                visit[adj[current][i]] = visit[current] + 1;
                degree[adj[current][i]]=degree[current]+1;
                qu.push(adj[current][i]);
            }
        }
    }
}

int main()
{
     ll v,e;
    cin>>v>>e;
  vector<vector<ll>>adj(v+1);
  for(int i=0;i<e;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
 
  vector<ll>visit(v+1,0);

  bfs(adj,1,visit);
  for(int i=0;i<=v;i++)visit[i]=0;
  vector<ll>degree(v+1,0);
  
  bfs_dia(adj,aroot,visit,degree);
  cout<<*max_element(degree.begin(),degree.end())-1<<endl;
    return 0;
}