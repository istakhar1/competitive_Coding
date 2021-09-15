  int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> dp(n,1);
       for(int i=1;i<n;i++){
           for(int j=0;j<i;j++){
               if(a[j]<a[i] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
           }
       }
       int maxv=0;
       for(auto i:dp){
           if(i>maxv)
            maxv=i;
       }
       return maxv;
    }


    /*
    N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5
     13,3,11,7,15}
Output: 6

    */