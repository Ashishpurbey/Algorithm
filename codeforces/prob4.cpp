#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt=1;

void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n+1,0);
    for(ll i=1;i<=n;i++)cin>>v[i];
    for(ll i=1;i<=n;i++)v[i]+=v[i-1];
    // for(auto &it:v)cin>>it;
    ll m;
    cin>>m;
    vector<ll>v1(m+1,0);
    // for(auto &it:v1)cin>>v1;
    for(ll i=1;i<=m;i++)cin>>v1[i];
    for(ll i=1;i<=m;i++)v1[i]+=v1[i-1];

    map<ll,ll>mp,mp1;
    mp[0]=0;
    mp1[0]=0;

    for(ll i=1;i<=n;i++){
        ll ans=0;
       for(ll j=0;j<=i;j++){
          ll eans=v[j]+(v[n]-v[n-(i-j)]);
          ans=max(ans,eans);
       }
       mp[i]=ans;
    }

     for(ll i=1;i<=m;i++){
        ll ans=0;
       for(ll j=0;j<=i;j++){
          ll eans=v1[j]+(v1[m]-v1[m-(i-j)]);
          ans=max(ans,eans);
       }
       mp1[i]=ans;
    }

    ll k;
    cin>>k;
    ll ans=0;
    for(ll i=0;i<k;i++){
        ans=max(mp[i]+mp1[k-i],ans);
    }

   

    // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
    // cout<<endl;
    // for(auto it:mp1)cout<<it.first<<" "<<it.second<<endl;





    cout<<"Case #"<<cnt<<":"<<" "<<ans<<endl;
    cnt++;

}


int main(){
    freopen("input.txt","r",stdin);
    ll t;
    cin>>t;
    while(t--)solve();
    return 0;
}