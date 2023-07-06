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
#define ld              long double
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


// here w= 10^9 so we cant take w in array but v= 10^3 so we can take it if we take it then we shoud store w;;
//  if dp[index][value]= weight if this is <= w then value shoud be answer 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int contingTowerDp(int n){
    int sep[n],join[n];
    sep[0]= join[0]=1;
    for(int i=1;i<n;i++){
        sep[i] = ((sep[i-1]*4)+join[i-1]);
        sep[i]%=mod;
        join[i] = ((2*join[i-1])+ sep[i-1]);
        join[i]%=mod;
    }

    return (sep[n-1]%mod + join[n-1]%mod)%mod;

}

string pi ="3141592653589793238462643383279";

void c_p_c()
{   
    
   int t;
   cin>>t;
   while(t--){
    int m;
    cin>>m;
    int n=m-1;
    vector<vector<int>> a(m,vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }

    }
    int freq[101]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            freq[a[j][i]]++;
            // cout<<a[j][i]<<" ";
        }
        int val=0;
        int count=0;
        for(int i=1;i<=m;i++){
            // cout<<freq[i]<<" ";
            if(freq[i]>count){
                count=freq[i];
                val=i;
            }

        }
        freq[val]=-1;
        // cout<<"\n";
        cout<<val<<" ";
       


    
    }

    for(int i=1;i<=m;i++){
        if(freq[i]!=-1 && freq[i]!=0){
            cout<<i<<" ";
            break;
        }
    }
    cout<<"\n";

   

    
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