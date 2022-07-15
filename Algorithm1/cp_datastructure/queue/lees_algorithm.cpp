#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    int start_x,start_y,end_x,end_y;
    cin>>start_x>>start_y>>end_x>>end_y;
    pair<int,int>dest={end_x,end_y};
    int r,c;
    cin>>r>>c;
    int dx[] ={-1,1,0,0};
    int dy[] ={0,0,-1,1};
    vector<vector<int>>v(r+1,vector<int>(c+1,0));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>path(r+1,vector<int>(c+1,0));
    
    queue<pair<int,int>>q;
    path[start_x][start_y]=1;
    q.push({start_x,start_y});
     
    while(!q.empty()){
        pair<int,int>p=q.front();
        if(p==dest){
            cout<< path[p.first][p.second]-1;
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int a=p.first+dx[i],b=p.second+dy[i];
            if( a<=r &&  b<=c && v[a][b]==1 && path[a][b]==0){
                path[a][b]=path[p.first][p.second]+1;
                q.push({a,b});
            }
            
        }
    }
    cout<<-1<<endl;
    return 0;
}