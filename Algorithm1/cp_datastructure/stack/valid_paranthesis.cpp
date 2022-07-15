#include<bits/stdc++.h>
using namespace std;  
int main(){
    freopen("input.txt","r",stdin); 
    string s;
    cin>>s;
    stack<char>st;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]=='{' or s[i]=='(' or s[i]=='<' or s[i]=='['){
            st.push(s[i]);
        }
        else {
            if(st.empty() ==0 && st.top()=='<' && s[i]=='>')st.pop();
            else if(st.empty() ==0 &&st.top()=='(' && s[i]==')')st.pop();
            else if(st.empty() ==0 &&st.top()=='{' && s[i]=='}')st.pop();
            else if(st.empty() ==0 &&st.top()=='[' && s[i]==']')st.pop();
            else{
                cout<<"invalid paranthesis"<<endl;
                return 0;
            }
        }
    }
    if(st.empty()){
        cout<<"valid paranthesis"<<endl;
    }
    else cout<<"invalid paranthesis"<<endl;
    return 0;
}