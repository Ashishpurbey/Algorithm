#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length();
    int l2=s2.length();
    vector<vector<int>>dp(l1+1,vector<int>(l2+1));
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=0;
        }
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    int i=l1,j=l2;
    string ans;
    while(i!=0 && j!=0){
        if(s1[i-1]==s2[j-1]){
            ans+=s1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i][j-1]>dp[i-1][j]){
                ans+=s2[j-1];
                j--;
            }
            else {
                ans+=s1[i-1];
                i--;
        }
    }
    }
    if(i!=0){
        while(i!=0){
            ans+=s1[i-1];
            i--;
        }
    }
     if(j!=0){
        while(j!=0){
            ans+=s2[j-1];
            j--;
        }
    }
    

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}