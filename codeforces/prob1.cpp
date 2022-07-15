#ifndef Ashish
#include <bits/stdc++.h>
using namespace std;
#define ll long long

// for pbds
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
//  template<class T> using o_set = tree<T,nuint_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>

// typedef tree<
//     int,
//     nuint_type,
//     less<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update>
//     ordered_set;
// less_equal for multiset
// order_of_key (k) : Number of items strictly smainter than k .
// find_by_order(k) : K-th element in a set (counting from zero).
//
#define mod 1000000007
#define mod1 998244353
#define vint vector<int>
#define vv vector<vector<int>>
#define mint map<int, int>
#define sint set<int>
#define pint pair<int, int>
#define F first
#define S second
#define pb(x) push_back(x)
#define f(i, a2, a3) for (int i = a2; i < a3; i++)
#define fr(i, a2, a3) for (int i = a2; i > a3; i--)
#define print(v)           \
    for (auto it : v)      \
        cout << it << " "; \
    cout << endl;
#define InputOutput freopen("input.txt", "r", stdin); // freopen("output.txt","w",stdout);
#define MAX(v) *max_element(v.begin(), v.end())
#define MIN(v) *min_element(v.begin(), v.end())
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NUint);                   \
    cout.tie(NUint);
#endif

long long power(long long x,
                int y, int p)
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
                     int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(long long n,
                        int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fiint factorial array so that we
    // can find aint factorial of r, n
    // and n-r
    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void binary_Search(int n, int x_position, int &cnt_big, int &cnt_less)
{
    int left = 0, right = n;

    while (left < right)
    {
        int middle = (left + right) / 2;
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

int factorial(int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}

// string r = s1.substr(1,3);
void dfs( vector<vector<ll>> &adj,ll root, vector<ll> &visit)
{
    visit[root] = 1;
    
    for (int i = 0; i < adj[root].size(); i++)
    {
        if (visit[adj[root][i]] == 0)
        {
            dfs(adj,adj[root][i],  visit);
        }
    }
}

int parent1(int p, vector<int> &parent)
{
    if (parent[p] == p)
    {
        return p;
    }
    return parent1(parent[p], parent);
}

void bfs(vector<vector<int>> adj, int root, vector<int> &visit)
{
    visit[root] = 1;
    priority_queue<int> qu;
    qu.push(root);
    while (!qu.empty())
    {
        int current = qu.top();
        qu.pop();
        cout << current << " ";
        for (int i = 0; i < adj[current].size(); i++)
        {
            if (!visit[adj[current][i]])
            {
                visit[adj[current][i]] = 1;
                qu.push(adj[current][i]);
            }
        }
    }
}

int lcm(int x, int y)
{
    return ((x * y) / __gcd(x, y));
}
void printpermutaion(vector<int> &v, int index)
{
    if (index == v.size() - 1)
        return;
    for (int i = index; i < v.size(); i++)
    {
        swap(v[i], v[index]);
        printpermutaion(v, index + 1);
        swap(v[i], v[index]);
    }
    return;
}


void solve(){
	ll n;
    cin>>n;
    vector<ll>v1(n),v2(n),v3(n);
    
    for(auto &it:v1)cin>>it;
    for(auto &it:v2)cin>>it;
    for(auto &it:v3)cin>>it;
    if(n==1){
        cout<<1<<endl;
        return ;
    }
    vector<ll>visit(n+1,0);
    vector<vector<ll>>adj(n+1);
    for(int i=0;i<n;i++){
        adj[v1[i]].push_back(v2[i]);
        adj[v2[i]].push_back(v1[i]);
    }
    ll cnt=0;
    visit[0]=1;
    for(int i=0;i<n;i++){
        if(visit[v3[i]]==0){
            dfs(adj,v3[i],visit);

        } 
    }

    for(int i=0;i<n;i++){
        if(v1[i]==v2[i]){
            visit[v1[i]]=1;
        }
    }




    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            dfs(adj,i,visit);
            cnt++;
        }
    }
    ll ans=power(2,cnt,mod)%mod;
    cout<<ans<<endl;








    return ;
}


int main()
{
#ifndef ONLINE_JUDGE
    InputOutput
#endif
        // IOS
        int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}