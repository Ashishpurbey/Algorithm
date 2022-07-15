#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
     string s1,s2;
     cin>>s1>>s2;
     if(s2.length()>s1.length()){
         sort(s1.begin(),s1.end(),greater<ll>());
         cout<<s1<<endl;
         return 0;
     }
     vector<ll>v(10,0);
     for(ll i=0;i<s1.length();i++){
         v[s1[i]-'0']++;
     }
    //  for(auto it:v)cout<<it<<" ";cout<<endl;
     string ans;
     ll p=0;
     for(ll i=0;i<s1.length();i++){
         if(v[s2[i]-'0']==0){
             p=i;
             break;
         }
         else {
             ans+=s2[i];
             v[s2[i]-'0']--;
             
         }
     }
     ll q=s2[p]-'0';
     for(ll i=q;i>=0;i--){
         if(v[i]>0){
             ans+=i+'0';
             v[i]--;
             break;
         }
     }
     for(ll i=9;i>=0;i--){
         while(v[i]>0){
             ans+=i+'0';
             v[i]--;
         }
     }
     cout<<ans<<endl;

    return 0;
}
