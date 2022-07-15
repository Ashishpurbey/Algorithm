/*In this question we have to make two sets such, sum of both the sets are equal 
and all given no. should definietyly be used */
/*Approach--here we have to divide the no. into to equal sets and it is only possible when 
the sum of all the elemnts is even ,so firstly we have to check that is the no. odd or even , if 
no. is odd dirctly our ans is no otherwise we  have to check that ans exist or not
 here we have to thik that which element is to be included or not we have two options ,
so we think about knapsack problem it is similar like that,*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll sum=0;
    for(auto it:v)sum+=it;
    if(sum%2!=0)cout<<"NO"<<endl;
    else {                       //knapsack
        vector<vector<int>>dp(n+1,vector<int>((sum/2)+1));
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=(sum/2);j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=(sum/2);j++){
                if(v[i-1]>j)dp[i][j]=dp[i-1][j];
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1]]);
                }
            }
        }
        if(dp[n][sum/2]==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}