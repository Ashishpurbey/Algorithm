#include<stdio.h>

int main(){
    freopen("input.txt","r",stdin);
    int row,col;
    scanf("%d %d",&row,&col);
    int p,q;
    scanf("%d %d",&p,&q);
    int ar[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&ar[i][j]);
        }
    }

    for(int i=0;i<=row-p;i++){
        for(int j=0;j<=col-q;j++){
           for(int k=i;k<i+p;k++){
               for(int l=j;l<j+q;l++){
                   printf("%d ",ar[k][l]);
               }
               printf("\n");
           }
           printf("\n");
        }
    }
    return 0;
}