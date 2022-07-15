/*in this  question we have to find a set such that sum of the element of the 
set is equal to the req_sum*/
/*Approach-- here either we have to include the no. or not ,we have only  two possibility
and it is similar like knapsack problem*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,req_sum;
    cin>>n>>req_sum;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<vector<int>>dp(n+1,vector<int>(req_sum+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=req_sum;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<=req_sum;j++){
            if(v[i-1]>j)dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1]]);
            }
        }    
    }
    if(dp[n][req_sum]==0)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}