#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
// #define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi             vector<vector<int>>
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
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// here w= 10^9 so we cant take w in array but v= 10^3 so we can take it if we take it then we shoud store w;;
//  if dp[index][value]= weight if this is <= w then value shoud be answer 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[1001][1001];


int getLongestPath(int h,int w,vector<vector<char>> &adj){
    if(h==0&&w==0){
        return dp[h][w]=1;
    }

    if(adj[h][w]=='#'){
        return dp[h][w]=0;
    }
    int &ans= dp[h][w];
    if(ans!=-1){
        return ans;
    }
    if(h==0){
        return ans = getLongestPath(h,w-1,adj)%mod;
    }
    if(w==0){
        return ans = getLongestPath(h-1,w,adj)%mod;
    }

 
  
    return ans = (getLongestPath(h-1,w,adj)%mod + getLongestPath(h,w-1,adj)%mod)%mod;
   
}


 
void c_p_c()
{   

    int t;
    cin>>t;
    while(t--){
    int h,w,k;
    cin>>h>>w>>k;
    cout<<h<<w<<k;
    vector<vector<char>> adj(h,vector<char>(w ,' '));
    if(k){
        while (k--)
        {
            int r,c;
            cin>>r>>c;
            adj[r][c]='#';
            /* code */
        }
        
    }
    // for(int i=0;i<h;i++){
    //     for(int j=0;j<w;j++){
    //         cin>>adj[i][j];
    //     }
    // }

    memset(dp,-1,sizeof(dp));
    // dp[0][0]=1;
    int ans =getLongestPath(h-1,w-1,adj);
    ans = ans==-1?0:ans;
    cout<<ans<<"\n";
    }

}
 
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    c_p_c();
    
    return 0;
}