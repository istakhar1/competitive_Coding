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
int res=INT_MIN;
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
}

bool cycle_bfs(int n,vector<int>adj[]){
	vector<bool>vist(n+1,false);
	for(int i=1;i<=n;i++){
		if(!vist[i]){
			queue<pair<int,int>>q;
			q.push({i,-1});
			vist[i]=true;
			while(!q.empty()){
				int node=q.front().first;
				int prev=q.front().second;
				q.pop();

				for(auto x:adj[node]){																																																																																																																																																																                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
					if(!vist[x]){
						vist[x]=true;
						q.push({x,node});

					}
					else if(x!=prev){
						return true;
					}
				}
			}
		}
	}
	return false;
}

void DFS(int Node,vector<int> &visit,vector<int>adj[],string s,map<char,int> mp){
	//store.push_back(Node);
	mp[s[Node-1]]+=1;
	//cout<<Node<<" ";
	visit[Node]=1;
	for(auto x:adj[Node]){
		//cout<<x;
		if(!visit[x]){
			DFS(x,visit,adj,s,mp);
		}
	}
	// cout<<"path"<<Node<<"\n";
	for(auto x:mp){
 			if(x.second>=res){
 				res=x.second;
 			}
 		}

}

void  DFS_of_graph(int V,vector<int> adj[],string s){// here v is total no of nodes
 	vector<int> visit(V+1,0);
 	for(int i=1;i<=V;i++){
 		map<char,int>mp;
 		if(!visit[i]){
 			DFS(i,visit,adj,s,mp);
 		}
 	}

 }
int32_t main()
{
    c_p_c();
    int n,m;
    cin>>n>>m;//n= nmber of nodes and m= number of edges
    string s;
    cin>>s;
    vi adj[n+1];
    for(int i=0;i<m;i++){
    	int u,v;//U= NUMBER OF NODES V = NUMBER OF VERTICES
    	cin>>u>>v;
    	adj[u].pb(v);
    	//adj[v].pb(u);
    }
    //  for(int i=0;i<=n;i++){
    // 	cout<<(i)<<"-->";
    // 	for(int x:adj[i]){
    // 		cout<<x<<" ";
    // 	}
    // 	cout<<"\n";
    // }
    if(cycle_bfs(n,adj)){
    	cout<<-1;
    }
    else{
    	 DFS_of_graph(n,adj,s);
    	 cout<<res;
    }

   // vector<int>res=DFS_of_graph(7,adj);
    // for(auto x:res){
    // 	cout<<x<<" ";
    // }
    return 0;
}