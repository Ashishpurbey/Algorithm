#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stack<int>st;
    stack<int>st1;
    vector<int>left(n,-1);
    vector<int>right(n,n);
    st.push(0);
    st1.push(n-1);
    for(int i=1;i<n;i++){
        if(st.empty()){
            st.push(i);
        }
        else if(!st.empty() && v[st.top()]<=v[i]){
            st.push(i);
        }
        else {
            while(!st.empty() && v[st.top()]>v[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
    }
       for(int i=n-2;i>=0;i--){
        if(st1.empty()){
            st1.push(i);
        }
        else if(!st.empty() && v[st1.top()]<v[i]){
            st1.push(i);
        }
        else {
            while(!st1.empty() && v[st1.top()]>v[i]){
                left[st1.top()]=i;
                st1.pop();
            }
            st1.push(i);
        }
    }
     vector<int>ans(n);
     for(int i=0;i<n;i++){
         int r=right[i]-1;
        int  l=left[i]+1;
         ans[i]=(r-l+1)*v[i];
     }
     int ans1=*max_element(ans.begin(),ans.end());
     for(auto it:right){
         cout<<it<<" ";
     }
     cout<<endl;
     for(auto it:left)cout<<it<<" ";
     cout<<endl;
     cout<<ans1<<endl;
return 0;
}