#include<bits/stdc++.h>
using namespace std;
//quick sort 
//element which is larger than the particular index,then it should have to be in the right of that element 
// and element which is smaller than the particular element it should be in the left.


void quick_sort(vector<int>&v,int l,int r){
    if(l>=r)return ;
    int l1=l,r1=r+1;
    while(l1<=r1 && l1<=r && r1>=l){
        l1++;
        r1--;
        while(l1<=r && v[l1]<v[l])l1++;
        while(r1>l && v[r1]>v[l])r1--;
        if(r1>l1)swap(v[r1],v[l1]);

    }
    swap(v[l],v[r1]);
    quick_sort(v,l,r1-1);
    quick_sort(v,r1+1,r);
}


int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   quick_sort(v,0,n-1);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   return 0;
}