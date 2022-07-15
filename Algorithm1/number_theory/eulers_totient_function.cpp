/* for finding euler totient function formula for [n=n*(1-1/p)*(1-1/q)* (1-1/r)...]*/
/*where p,q,r are the distinct prime_factor of n;*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    for(int i=0;i<=n;i++)v[i]=i;
    for(int i=2;i<=n;i++){
        if(v[i]==i){
            int count=1;
            while(i*count<=n){
                v[i*count]=(v[i*count]*(i-1))/i;
                count++;
            }
        }
    }

    for(int i=1;i<=n;i++){
       cout<<i<<" : "<<v[i]<<endl;
    }
    return 0;
}