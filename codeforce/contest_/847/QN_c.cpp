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

vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> ans;
    // cout<<"value of v"<<V<<"\n";
    vector<int> in (V,0);
    for(int i=1;i<V;i++){
        for(auto it: adj[i])
            in[it]++;
    }
    
    queue<int>q;
    for(int i=1;i<V;i++){
        // cout<<in[i]<<" ";
        if(in[i]==0){
            // cout<<"\n aya"<<i;
             q.push(i);
        }
    }
    // cout<<q.front();
    while(q.size()!=0){
        int node= q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            in[it]--;
            if(in[it]==0)q.push(it);
        }
    }
    return ans;
}

void c_p_c()
{   
    
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    vector<vector<int>> arr;
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        vector<int> temp(n);
        for(int j=1;j<n;j++)cin>>temp[j];
        for(int k=2;k<n;k++){
            adj[temp[k-1]].push_back(temp[k]);
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<i<<"-> ";
    //     for(auto x: adj[i]){
    //         cout<<x<<", ";
    //     }
    //     cout<<"\n";
    // }
    vector<int> ans = topoSort(n+1,adj);
    for(auto it:ans)cout<<it<<" ";
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