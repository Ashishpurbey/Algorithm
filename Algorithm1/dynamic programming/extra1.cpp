#include<bits/stdc++.h>

typedef long long int ll;

#define dbg printf("in\n");
#define nl printf("\n");
#define pp pair<int,int>
#define inf 1000000000000000000
 

using namespace std;
vector<ll>v;
int main()
{
    //freopen("in.txt","r",stdin);
   ll n;
   cin>>n;
  
ll value=5;
ll count=3;
    while(value<inf){
       v.push_back(value);
       value+=(count*(count+1))/2;
       count++;
    }
    if(n<4){
        cout<<n<<endl;
    }
    else {
        
    }


    return 0;
}