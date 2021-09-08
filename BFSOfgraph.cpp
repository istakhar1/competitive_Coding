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

vector<int> bfs(int n,vi adj[])
{
	vector<int> res;
	vector<bool> vis(n+1,false);
	for(int i=1;i<n;i++){
		if(!vis[i]){
			queue<int> q;
			q.push(i);
			vis[i]=true;
			while(!q.empty()){
				int val=q.front();//
				//cout<<val<<"\n";
				res.push_back(val);
				q.pop();
				for(int x:adj[val]){
					if(!vis[x]){
						if(gcd(arr[val],arr[x])%k==0){
							cout++;
						}
					vis[x]=true;
					q.push(x);
				}
				}
			}
		}
	}
	return res;
}
 
int32_t main()
{
    c_p_c();
    int n,m;
    cin>>n>>m;//n= nmber of nodes and m= number of edges
    vi adj[n+1];
    for(int i=0;i<m;i++){
    	int u,v;//U= NUMBER OF NODES V = NUMBER OF VERTICES
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    // for(int i=0;i<=n;i++){
    // 	cout<<(i)<<"-->";
    // 	for(int x:adj[i]){
    // 		cout<<x<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    vi res=bfs(n,adj);
    for(int x:res){
    	cout<<x<<" ";
    }

    
    return 0;
}