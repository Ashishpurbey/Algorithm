#include<bits/stdc++.h>
using namespace std;

void multiply(int m[2][2],int M[2][2]){
    int value1=m[0][0]*M[0][0]+m[0][1]*M[1][0];
    int value2=m[0][0]*M[0][1]+m[0][1]*M[1][1];
    int value3=m[1][0]*M[0][0]+m[1][1]*M[1][0];
    int value4=m[1][0]*M[0][1]+m[1][1]*M[1][1];

    m[0][0]=value1;
    m[0][1]=value2;
    m[1][0]=value3;
    m[1][1]=value4;
}
void power(int m[2][2],int n){
    if(n==0 || n==1){
        return ;
    }
    power(m,n/2);
    multiply(m,m);
    if(n%2!=0){
        int M[2][2]={{1,1},{1,0}};
        multiply(m,M);
    }
}
int fib(int n){
    int m[2][2]={{1,1},{1,0}};
    if(n==0)return 0;
    power(m,n-1);
    return m[0][0];
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
return 0;
}