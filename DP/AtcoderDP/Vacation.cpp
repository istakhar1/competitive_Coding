#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int getSolution(vi a,vi b,vi c, vvi &dp,int n){
    dp[0][0]=a[0];
    dp[0][1]=b[0];
    dp[0][2]=c[0];

    for(int i=1;i<n;i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    for(auto x:dp){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }
    
    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));

} 
 
void c_p_c()
{
   int n;
   cin>>n;
   int T=n;
   vi a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i]>>c[i];
  }

vvi dp(n,vector<int>(3));
  cout<<getSolution(a,b,c,dp, n)<<"\n";
  
    

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