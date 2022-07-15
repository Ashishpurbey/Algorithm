#include<bits/stdc++.h>
using namespace std;
struct node{
    int x;
    int y;
};

   node  extended_eculid(int a,int b){
       if(b==0){
           node ans;
           ans.x= 1;
           ans.y= 0;
           return ans;
        }
       node smallans=extended_eculid(b,a%b);
       node ans;
       ans.x=smallans.y;
       ans.y=smallans.x-(a/b)*smallans.y; 
       return ans;
    }

int main(){
    int a,b;
    cin>>a>>b;
    node smallans=extended_eculid(a,b);
    cout<<smallans.x<<endl;
    cout<<smallans.y<<endl;
    return 0;
}