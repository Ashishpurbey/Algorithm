#include<bits/stdc++.h>
using namespace std; 
#define ll long long
void print(vector<vector<int>>v,int n,int sv,vector<int>&visit){
    cout<<sv<<endl;
    visit[sv]=1;
    for(int i=1;i<n+1;i++){
        if(v[sv][i]==1){
            if(visit[i]==1) continue;
            print(v,n,i,visit);
        }
    }
}
int main(){
//  freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
   int n,e;
   cin>>n>>e;
   vector<vector<int>>v(n+1,vector<int>(n+1));
   for(int i=0;i<n+1;i++){
       for(int j=0;j<n+1;j++)
       v[i][j]=0;
   }
   for(int i=0;i<e;i++){
       int a,b;
       cin>>a>>b;
       v[a][b]=1;
       v[b][a]=1;
   }
   vector<int>visit(n+1,0);
   print(v,n,1,visit);


 return 0;
}