#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void convert_number_to_binary(int exponent,vector<int>&store){
    while(1){
        if(exponent==0 || exponent==1)break;
        int p = exponent%2;
        store.push_back(p);
        exponent=exponent/2;
    }
    store.push_back(exponent);
}


int main(){
    ll base, exponent;
    cin>>base>>exponent;
    vector<int>store;
    convert_number_to_binary(exponent,store);
    ll ans=base;
    ll sol=1;
    //for(auto it:store)cout<<it<<" ";
    for(int i=0;i<store.size();i++){ 
        if(store[i]==1){
            sol=(sol*ans)%mod;
        }
        ans=(ans*ans)%mod;
    }
    cout<<sol<<endl;
    return 0;
}