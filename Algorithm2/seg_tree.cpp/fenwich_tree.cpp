#include<bits/stdc++.h>
using namespace std;

void update(int index,int value,vector<int>&BIT,int n){
    for(;index<=n;index+=index&(-index)){
        BIT[index]+=value;
    }
}

int query(int index,vector<int>&BIT){
    int sum=0;
    for(;index>0;index-=index&(-index)){
        sum+=BIT[index];
    }
    return sum;
}


int main(){
  
  int n;
  cin>>n;
  vector<int>ar(n+1,0);
  vector<int>BIT(n+1,0);
  
  for(int i=1;i<=n;i++){
      cin>>ar[i];
      update(i,ar[i],BIT,n);
  }

  cout<<"sum of first 5 elements "<<query(5,BIT)<<endl;
  cout<<"sum of elements from 2 index to 6 index"<<query(6,BIT)-query(1,BIT)<<endl;
    return 0;
}