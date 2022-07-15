#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int  l1=s1.length();
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
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int length_of_lcs=dp[l1][l2];
    int no_of_deletion=l1-length_of_lcs;
    int no_of_insertion=l2-length_of_lcs;
    cout<<no_of_deletion<<" "<<no_of_insertion<<endl;
    return 0;
}