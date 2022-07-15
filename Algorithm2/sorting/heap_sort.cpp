#include<bits/stdc++.h>
using namespace std;

#define ll long long

void insert_min_heap(vector<ll>&heap_array,int data){
    heap_array.push_back(data);
    int curInd=heap_array.size()-1;
    while(curInd>0 && heap_array[(curInd-1)/2]>data){
      swap(heap_array[curInd],heap_array[(curInd-1)/2]);
      curInd=(curInd-1)/2;
    }
}


void delete_min_heap(vector<ll>&heap_array){
    if(heap_array.size()==0)return;
    swap(heap_array[0],heap_array[heap_array.size()-1]);
    heap_array.pop_back();

    int curInd=0;
    while(curInd<heap_array.size()){
        ll p1=2*curInd+1;
        ll p2=2*curInd+2;
        ll val_p1=INT_MAX;
        ll val_p2=INT_MAX;

        if(p1<heap_array.size())val_p1=heap_array[p1];
        if(p2<heap_array.size())val_p2=heap_array[p2];
        
        if(p1>=heap_array.size())break;
        else if(p2>=heap_array.size()){
            if(heap_array[curInd]>heap_array[p1])swap(heap_array[curInd],heap_array[p1]);
            break;
        }else if(p1<heap_array.size() && p2<heap_array.size()){
            if(val_p1<=val_p2 && val_p1<heap_array[curInd]){
                swap(heap_array[curInd],heap_array[p1]);
                curInd=p1;
            }else if(val_p2<=val_p1 && heap_array[curInd]>val_p2){
               swap(heap_array[curInd],heap_array[p2]);
                curInd=p2;
            }else break;
        }else break;
    }
}


int main(){
   vector<ll>heap_array;
   insert_min_heap(heap_array,100);
//    for(auto it:heap_array)cout<<it<<" ";
//   cout<<endl;
   insert_min_heap(heap_array,20);
   insert_min_heap(heap_array,60);
   insert_min_heap(heap_array,50);
   insert_min_heap(heap_array,10);
   insert_min_heap(heap_array,2);
   insert_min_heap(heap_array,10);
   delete_min_heap(heap_array);
    for(auto it:heap_array)cout<<it<<" ";
  cout<<endl;
   delete_min_heap(heap_array);
    for(auto it:heap_array)cout<<it<<" ";
  cout<<endl;
   delete_min_heap(heap_array);

  for(auto it:heap_array)cout<<it<<" ";
  cout<<endl;

  return 0;
}