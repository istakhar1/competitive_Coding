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
int count=0;
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
}
 
void DFS(int Node,vector<int> &visit,vector<int>adj[],vector<int> &store,int waight[],int x,int value,int ans){
	store.push_back(Node);
    value^=waight[Node-1];
    cout<<value<<"\n";
    if(value==x){
        value=0;
        cout<<"check\n";
        ans++;
    }
	//cout<<Node<<" ";
	visit[Node]=1;
	for(auto x:adj[Node]){
		//cout<<x;
		if(!visit[x]){
			DFS(x,visit,adj,store,waight,x,value,ans);
            
		}
	}
}

 int DFS_of_graph(int V,vector<int> adj[],int waight[],int x){// here v is total no of nodes
 	vector<int>store;
 	vector<int> visit(V+1,0);
    int value=0,ans=0;
 	for(int i=1;i<=V;i++){
 		if(!visit[i]){
 			DFS(i,visit,adj,store,waight,x,value,ans);
 		}
 	}
 	return ans;
 }
int32_t main()
{
    c_p_c();
    int t;
    cin>>t;
    while(t--){


    int n;
    cin>>n;
    int waight[n];
    for(int i=0;i<n;i++){
        cin>>waight[i];
    }
    int x;
    cin>>x;
    //n= nmber of nodes and m= number of edges
    vi adj[n+1];
    for(int i=0;i<n;i++){
    	int u,v;//U= NUMBER OF NODES V = NUMBER OF VERTICES
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
     for(int i=0;i<=n;i++){
    	cout<<(i)<<"-->";
    	for(int x:adj[i]){
    		cout<<x<<" ";
    	}
    	cout<<"\n";
    }
   cout<<DFS_of_graph(n,adj,waight,x);
    
}
    return 0;
}