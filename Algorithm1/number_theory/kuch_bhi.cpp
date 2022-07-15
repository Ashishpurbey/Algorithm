#include<bits/stdc++.h>
using namespace std;
  vector<int>sieve(100001,1);
  #define ll long long 
int main(){
    sieve[0]=0,sieve[1]=1;
    for(int i=2;i*i<=100001;i++){
        if(sieve[i]==0)continue;
        int p=i;
        while(p*i<100001){
            sieve[i*p]=0;
            p++; 
        }
    }
    vector<int>fin_sieve;
    for(int i=2;i<=sieve.size();i++){
        if(sieve[i]==1)fin_sieve.push_back(i);
    }
        int t;
        cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        vector<ll>store(r-l+1,1);
        for(ll i=0;fin_sieve[i]*(ll)fin_sieve[i]<=r;i++){
            int current_prime=fin_sieve[i];
            int count=(l/current_prime);
            if(count==0)count++;
            while(count*fin_sieve[i]<=r){
                if((count*fin_sieve[i])-l<0){
                    count++;
                }
                else if(count*fin_sieve[i]==fin_sieve[i]){
                    count++;
                }
                else { 
                    store[(count*fin_sieve[i])-l]=0; 
                    count++;
                }
            }
        }
        for(int i=0;i<store.size();i++){
            if(store[i]==1)cout<<l+i<<endl;
        }
        //for(auto it:store)cout<<it<<endl;
    }
    return 0;
}