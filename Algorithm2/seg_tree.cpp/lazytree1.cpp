#include<bits/stdc++.h>
using namespace std;
#define ll long long

// for update, we have to update no from range {l,r};
// and for query we have to find the sum of no from range {l,r};



ll lazy[300001]={0},tree[300001]={0},l,r,x,c,n,t,val;


void update(ll node,ll start,ll end,ll l,ll r,ll val){
    if(lazy[node]){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(r<start || start>end || l>end)return ;
    if(l<=start && end<=r){
        tree[node]+=(end-start+1)*val;
        if(start!=end){
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    ll mid=(start+end)/2;
    update(2*node,start,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node]=tree[2*node]+tree[2*node+1];
    return;
}



ll query(ll node,ll start,ll end,ll l,ll r){
    if(start>end || l>end || r<start)return 0;
    
    if(lazy[node]){
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l<=start && r>=end)return tree[node];
    ll mid=(start+end)/2;
    return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}


int main(){
    cin>>t;
    while(t--){
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        cin>>n>>c;
        while(c--){
            cin>>x;
            if(x==0){
                cin>>l>>r>>val;
                update(1,1,n,l,r,val);
            }
            else{
                cin>>l>>r;
                cout<<query(1,1,n,l,r)<<endl;
            }
        }
    }
    return 0;
}
