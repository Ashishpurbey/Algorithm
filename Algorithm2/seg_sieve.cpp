#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>prime;

void sieve(){
    vector<ll>prime1(1010000,1);

    prime1[0]=0;
    prime1[1]=0;
    for(ll i=2;i*i<=1000000;i++){
        if(prime1[i]==1){
            for(ll j=i*i;j<=1000000;j+=i)prime1[j]=0;
        }
    }
    for(int i=1;i<=1000000;i++){
        if(prime1[i]==1)prime.push_back(i);
    }
}

void seg_sieve(vector<ll>&v,int l,int r){
    for(auto it:prime){
        if(it*it>r)break;
        //just smaller or equal value to l
        ll base=(l/it)*it;
        if(base<l)base+=it;
        //mark all multiple within l to r as false;
        for(ll i=base;i<=r;i+=it){
            v[i-l]=0;
        }
        //there may be a case where base is itself a prime
        if(base==it)v[base-l]=1;

    }
}


int_fast64_t main(){
    sieve();
    ll l,r;
    cin>>l>>r;
    vector<ll>v(r-l+1,1);
    seg_sieve(v,l,r);
    for(int i=0;i<=r-l;i++){
        if(v[i]==1)cout<<i+l<<" ";
    }
    cout<<endl;
    return 0;
}
















