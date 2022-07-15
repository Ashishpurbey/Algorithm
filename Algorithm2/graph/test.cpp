
#include <iostream>
#include <vector>
using namespace std;









 int flag=0;

void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&data,int index,int R,int C,char check,int r1,int c1){

    if(flag==1)return;
    if(r>=R || c>=C || r<0 || c<0)return ;
    if(!vis[r][c] && data[r][c]==check){
         if(index>=4){
      

        if(r-1==r1 && c==c1){
           flag=1;return;
        }
        else if(r==r1 && c-1==c1){
            flag=1;return;
        } else if(r==r1 && c+1==c1){
            flag=1;return;
        } else if(r+1==r1 && c==c1){
            flag=1;return;
        }
        
    }
        vis[r][c]=1;
   
        dfs(r+1,c,vis,data,index+1,R,C,check,r1,c1);
        dfs(r-1,c,vis,data,index+1,R,C,check,r1,c1);
        dfs(r,c+1,vis,data,index+1,R,C,check,r1,c1);
        dfs(r,c-1,vis,data,index+1,R,C,check,r1,c1);
    }
    vis[r][c]=0;   
}

bool hasCycle(vector<vector<char>> &Graph, int r, int c) {

	 vector<vector<char>>data(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            data[i][j]=Graph[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            
                vector<vector<int>>vis(r,vector<int>(c,0));
                dfs(i,j,vis,data,0,r,c,data[i][j],i,j);
                if(flag==1){
                    cout<<i<<" "<<j<<endl;
                    return true;
                }
            
        }
    }
    return false;
}



int main() {
    // freopen("input.txt","r",stdin);
    // int n, m;
    // cin >> n >> m;

    // vector<vector<char>> board(n, vector<char>(m));

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cin >> board[i][j];
    //     }
    // }

    // cout << (hasCycle(board, n, m) ? "true" : "false");
    vector<vector<int>>v(10);
    cout<<v[0].size()<<endl;
    return 0;
}