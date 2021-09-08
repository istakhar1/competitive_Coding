#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
}
// int  fun(int i,int j,vector<vector<char>>path,vector<vector<bool>>visit,int sum,int n){
// //	cout<<"check\n";
// 	if(((i<0 || j<0) || (i>=n || j>=n)) ){
// 		return 0;
// 	}
// 	if(visit[i][j]==true){
// 	 return 0;
// 	}
// 	visit[i][j]=true;
// 	if(i==n-1&&j==n-1 && path[i][j]!='*'){
		
// 		return 1;
// 	}
	
	
// 	return (fun(i+1,j,path,visit,sum,n)%mod+fun(i,j+1,path,visit,sum,n)%mod)%mod;;
	
//  }
int32_t main()
{
    c_p_c();
    int n;
    cin>>n;
    vector<vector<char>>path(n,vector<char>(n));
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>path[i][j];
    	}
    }
    //  for(int i=0;i<n;i++){
    // 	for(int j=0;j<n;j++){
    // 		cout<<path[i][j]<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    vector<vector<bool>>visit(n,vector<bool>(n,false));
   	for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(path[i][j]=='*'){
    			visit[i][j]=true;
    		}
    	}
    	
    }

    if(path[0][0]=='*' or path[n-1][n-1]=='*'){
        cout<<0;
    }
    else if(n==1&&path[0][0]!='*'){
    	cout<<1;
    }
    else{
        vector<vector<int>>dp(n,vector<int>(n,0));
        dp[n-1][n-1]=0;
        if(path[n-1][n-2]!='*')
        dp[n-1][n-2]=1;
        else dp[n-1][n-2]=0;
        for(int i=n-3;i>=0;i--){
            if(path[n-1][i]!='*')
        	dp[n-1][i]=dp[n-1][i+1];
        }

    	if(path[n-2][n-1]!='*')
           dp[n-2][n-1]=1;
        else
        	dp[n-2][n-1]=0;

        for(int i=n-3;i>=0;i--){
            if(path[i][n-1]!='*')
        	dp[i][n-1]=dp[i+1][n-1];
        }

        for(int i=n-2;i>=0;i--){
        	for(int j=n-2;j>=0;j--){
        		if(path[i][j]!='*'){
        		    dp[i][j]=(dp[i][j+1]%mod+dp[i+1][j]%mod)%mod;
        		}
        	}
        
        }
        // for(int i=0;i<n;i++){
        // 	for(int j=0;j<n;j++){
        // 		cout<<dp[i][j]<<" ";
        // 	}
        // 	cout<<"\n";
        
        // }
      cout<<dp[0][0];
        
    }
    return 0;
}