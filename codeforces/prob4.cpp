#ifndef Ashish
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// for pbds
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//  template<class T> using o_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

// typedef tree<
//     ll,
//     null_type,
//     less<ll>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;
// less_equal for multiset
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).
//
#define mod 1000000007
#define mod1 998244353
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
#define prll(v)           \
    for (auto it : v)      \
        cout << it << " "; \
    cout << endl;
#define InputOutput freopen("input.txt", "r", stdin); // freopen("output.txt","w",stdout);
#define MAX(v) *max_element(v.begin(), v.end())
#define MIN(v) *min_element(v.begin(), v.end())
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NUll);                   \
    cout.tie(NUll);
#endif

long long power(long long x,
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
long long modInverse(long long n,
                     ll p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(long long n,
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
        res = (res * i) % mod;
    return res;
}

// string r = s1.substr(1,3);
void dfs( vector<vector<ll>> &adj,ll root, vector<ll> &visit)
{
    visit[root] = 1;
    
    for (ll i = 0; i < adj[root].size(); i++)
    {
        if (visit[adj[root][i]] == 0)
        {
            dfs(adj,adj[root][i],  visit);
        }
    }
}

ll parent1(ll p, vector<ll> &parent)
{
    if (parent[p] == p)
    {
        return p;
    }
    return parent1(parent[p], parent);
}

void bfs(vector<vector<ll>> adj, ll root, vector<ll> &visit)
{
    visit[root] = 1;
    priority_queue<ll> qu;
    qu.push(root);
    while (!qu.empty())
    {
        ll current = qu.top();
        qu.pop();
        cout << current << " ";
        for (ll i = 0; i < adj[current].size(); i++)
        {
            if (!visit[adj[current][i]])
            {
                visit[adj[current][i]] = 1;
                qu.push(adj[current][i]);
            }
        }
    }
}

ll lcm(ll x, ll y)
{
    return ((x * y) / __gcd(x, y));
}
void prllpermutaion(vector<ll> &v, ll index)
{
    if (index == v.size() - 1)
        return;
    for (ll i = index; i < v.size(); i++)
    {
        swap(v[i], v[index]);
        prllpermutaion(v, index + 1);
        swap(v[i], v[index]);
    }
    return;
}

ll n=1e6+5;
   vector<vector<ll>>dp(1e6+10,vector<ll>(3,-1));
    vector<vector<ll>>dp1(1e6+10,vector<ll>(3,-1));

ll findans1(ll idx,ll pre,vector<vector<ll>>&dp1){
    if(idx>n)return 1;
    if(dp1[idx][pre]!=-1)return dp1[idx][pre];
    if(pre==1){
       return dp1[idx][pre]= (4*findans1(idx+1,1,dp1)%mod)%mod+(findans1(idx+1,2,dp1)%mod)%mod;
    }else{
       return dp1[idx][pre]= (1*findans1(idx+1,1,dp1)%mod+(2*findans1(idx+1,2,dp1)%mod)%mod)%mod;
    }
}

ll findans(ll idx,ll pre,vector<vector<ll>>&dp){
    if(idx>n)return 1;
    if(dp[idx][pre]!=-1)return dp[idx][pre];
    if(pre==1){
       return dp[idx][pre]= (4*findans(idx+1,1,dp)%mod)%mod+(findans(idx+1,2,dp)%mod)%mod;
    }else{
       return dp[idx][pre]= (1*findans(idx+1,1,dp)%mod+(2*findans(idx+1,2,dp)%mod)%mod)%mod;
    }
}


void solve(){
   cin>>n;
   //consider case for 1
   if(n==1){
    cout<<2<<endl;
    return ;
   }
   cout<<(dp[n][1]+dp[n][2]+dp1[n][1]+dp1[n][2])%mod;
  
   return;
}


int main()
{
#ifndef ONLINE_JUDGE
    InputOutput
#endif
        // IOS
        ll t = 1;
    cin >> t;
     ll ans=findans(1e6+5,1,dp);
   ll aans = findans1(1e6+5,2 ,dp1);
   

    while (t--)
    {
        solve();
    }
    return 0;
}