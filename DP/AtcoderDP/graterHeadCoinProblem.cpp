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
#define ld              long double
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// here w= 10^9 so we cant take w in array but v= 10^3 so we can take it if we take it then we shoud store w;;
//  if dp[index][value]= weight if this is <= w then value shoud be answer 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ld dp[3001][3001];
ld arr[3001];
int n;



ld getMoreHead(int i,int h,int t){
    if(i==n){
        return 1.00;
    }
    ld &ans =dp[i][h];
    if(ans!=-1.00){
        return ans;
    }
    ans= 0.00;
    if(h){
        ans+=getMoreHead(i+1,h-1,t) * arr[i];
    }
    if(t){
        ans+= getMoreHead(i+1,h,t-1) *(1.00 - arr[i]);
    }
    return ans;
}


 
void c_p_c()
{   
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    
    ld ans = 0;
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            dp[i][j]=-1.00;
        }
    }
    for(int i=(n/2+1);i<=n;i++){
        ans+=getMoreHead(0,i,n-i);
    }
    cout<<setprecision(10)<<fixed;
    cout<<ans;

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