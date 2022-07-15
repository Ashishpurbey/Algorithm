#include<bits/stdc++.h>
using namespace std;

//selection sort
//find the sortest element in the array and put in the begging and increment the beginning by 1 and 
//then again find the element in the remaing array



void selection_sort(vector<int>&v){
    int n=v.size();
    int val=INT_MAX;
    int ind=0;
    for(int i=0;i<n-1;i++){
       val=INT_MAX;
       ind=0;
       for(int j=i;j<n;j++){
          if(v[j]<val){
            val=v[j];
            ind=j;
          }
       }
       swap(v[i],v[ind]);
    }
}




int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   selection_sort(v);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   return 0;
}