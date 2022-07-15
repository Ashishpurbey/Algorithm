#include <bits/stdc++.h>
using namespace std;
#define ll long long
// if we find any back edge that means that graph has a cycle.
//  if we remove all the back edge,then the graph has no cycle
void dfs(int root, vector<vector<int>> adj, vector<int> &visit, ll parent)
{
  visit[root] = 1;
  for (int i = 0; i < adj[root].size(); i++)
  {
    if (visit[adj[root][i]] == 0)
    {
      // Edges from (root-adj[root][i]) is a forward edge
      dfs(adj[root][i], adj, visit, root);
    }
    else if (parent != adj[root][i])
    {
      // Edges from (node-adj[root][i]) is a back edge that means graph has cycle
    }
  }
}

int main()
{
  // freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
  int v, e;
  cin >> v >> e;
  int a, b;
  vector<vector<int>> adj(v + 1);
  for (int i = 1; i <= e; i++)
  {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int> visit(v + 1, 0);
  dfs(1, adj, visit, 0);
  return 0;
}