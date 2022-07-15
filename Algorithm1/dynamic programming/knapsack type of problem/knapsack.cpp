/*here we have to the find max profit by taking some items such that 
 its weight doesnot exceed the req_weight*/
#include<bits/stdc++.h>
using namespace std ;
int main(){
    int items;
    cin>>items;
    vector<int>value(items);
    vector<int>weight(items);
    for(int i=0;i<items;i++)cin>>value[i];
    for(int j=0;j<items;j++)cin>>weight[j];
    int req_weight;
    cin>>req_weight;
    vector<vector<int>>dp(items+1,vector<int>(req_weight+1));
    for(int i=0;i<=items;i++){
        for(int j=0;j<=req_weight;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=0;
        }
    }

    for(int i=1;i<=items;i++){
        for(int j=1;j<=req_weight;j++){
            if(weight[i-1]>j)dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=max(dp[i-1][j],value[i-1]+dp[i-1][j-weight[i-1]]);
            } 
        }
    }
    cout<<dp[items][req_weight]<<endl;
}