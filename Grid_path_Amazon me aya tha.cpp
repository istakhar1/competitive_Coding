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
int  fun(int i,int j,vector<vector<int>>path,vector<vector<bool>>visit,int sum,int n){
//	cout<<"check\n";
	if(((i<0 || j<0) || (i>=n || j>=n)) ){
		return INT_MAX;
	}
	if(visit[i][j]==true){
	 return INT_MAX;
	}
	visit[i][j]=true;
	if(path[i][j]==9){
		
		return (sum+1);
	}
	
	if(path[i][j]==1){
	    
		sum+=1;
	}
		int v1= fun(i+1,j,path,visit,sum,n);
    	int v2= fun(i,j+1,path,visit,sum,n);
		int v3= fun(i-1,j,path,visit,sum,n);
		int v4= fun(i,j-1,path,visit,sum,n);

	
	return min(min(v1,v2),min(v3,v4));
	
 }
int32_t main()
{
    c_p_c();
    int n;
    cin>>n;
    vector<vector<int>>path(n,vector<int>(n));
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
    		if(path[i][j]==0){
    			visit[i][j]=true;
    		}
    	}
    	
    }
    if(path[0][0]==0){
        cout<<-1;
    }
    else{
        int v=fun(0,0,path,visit,0,n);
        if(v==INT_MAX){
            cout<<-1;
        }
        else{
            cout<<v;
        }
        
    }
    return 0;
}