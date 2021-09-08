#include<bits/stdc++.h>
// #include <boost/algorithm/string.hpp>
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
 
int32_t main()
{
    c_p_c();

    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	
    	int i=0;
    	string dd="",mm="",yy="";
    	while(i<s.size()&& (s[i]!='.' && s[i]!='/')){
    		dd+=s[i];
    		i++;
    	}
    	bool flag=true;
    	if(s[i]=='/'){
    		flag=false;
    	}
    	i++;
    	while(i<s.size()&& (s[i]!='.' && s[i]!='/')){
    		mm+=s[i];
    		i++;
    	}
    	i++;
    	while(i<s.size()&& (s[i]!='.' && s[i]!='/')){
    		yy+=s[i];
    		i++;
    	}
    	if(dd.size()==1){
    		dd="0"+dd;
    	}
    	if(mm.size()==1){
    		mm="0"+mm;
    	}
    	if(yy.size()!=4){
    		while(yy.size()!=4){
    			yy="0"+yy;
    		}
    	}
    	if(flag){
    	cout<<dd<<"."<<mm<<"."<<yy<<" "<<mm<<"/"<<dd<<"/"<<yy<<"\n";
    }
    else{
    	cout<<mm<<"."<<dd<<"."<<yy<<" "<<dd<<"/"<<mm<<"/"<<yy<<"\n";
    }
    }
    
    return 0;
}