#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct trieNode{
    trieNode *left=NULL;
    trieNode *right=NULL;
};

void insert(ll n,trieNode *head){ 
   trieNode * p=head;
   bitset<32>br(n);
    for(ll i=31;i>=0;i--){
        if(br[i]==0){
            if(p->left==NULL)p->left=new trieNode;
            p=p->left;
        }else{
           if(p->right==NULL)p->right=new trieNode;
           p=p->right;
        }
    }
}

ll findMaxXorPair(trieNode *head,ll *ar,ll n){
    ll ans=0;
    for(ll i=0;i<n;i++){
        bitset<32>ar1(ar[i]);
        trieNode * p=head;
        for(ll j=31;j>=0;j--){
            if(ar1[j]==0){
               if(p->right!=NULL){
                   ar1[j]=1;
                   p=p->right;
               }else{
                   ar1[j]=0;
                   p=p->left;
               } 
            }else{
                if(p->left!=NULL){
                    ar1[j]=1;
                    p=p->left;
                }else{
                    ar1[j]=0;
                    p=p->right;
                }
            }
        }
        ll p1=ar1.to_ullong();
        ans=max(ans,p1);

    }
    return ans;
}



int main(){
    
    trieNode *head=new trieNode;
    ll arr[6]={8,1,2,15,10,5};
    for(int i=0;i<6;i++){
        insert(arr[i],head);
    }
    cout<<findMaxXorPair(head,arr,6);
    return 0;
}