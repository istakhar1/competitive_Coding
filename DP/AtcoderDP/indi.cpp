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


void checkVal(vector<int> &b,int s, int sum,int n){
    if(sum>s){
        for(int i=0;i<n;i++){
            if(b[i]==1){
                b[i]=0;
                break;
            }
        }
    }
}

 
void c_p_c()
{   
    int t;
	cin>>t;
	while(t--){
	    int n,k,s;
        cin>>n>>k>>s;
        vector<int>b(n,1);
        int sum =0;
        int c=0;
        while(true){
            if(c==100)break;
            c++;
        for(int i=1;i<n;i++){
            sum += b[i]*pow(k,i-1);
          
            
        }
          if(sum==s){
                break;
                
            }
            else{
                checkVal(b,s,sum,n);
                
            }
        }
        for(auto x:b){
            cout<<x<<" ";
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