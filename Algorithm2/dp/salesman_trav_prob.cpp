int findans(int mask,int pre,int k,vector<vector<int>>&cost,int n,vector<vector<int>>&dp){
    // cout<<mask<<endl;
    if(mask==k)return 0;
    int ans=0;
    if(pre!=-1 && dp[mask][pre]!=-1)return dp[mask][pre];
    if(pre==-1){
        for(int i=0;i<n;i++){
            int k1=(1<<i);
            // cout<<k1<<" "<<(mask|k1)<<endl;
            ans=max(ans,findans((mask | k1),i,k,cost,n,dp));
            // cout<<ans<<endl;
        }
    }else{
        for(int i=0;i<n;i++){
            int k1=(1<<i);
            if((mask & k1) == 0){
                // cout<<k<<" "<<(mask | k)<<endl;
                ans=max(ans,cost[pre][i]+findans((mask | k1),i,k,cost,n,dp));
                // cout<<ans<<endl;
            } 
        }
    }
    if(pre==-1)return ans;
    else return dp[mask][pre] = ans;
}
