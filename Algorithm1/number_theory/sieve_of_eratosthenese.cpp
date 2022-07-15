#include<bits/stdc++.h>
using namespace std;
  vector<int>v(100000001,1);
int main(){
    int n;
    cin>>n;
  
    v[0]=0,v[1]=0;

    for(int i=2;i*i<=n;i++){
        if(v[i]==0)continue;
            int p=i;
            while(p*i<=n){
               v[i*p]=0;
               p++; 
            }
        }
        for(int i=0;i<=n;i++){
            if(v[i]==1){
                cout<<i<<" ";
            }
        }
    return 0;
}