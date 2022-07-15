// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

#include<bits/stdc++.h>
using namespace std;
vector<vector<string>>vd;

void printans(vector<vector<int>>&ans){
    vector<string>v;
    for(auto it:ans){
        string p="";
        for(auto it1:it){
            if(it1==0)p+='.';
            else p+='Q';
        }
        v.push_back(p);
    }
    vd.push_back(v);

    return;
}

bool is_safe(int r,int c,int n,vector<vector<int>>&ans){
    for(int i=0;i<r;i++)if(ans[i][c]==1)return false;
    int r1=r,c1=c;
    while(r1>=0 && c1>=0 && c1<n && r1<n){
        if(ans[r1][c1]==1)return false;
        r1--;
        c1++;
    }
     r1=r,c1=c;
    while(r1>=0 && c1>=0 && c1<n && r1<n){
        if(ans[r1][c1]==1)return false;
        r1--;
        c1--;
    }
    return true;
}


void findans(int r,int n,vector<vector<int>>&ans){
    if(r==n){
        printans(ans);
    }
    if(r<0  || r>=n )return;
    for(int i=0;i<n;i++){
        if(is_safe(r,i,n,ans)){
            ans[r][i]=1;
            findans(r+1,n,ans);
            ans[r][i]=0;
        }
    }
    return;
}

vector<vector<string> >solveNQueens(int n){
    vd.clear();
    vector<vector<int>>ans(n,vector<int>(n,0));
    findans(0,n,ans);
    return vd;
}

int main(){
    int n;
    cin>>n;
   vector<vector<string>>gp= solveNQueens(n);
}