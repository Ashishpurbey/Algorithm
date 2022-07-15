#include<bits/stdc++.h>
using namespace std;
#define ll long long

int cnt=1;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=n-1;i>=(n-k+1);i--)sum+=v[i];
    double val=0;
    for(int i=0;i<=n-k;i++)val+=(v[i]*1.000);
    val=val/(n-k+1);
    val+=sum;

    cout<<"Case #"<<cnt<<":"<<" "<<fixed<<setprecision(8)<<val<<endl;
    cnt++;

}


int main(){
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}