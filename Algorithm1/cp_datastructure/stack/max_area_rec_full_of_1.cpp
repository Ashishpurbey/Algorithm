#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll max_area(vector<int>&v){
     int n=v.size();
     vector<int>left(n,-1);
     vector<int>right(n,n);
     stack<int>lf;
     stack<int>rf;
     for(int i=0;i<n;i++){
        if(rf.empty()){
        rf.push(i);
        }
        else if(!rf.empty() && v[i]>=v[rf.top()]){
            rf.push(i);
        }
        else {
            while(!rf.empty() && v[i]<v[rf.top()]){
                right[rf.top()]=i;
                rf.pop();
            }
            rf.push(i);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(lf.empty()){
            lf.push(i);
        }
        else if(!lf.empty() && v[i]>=v[lf.top()]){
            lf.push(i);
        }
        else {
            while(!lf.empty() && v[i]<v[lf.top()]){
                left[lf.top()]=i;
                lf.pop();
            }
            lf.push(i);
        }
    }
    vector<ll>sol(n);
    for(int i=0;i<n;i++){
        ll r=right[i]-1;
        ll l=left[i]+1;
        sol[i]=(r-l+1)*v[i];
    }
    ll ans = *max_element(sol.begin(),sol.end());
    return ans;
}
int main(){
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int r,c;
    cin>>r>>c;
    vector<vector<int>>data(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>data[i][j];
        }
    }
    for(int i=0;i<c;i++){
        for(int j=1;j<r;j++){
            if(data[j][i]==0)continue;
            else data[j][i]=data[j][i]+data[j-1][i];
        }
    }  
    vector<int>ans(r);
    for(int i=0;i<r;i++)ans[i]=max_area(data[i]);
    ll ans1=*max_element(ans.begin(),ans.end());
    cout<<ans1<<endl;
return 0;
}