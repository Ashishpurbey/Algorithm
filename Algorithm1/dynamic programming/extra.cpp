#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>>fac(1001,vector<ll>(1001,1));


int main(){
    freopen("input.txt","r",stdin);
    string s;
    cin>>s;
    vector<int>v(26,0);
    for(int i=0;i<s.length();i++)v[s[i]-'a']++;
    string q;
    cin>>q;
    int t;
    cin>>t;
    int count=0;
    for(int i=0;i<q.length();i++)if(q[i]=='*')count++;
    while(t--){
        string check;
        cin>>check;
        if(count==1){
            string s1,s2,s3;
            int i;
            for(i=0;i<q.length();i++){
                s1+=
            }
        }
        
        
    }


    
    return 0;
}