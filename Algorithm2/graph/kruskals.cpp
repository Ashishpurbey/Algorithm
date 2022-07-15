//MST find karne ke liea use karte hai

#include<bits/stdc++.h>
using namespace std;
struct edge{
    int start;
    int end;
    int weight;
};

int cmp(edge a1,edge a2){
    return a1.weight<a2.weight;
}

int getparent(int n,vector<int>parent){
    if(parent[n]==n){
        return n;
    }
    return getparent(parent[n],parent);
}

void  kruskul(vector<edge>ar,int e,int n,vector<edge>&output){
    int count=0;
    vector<int>parent(n);
    for(int i=0;i<n;i++)
    parent[i]=i;
    int i=0;
    while(count<(n-1)){
        edge currentedge =ar[i];
        int start=getparent(ar[i].start,parent);
        int end=getparent(ar[i].end,parent);
        if(start!=end){
            output[count]=currentedge;
            count++;
            //parent[ar[i].end]=parent[ar[i].start];
            parent[start]=end;
        }
        i++;
    }
}

int main(){
    freopen("input.txt","r",stdin);freopen("result.txt","w",stdout);
    int n,e;
    cin>>n>>e;
    vector<edge>ar(e);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
       ar[i].start=a;
       ar[i].end=b;
       ar[i].weight=c;
    }
   sort(ar.begin(),ar.end(),cmp);
   vector<edge>output(n-1);
   //calling the kruskul function
   kruskul(ar,e,n,output); 
   for(int i=0;i<n-1;i++){
       cout<<output[i].start<<" "<<output[i].end<<" "<<output[i].weight<<endl;
    }
   return 0;
}