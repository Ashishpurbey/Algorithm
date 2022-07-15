/*this question is clear from its name that we have to make two sets such its differnce is equal to k  and how many types of sets is 
possible ,we have to tell*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int items;
    cin>>items;
    vector<int>v(items);
    for(int i=0;i<items;i++){
        cin>>v[i];
    }
    int diff ;
    cin>>diff;
    ll sum=0;
    for(int i=0;i<items;i++)sum+=v[i];
    ll p=(sum+diff);
    if(p%2!=0)cout<<"not possible"<<endl;
    else {
        ll check=p/2;
            vector<vector<int>>dp(items+1,vector<int>(check+1));
    for(int i=0;i<items+1;i++){
        for(int j=0;j<=check;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<items+1;i++){
        for(int j=1;j<=check;j++){
            if(v[i-1]>j)dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
            }
        }    
    }
    cout<<dp[items][check]<<endl;
    }
    return 0;
}