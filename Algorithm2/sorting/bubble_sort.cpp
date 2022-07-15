#include<bits/stdc++.h>
using namespace std;

//sort 5 4 3 2 1
//bubble sort
//complexity O(n^2)
/*
1st pass    2nd pass   3rd pass  4th pass
5 4 4 4 4   4 3 3 3    3 2 2     2 1
4 5 3 3 3   3 4 2 2    2 3 1     1 2 
3 3 5 2 2   2 2 4 1    1 1 3     3 3
2 2 2 5 1   1 1 1 4    4 4 4     4 4
1 1 1 1 5   5 5 5 5    5 5 5     5 5 

similarity we do n-1 times */

void bubble_sort(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(v[j]>v[j+1])swap(v[j],v[j+1]);
        }
    }
}

int main(){
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   bubble_sort(v);
   for(auto it:v)cout<<it<<" ";
   cout<<endl;
   return 0;
}