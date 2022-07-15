#include<bits/stdc++.h>
using namespace std;

vector<int> getlps(string pattern){
    int l=pattern.length();
    vector<int>v(l);
    v[0]=0;
    int i=1;
    int j=0;
    while(i<l){
        if(pattern[i]==pattern[j]){
            v[i]=j+1;
            j++;
            i++;
        }
        else {
            if(j!=0){
                j=v[j-1];
            }
            else{
                v[i]=0;
                i++;
            }
        }
    }
    for(auto it:v)cout<<it<<" ";
    cout<<endl;
    return v;
}

int KMP_search(string s,string pattern){
    int i=0;
    int j=0;
    vector<int>lps=getlps(pattern);
    for(auto it:lps)cout<<it<<" " ;
      int string_length=s.length();
      int pattern_length=pattern.length();

    while(i<string_length && j<pattern_length){
        if(s[i]==pattern[j]){
            i++;
            j++;
        }
        else {
            if(j!=0){
                j=lps[j-1];
            }
            else {
                i++;
            }
        }

    }
    if(j==pattern_length)return 1;
    else return 0;
}
int main(){
    string s="azadalokashish";
    string pattern="alok";

    int ans = KMP_search(s,pattern);
    cout<<ans<<endl;
    return 0;
}