    int lengthOfLIS(vector<int>& nums) {
        int n=(int)nums.size();
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                dp[i]= max(dp[i],dp[j]+1);
            }
            if(dp[i]==0){
                dp[i]=1;
            }
        }
        
        int ans=INT_MIN;
        for(auto x: dp){
            ans= max(ans,x);
        }
        return ans;
        
    }