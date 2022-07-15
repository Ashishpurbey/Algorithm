#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>>dp(101,vector<ll>(10001,-1));



ll rec(vector<ll>&v,ll index,ll size,ll sum){
  if(sum<0)return 0;
  if(sum==0)return 1;
  if(index>=size)return 0;
  if(dp[index][sum]!=-1)return dp[index][sum];
  ll ans1=rec(v,index+1,size,sum);
  ll ans2=rec(v,index+1,size,sum-v[index]);
  dp[index][sum]=(ans1|ans2);
  return ans1|ans2;
}
void findpath(vector<ll>&v,ll index,ll size,ll sum){
    if(dp[index][sum]==1){
        if(dp[index+1][sum]==1){
           findpath(v,index+1,size,sum);
        }else{
            findpath(v,index+1,size,sum-v[index]);
            cout<<v[index]<<" ";
        }
    }
}

int main(){
    freopen("input.txt","r",stdin);
   ll n;
   cin>>n;
   vector<ll>v(n);
   for(auto &it:v)cin>>it;
   ll sum;
   cin>>sum;
   ll ans=rec(v,0,n,sum);
   if(ans==1)cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

   if(ans==1){
       findpath(v,0,n,sum);
   }









    return 0;
}