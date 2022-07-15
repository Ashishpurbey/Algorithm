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
    cout<<dp[l1][l2]<<endl;
    return 0;
}



//recursive sol
// #include<bits/stdc++.h>
// using namespace std;


// string s,t;

// int dp[1001][1001];
// int rec(int i,int j){
// 	if(i==s.length()||j==t.length()){
// 		return 0;
// 	}
// 	if(dp[i][j]!=-1){
// 		return dp[i][j];
// 	}
// 	// int ans;
// 	// if(s[i]==t[j]) ans = 1+rec(i+1,j+1);
// 	// else ans = max(rec(i+1,j),rec(i,j+1));
// 	// return dp[i][j] = ans;
// 	if(s[i]==t[j])return dp[i][j] = rec(i+1,j+1)+1;
// 	return dp[i][j] = max(rec(i+1,j),rec(i,j+1));
// }

// void solve(){
// 	cin>>s>>t;
// 	memset(dp,-1,sizeof(dp));
// 	cout<<rec(0,0)<<endl;
// }		

// signed main(){
// 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// 	int _t;cin>>_t;while(_t--)
// 	solve();
// }