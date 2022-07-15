/*target sum-In this question there is a set of no. is given and we have to take all elements either with a + sign or - sign 
and then add them , we have tell that in how many ways we can make the arrangement such that is toatal sum is equal to k(which is given)*/
/*Approach--this question is more similar like to the  no_of_subset_with_given_difference because here we also have to make two sets one with 
a + sign and one with a - sign and actually we  have to subtract the + wala set from the - walla sets and this is equal to k 
so finally we have to make two sets such that its difference is k*/

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