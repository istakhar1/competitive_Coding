class Solution {
public:
    static bool compareHeight(vector<int>a, vector<int>b){
        int n1=a.size();
        int n2=b.size();
        if(a[n1-1] < b[n2-1]){
            return true;
        }
        else if(a[n1-1] == b[n2-1]){
            if(a[n1-2] < b[n2-2]){
                return true;
            }
            else if( a[n1-2] == b[n2-2]){
                if(a[0]<b[0]){
                    return true;
                }
                else{
                    return false;
                }
            }
           
        }
        
        return false;
        
    }
    int maxHeight(vector<vector<int>>& c) {
        
        int n=(int)c.size();
        for(int i=0;i<n;i++){
           sort(c[i].begin(),c[i].end());
        }
        sort(c.begin(), c.end(),compareHeight);
        
        int dp[101]={0};
        
        dp[0]=c[0][2];
 
        // for(auto x:c){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<"\n";
        // }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(c[j][0]<=c[i][0]&&c[j][1]<=c[i][1]){
                    dp[i] = max(dp[i], dp[j]+c[i][2]);
                }
            }
            if(dp[i]==0){
                dp[i]=c[i][2];
            }
        }
        
        int ans=INT_MIN;
        for(auto x: dp){
            // cout<<x<<"--";
            ans= max(ans,x);
        }
        
     
        return ans;
    }
};