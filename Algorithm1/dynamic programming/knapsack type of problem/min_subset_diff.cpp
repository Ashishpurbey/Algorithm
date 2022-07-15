/*In this question we have to find two sets such that difference of the sum of all elements of the sets is minimum*/
/*Approach--In this question we have to find two sets such that its  difference is min. so,we just focus on one set because
the other set is automatically comes by taking the differce of the sum of all element with  the set which we consider,
now the max value of set one is the sum of all element of the the  globla set,now we have to check for the every value of sum 
is possible or not, according  to that the two sets are defined.
now this question is more similar like subset sum.
so we have to make a 2d array and fill  the array,such that each elemet tells us that this sum is possible using that no. of element,
and the last row tells us that which sum is possible .
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    ll Max=*max_element(v.begin(),v.end());
    ll sum=0;
    for(auto it:v)sum+=it;
    ll sum1=sum;
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=sum;j++){
           if(v[i-1]>j)dp[i][j]=dp[i-1][j];
           else {
               dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i-1]]);
           }
       }
    }
    int Min=INT_MAX,diff;
   for(int j=1;j<=sum;j++){
       if(dp[n][j]==1){
           int sum1=j,sum2=sum-j;
           diff=abs(sum1-sum2);
           Min=min(Min,diff);
       }
   }
  cout<<Min<<endl;
    return 0;
}