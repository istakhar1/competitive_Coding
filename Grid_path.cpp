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
int  fun(int i,int j,vector<vector<int>>path,vector<vector<bool>>visit,int sum,int m,int n){

	if(((i<0 || j<0) || (i>=m || j>=n)) ){
		return INT_MAX;
	}
	if(visit[i][j]==true){
	 return INT_MAX;
	}
   
	visit[i][j]=true;
  
	if(i==n-1&& j==m-1&&path[i][j]==9){
		
		return (sum+1);
	}
	
  
		sum+=1;
	
		int v1= fun(i+1,j,path,visit,sum,n,m);
    	int container= fun(i,j+1,path,visit,sum,n,m);
		int v3= fun(i-1,j,path,visit,sum,n,m);
		int v4= fun(i,j-1,path,visit,sum,n,m);
        int v5 =INT_MAX;
        int v6 =INT_MAX;
        int v7 =INT_MAX;
        int v8 =INT_MAX;
        if(path[i][j]==99){
            
            // v5 = fun(i-1,j-1,path,visit,sum,n,m);
            // v6 = fun(i-1,j+1,path,visit,sum,n,m);
            // v7 = fun(i+1,j-1,path,visit,sum,n,m);
            v8 = fun(i+1,j+1,path,visit,sum,n,m);
        }
	
    // cout<<v1<<" "<<container<<" "<<v3<<" "<<v4<<"\n";
	return min(min(min(v1,container),min(v3,v4)), min(min(v5,v6),min(v7,v8)));
	
 }
int32_t main()
{
    c_p_c();
    int t;
    cin>>t;
    while(t--){
    int n,m,k;
    cin>>m>>n>>k;
    vector<vector<int>>path(m,vector<int>(n,1));
    path[m-1][n-1]=9;
    while(k--){
        
        int r,k;
        cin>>r>>k;
        path[r-1][k-1]=99;
    }
    
     for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<path[i][j]<<" ";
    	}
    	cout<<"\n";
    }
    vector<vector<bool>>visit(m,vector<bool>(n,false));
   	// for(int i=0;i<m;i++){
    // 	for(int j=0;j<n;j++){
    // 		if(path[i][j]==0){
    // 			visit[i][j]=true;
    // 		}
    // 	}
    	
    // }
    if(path[0][0]==0){
        cout<<-1;
    }
    else{
        int v=fun(0,0,path,visit,0,m,n);
        if(v==INT_MAX){
            cout<<-1<<"\n";
        }
        else{
            cout<<v-1<<"\n";
        }
        
    }
    }
    return 0;
}