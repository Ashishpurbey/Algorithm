#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={7,3,2,6,11,9,8,10,13};
    vector<int>ans(v.size(),0);
    stack<int>st;
    st.push(1);
    for(int i=1;i<v.size();i++){
        if(st.empty()){
            st.push(i+1);
        }
        else if(!st.empty() && v[st.top()-1]>v[i]){
           st.push(i+1);
        }
        else {
            while(!st.empty() && v[st.top()-1]<v[i]){
                ans[st.top()-1]=i+1;
                st.pop();
            }
            st.push(i+1);
        }
    }
    for(auto it:ans)cout<<it<<" ";cout<<endl;
    return 0;
}