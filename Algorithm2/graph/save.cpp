#include<bits/stdc++.h>
using namespace std;
int falg=0;
struct node{
    int x;
    int y;
};
void bfs(int i,int j,vector<vector<char>>&data,vector<vector<int>>&vis,queue<node>&qu,char match,int R,int C){
    node p;
    p.x=i;
    p.y=j;
    qu.push(p);
    vis[p.x][p.y]=0;
    while(!qu.empty()){
       node current=qu.front();
       qu.pop();
       vis[current.x][current.y]=1;
       if((current.x+1<R && current.x+1>=0 && data[current.x+1][current.y]==match && vis[current.x+1][current.y]!=1){
          if(vis[current.x+1][current.y]==0){
              flag=1;
              return ;
          }
          vis[current.x+1][current.y]=0;
          node r;
          r.x=curent.x+1;
          r.y=current.y;
          qu.push_back(r)
       }
           if((current.x+1<R && current.x+1>=0 && data[current.x+1][current.y+1]==match && vis[current.x+1][current.y+1]!=1){
          if(vis[current.x+1][current.y+1]==0){
              flag=1;
              return ;
          }
          vis[current.x+1][current.y+1]=0;
          node r;
          r.x=curent.x+1;
          r.y=current.y+1;
          qu.push_back(r)
       }
           if((current.x+1<R && current.x+1>=0 && data[current.x+1][current.y+1]==match && vis[current.x+1][current.y+1]!=1){
          if(vis[current.x+1][current.y+1]==0){
              flag=1;
              return ;
          }
          vis[current.x+1][current.y+1]=0;
          node r;
          r.x=curent.x+1;
          r.y=current.y+1;
          qu.push_back(r)
       }
           if((current.x+1<R && current.x+1>=0 && data[current.x+1][current.y+1]==match && vis[current.x+1][current.y+1]!=1){
          if(vis[current.x+1][current.y+1]==0){
              flag=1;
              return ;
          }
          vis[current.x+1][current.y+1]=0;
          node r;
          r.x=curent.x+1;
          r.y=current.y+1;
          qu.push_back(r)
       }
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<char>>data(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>data[i][j];
        }
    }
    vector<vector<int>>vis(r,vector<int>(c,-1));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(vis[i][j]==-1){
                queue<node>qu;
                bfs(i,j,data,vis,qu,data[i][j],r,c);
                if(falg==1){
                    cout<<1<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<0<<endl;
    return 0;
} vi