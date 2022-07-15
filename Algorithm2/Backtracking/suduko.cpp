#include<bits/stdc++.h>
using namespace std;

int N;



bool isSafe(vector<vector<int>>&grid, int row,
                       int col, int num)
{

    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;

    int startRow = row - row % 3,
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                            startCol] == num)
                return false;
 
    return true;
}

bool solveSudoku1(vector<vector<int>>&grid, int row, int col)
{

    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return solveSudoku1(grid, row, col + 1);
 
    for (int num = 1; num <= N; num++)
    {

        if (isSafe(grid, row, col, num))
        {
             

            grid[row][col] = num;

            if (solveSudoku1(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0;
    }
    return false;
}

void solveSudoku(vector<vector<char> > &A) {
    N=A.size();
    vector<vector<int>>grid(A.size(),vector<int>(A.size(),0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]!=' ')grid[i][j]=A[i][j]-'0';
        }
    }
    bool val=solveSudoku1(grid,0,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]=grid[i][j]+'0';
        }
    }
    return;
    
}

int main(){
    vector<vector<char>>A;
    for(auto &it:A)for(auto &it1:it)cin>>it1;
    solveSudoku(A);
    return 0;
}