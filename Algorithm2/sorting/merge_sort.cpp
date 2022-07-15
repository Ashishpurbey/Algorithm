#include<bits/stdc++.h>
using namespace std;

void merge_sort(vector<int>&v,int l,int r){
    if(l>=r)return;

    int mid=(l+r)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    //merge sorted array
    vector<int>left,right;
    for(int i=l;i<=mid;i++)left.push_back(v[i]);
    for(int i=mid+1;i<=r;i++)right.push_back(v[i]);
    int cnt=l;
    int l1=0,l2=0;
    while(l1<left.size() && l2<right.size()){
        if(left[l1]<=right[l2]){
            v[cnt]=left[l1];
            cnt++;
            l1++;
        }else{
            v[cnt]=right[l2];
            cnt++;
            l2++;
        }
    }
    while(l1<left.size()){
        v[cnt]=left[l1];
        cnt++;
        l1++;
    }
    while(l2<right.size()){
        v[cnt]=right[l2];
        cnt++;
        l2++;
    }
}



int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   merge_sort(v,0,n-1);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   return 0;
}