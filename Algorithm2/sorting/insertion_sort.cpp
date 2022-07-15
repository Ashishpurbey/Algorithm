#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>&v){
    int n=v.size();
    for(int i=1;i<n;i++){
        int p=v[i];
        int j=i-1;
        while(j>=0 && v[j]>p){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=p;
    }
}


int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   insertion_sort(v);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   return 0;
}