#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Nearest greater to left

int main(){
    freopen("input.txt","r",stdin);
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it:v)cin>>it;
    stack<ll>st; 

    vector<ll>ans;
    for(int i=n-1;i>=0;i--){
        while(st.size()>0 && st.top()<=v[i])st.pop();
        if(st.size()==0)ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(v[i]);
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)cout<<it<<" ";
    cout<<endl;
    
    return 0;

}