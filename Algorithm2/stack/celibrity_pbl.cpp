#include<bits/stdc++.h>
using namespace std;
#define ll long long
//celebrity:1>known by every body;
//          2>knows nobody;

//v[a][b]=1;means a knows b;
//v[b][a]=0;means a doesn't know b;


int main(){
    ll n;
    cin>>n;
    vector<vector<ll>>v(n,vector<ll>(n));
    for(auto &it:v)for(auto &it1:it)cin>>it1;
    stack<ll>st;
    for(int i=0;i<n;i++)st.push(i);
    while(st.size()!=1){
        ll p1=st.top();
        st.pop();
        ll p2=st.top();
        st.pop();
        if(v[p1][p2]==1)st.push(p2);
        else st.push(p1);
    }
    ll potential_ans=st.top();
    for(int i=0;i<n;i++){
        if(i==potential_ans)continue;
        else if(v[potential_ans][i]==0)continue;
        else {
            cout<<"There is no celebrity"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(i==potential_ans)continue;
        else if(v[i][potential_ans]==1)continue;
        else {
            cout<<"There is no celebrity"<<endl;
            return 0;
        }
    }

   cout<<"Celebrity"<<" "<<potential_ans+1<<endl;
   //+1 because of 1 based indexing;

    return 0;
}