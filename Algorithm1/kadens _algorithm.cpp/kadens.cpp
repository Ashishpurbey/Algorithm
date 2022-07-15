#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int current_value=v[0],max_value=v[0];
    for(int i=1;i<n;i++){
        current_value=max(v[i],v[i]+current_value);
        if(current_value>max_value)max_value=current_value;
    }
    cout<<max_value<<endl;
    return 0;
}