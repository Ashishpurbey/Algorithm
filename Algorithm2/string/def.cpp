#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

// void lps(string pattern,vector<int>&lp){
//     int l=0,r=1;
//     int n=pattern.length();
//     while(r<n){
//         if(pattern[l]==pattern[r]){
//             lp[r]=l+1;
//             l++;
//             r++;
//         }else{
//             if(l==0){
//                lp[r]=0;
//                r++;
//             }else{
//                 l=lp[r-1];
//             }
//         }
//     }
// }

// int KMP_search(string s,string pattern){
//    int s1=0,p1=0;
//   vector<int>lp(pattern.length(),0);
//   lps(pattern,lp);
//    while(s1<s.length() && p1<pattern.length()){
//       if(s[s1]==pattern[p1]){
//           s1++;
//           p1++;
//       }else{
//           if(p1==0){
//              s1++;
//           }else{
//              p1=lp[p1-1];
//           }
//       }

//    }

//    if(p1==pattern.length())return 1;
//    else return 0;

// }
int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &it : v)
            cin >> it;

        vector<vector<int>> dp(n, vector<int>(7, 0));
        dp[0][v[0] % 7] = 1;

        for (int i = 1; i < n; i++)
        {
            int p = v[i];
            int cnt = 1;
            while (p != 0)
            {
                p /= 10;
                cnt *= 10;
            }
            dp[i][v[i] % 7]++;
            for (int j = 0; j < 7; j++)
            {                                                                                                              
                int rem = (cnt * j + v[i]) % 7;
                dp[i ][j] += dp[i-1][j];
                dp[i ][rem] += (dp[i-1][j]);
                dp[i][j] %= mod;
                dp[i][rem] %= mod;
            }
        }

        cout << dp[n-1][0] % mod << endl;
    }

    return 0;
}