#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("input.txt","r",stdin);
    int v,e;
    cin>>v>>e;
    //for minima
    if((v+1)/2 <= e) cout<<0<<" ";
    else cout<<v-(e*2)<<" ";

    //for maxima
    vector<long long>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
  for(int i=3;i<100001;i++)
    vec.push_back(vec[i-1]+i);

    int index=lower_bound(vec.begin(),vec.end(),e)-vec.begin();
    index=index+1;
    if(e==1){
        if(v-e <=0) cout<<0<<endl;
        else cout<<v-(2*e)<<endl;
    }
    else if(e==2){
        if(v-3<=0) cout<<0<<endl;
        else cout<<v-3<<endl;
    }
    else {
        if(v-index<=0) cout<<0<<endl;
        else cout<<v-index<<endl;
    }
    return 0;
}



