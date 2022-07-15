#include<bits/stdc++.h>
#define ll long long
using namespace std;

void update(string &s,ll &l){
    if(s[l]!='0'){
    s[l]='0';
    for(ll i=l-1;i>=0;i--){
        if(s[i]=='9')s[i]='0';
        else {
            s[i]++;
            break;
        }

    }
    if(s[0]=='0'){
        reverse(s.begin(),s.end());
        s+='1';
        reverse(s.begin(),s.end());
        l++;
    }
    }
    else {
        ll p=0;
    }
}
ll sumdigit(string s){
    ll sum=0;
    for(ll i=0;i<s.length();i++)sum+=(s[i]-'0');
    return sum;
}
int main(){
    freopen("input.txt","r",stdin);
    ll t;
    cin>>t;
    while(t--){
        string a;
        ll k;
        cin>>a>>k;
        
        ll sum=sumdigit(a);
        if(sum<=k){
            cout<<0<<endl;
        }
        else {
            ll index=a.length()-1;
            ll val=0;
            ll add=1;
            while(sumdigit(a)>k){
                if(a[index]!='0')val=add*(10-(a[index]-'0'))+val;
                update(a,index);
                add*=10;
                index--;
            }
            cout<<val<<endl;
        }
        
    }
    return 0;
}