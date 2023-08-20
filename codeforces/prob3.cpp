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
   
#endif



struct ash{
  ll start,end,value;
};

bool cmp(ash a,ash b){
    if(a.start<b.start)return true;
    else if(a.start==b.start){
        if(a.end<b.end)return true;
        else return false;
    }else return false;
}
ll n;

ll findans(ll idx,vector<ll>&start,vector<ll>&end,vector<ll>&value,vector<ll>&dp){
  if(idx>=n)return 0;
  if(dp[idx]!=-1)return dp[idx];
  auto it=upper_bound(start.begin(),start.end(),end[idx])-start.begin();
  ll ans1=value[idx]+findans(it,start,end,value,dp);
  ll ans2=findans(idx+1,start,end,value,dp);
  return dp[idx]= max(ans1,ans2);
}

void solve(){
    cin>>n;
    vector<ash>v(n);
    vector<ll>start(n),end(n),value(n);
    for(int i=0;i<n;i++){
      cin>>v[i].start>>v[i].end>>v[i].value;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        start[i]=v[i].start;
        end[i]=v[i].end;
        value[i]=v[i].value;
    }
    vector<ll>dp(n,-1);
    ll ans=findans(0,start,end,value,dp);
    cout<<ans<<endl;



  return;
}


int main()
{
#ifndef ONLINE_JUDGE
    InputOutput
#endif
        ios_base::sync_with_stdio(false); 
        cin.tie(0);cout.tie(0);   
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}