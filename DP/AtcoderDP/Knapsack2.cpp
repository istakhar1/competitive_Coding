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
int N,K;

bool dp[101][100001];
int w8[101][100001];


int w[101],v[101]; 
// here w= 10^9 so we cant take w in array but v= 10^3 so we can take it if we take it then we shoud store w;;
//  if dp[index][value]= weight if this is <= w then value shoud be answer 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;



void getSolution(){
 
dp[0][0]=1;
w8[0][0]=0;
 for(int i=1;i<=N;i++){
    for(int j=0;j<100001;j++){
        if(dp[i-1][j]){
            dp[i][j]=true;
            w8[i][j]= min(w8[i][j],w8[i-1][j]);

        }
        if(j-v[i]>=0 && dp[i-1][j-v[i]] && w8[i-1][j-v[i]]+w[i] <= K){
    
           dp[i][j] = 1;
           w8[i][j] = min(w8[i][j], w8[i-1][j-v[i]] + w[i]);
           
        }
    }
 }

int ans=0;
for(int i=0;i<=100001;i++){
 if(dp[N][i]) ans = i;
}
cout<<ans<<"\n";
//   for(int i=0;i<=N;i++){
//     for(int j=0;j<15;j++){
//       cout<<dp[i][j]<<" ";
//     }
//     cout<<"\n";
//  }
// cout<<"==========================================================\n";
//    for(int i=0;i<=N;i++){
//     for(int j=0;j<15;j++){
//       cout<<w8[i][j]<<" ";
//     }
//     cout<<"\n";
//  }



} 
 
void c_p_c()
{   
    
    cin>>N>>K;
    for(int i=1;i<=N;i++){
        cin>>w[i]>>v[i];
    }
    
    for(int i=0;i<=N;i++){
    for(int j=0;j<100001;j++){
      w8[i][j]=1e13;
    }
 }
    
    getSolution();


   
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