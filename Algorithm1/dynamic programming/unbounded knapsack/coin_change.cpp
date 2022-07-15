#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int change;
    cin>>change;

    vector<vector<int>>dp(n+1,vector<int>(change+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<change+1;j++){
            if(i==0)dp[i][j]= 0;
            if(j==0)dp[i][j]= 1;
        }
    }
     for(int i=1;i<n+1;i++){
         for(int j=1;j<change+1;j++){
             if(v[i-1]>j){
                 dp[i][j]=dp[i-1][j];
             }
             else {
                dp[i][j]=dp[i-1][j]+dp[i][j-v[i-1]];
             }
         }
     }

   cout<<dp[n][change]<<endl;
//    for(auto it:dp){
//    for(auto it1:it){cout<<it1<<" ";}
//    cout<<endl;
//    }
 return 0;
}