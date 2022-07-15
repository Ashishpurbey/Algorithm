#ifndef Ashish
#include <bits/stdc++.h>
using namespace std;
// for pbds
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// // template<class T> using o_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

// typedef tree<
// ll,
// null_type,
// less_equal<ll>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;
// cout<<*X.find_by_order(1)<<endl; 
// cout<<X.order_of_key(-5)<<endl;
//
#define ll long long
#define mod 1000000007
#define vll vector<ll>
#define vv vector<vector<ll>>
#define mll map<ll, ll>
#define sll set<ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) push_back(x)
#define f(i, a2, a3) for (ll i = a2; i < a3; i++)
#define fr(i, a2, a3) for (ll i = a2; i > a3; i--)
#define prll(v)            \
    for (auto it : v)      \
        cout << it << " "; \
    cout << endl;
#define InputOutput freopen("input.txt", "r", stdin); //freopen("output.txt","w",stdout);
#define MAX(v) *max_element(v.begin(), v.end())
#define MIN(v) *min_element(v.begin(), v.end())
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#endif

 long long power( long long x,
                         ll y, ll p)
{
     long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
 long long modInverse( long long n,
                              ll p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
 long long nCrModPFermat( long long n,
                                 ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
     long long fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void binary_Search(ll n, ll x_position, ll &cnt_big, ll &cnt_less)
{
    ll left = 0, right = n;

    while (left < right)
    {
        ll middle = (left + right) / 2;
        if (x_position >= middle)
        {
            if (x_position != middle)
                cnt_less++;
            left = middle + 1;
        }
        else if (x_position < middle)
        {
            cnt_big++;
            right = middle;
        }
    }
    // cout<<cnt_big<<" "<<cnt_less<<endl;
}

ll factorial(ll n)
{
    ll res = 1, i;
    for (i = 2; i <= n; i++)
        res = (res * i ) % mod;
    return res;
}

//  string r = s1.substr(1, 3);
void dfs(ll root, vector<vector<ll>> &adj, vector<ll> &visit, set<ll> &st,map<pair<ll,ll>,ll>&mp)
{
    visit[root] = 1;
    st.insert(root);
    //   cout<<root<<" ";
    for (ll i = 0; i < adj[root].size(); i++)
    {
        if (visit[adj[root][i]] == 0 && mp[{adj[root][i],root}]==0)
        {
            // visit[adj[root][i]]=1;
            dfs(adj[root][i], adj, visit, st,mp);
        }
    }
}
ll aroot=0;

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
// longest common subsequence increasing subsequence;
ll lcs(string s,string t,ll sl,ll tl,ll S,ll T,vector<vector<ll>>&dp){
   if(sl==S || tl==T)return 0;
   if(dp[sl][tl]!=-1)return dp[sl][tl];

   ll ans1=0,ans2=0;
   if(s[sl]==t[tl]){
       ans1=1+lcs(s,t,sl+1,tl+1,S,T,dp);
       dp[sl][tl]=ans1;
   }else{
       ans1=lcs(s,t,sl+1,tl,S,T,dp);
       ans2=lcs(s,t,sl,tl+1,S,T,dp);
       dp[sl][tl]=max(ans1,ans2);
   }
   return max(ans1,ans2);
}

void solve()
{
  ll a,b,k;
  cin>>a>>b>>k;
  vector<ll>boy(k);
  vector<ll>girl(k);
  for(auto &it:boy)cin>>it;
  for(auto &it:girl)cin>>it;
  ll cnt1=k;
  map<ll,ll>bo;
  map<ll,ll>gi;
  
  for(ll i=0;i<k;i++){
      bo[boy[i]]++;
      gi[girl[i]]++;
  }

  ll ans=0;
  for(ll i=0;i<k;i++){
      ll p1=bo[boy[i]];
      ll p2=gi[girl[i]];
    //   cout<<p1<<" "<<p2<<endl;
      ans+=(cnt1-(p1)-(p2)+1);
      bo[boy[i]]--;
      gi[girl[i]]--;
      cnt1--;

  }

cout<<ans<<endl;
    return;
}



int main()
{
#ifndef ONLINE_JUDGE
    InputOutput
#endif
        IOS

    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}