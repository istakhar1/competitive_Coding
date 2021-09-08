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

string decodeString(string s) {
       
        stack<string> val;
        stack<int>number;
        int i=0;
        while(i<s.size()){
            
            if(s[i]>='0'&&s[i]<='9'){
                int v=0;
                while(s[i]>='0'&&s[i]<='9'){
                    v = v*10+(int)(s[i]-'0');
                    i++;
                }
                // cout<<v<<"\n";
                number.push(v);
            }
            
            if(s[i]>='a'&&s[i]<='z'){
                string temp="";
                while(s[i]>='a'&&s[i]<='z'){
                    temp+=s[i];
                    i++;
                }
               val.push(temp);
               
            }
            if(s[i]=='['){
                // val.push(to_string(s[i]));
                i++;
                continue;      
            }
            if(s[i]==']'){
            	while(!number.empty()&&(number.top()>=0&&number.top()<=300)){
                string news=val.top();
                val.pop();
                int t=number.top();
                number.pop();
                string temp="";
                while(t--){
                    temp+=news;
                    
                }
                // val.pop();
                if(!val.empty()){
                string d=val.top();
                temp=d+temp;
                val.pop();
                val.push(temp);
                }
                else{
                    val.push(temp);
                }

              i++;
            }
        }
        }
        while(!number.empty()){
            cout<<number.top()<<"\n";
            number.pop();
        }
        string v="";
        while(!val.empty()){
        v=val.top()+v;
            val.pop();
        }
      
        
        return v;
    }



string decodeString2(string s) {
      int n = s.size();      
      string str = "";
      stack<char> st;
      
      for(int i=0; i<n; i++){
        if(s[i] == ']'){
          string a = "";
          //ceate string
          while(!st.empty() && st.top() != '['){
            a.push_back(st.top());
            st.pop();
          }
          if(!st.empty() && st.top() == '['){
            st.pop();
            stack<int> num;//jisme number rahega
            int x = 0;
            while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
              num.push(st.top() - '0');
              st.pop();              
            }
            while(!num.empty()){
              x = 10*x + num.top();
              num.pop();
            }
            
            
            while(x--){
              for(int i=a.size()-1; i>=0; i--)
                st.push(a[i]);
            }            
          }          
        }
        else{
          st.push(s[i]);
        }        
        
      }
      while(!st.empty()){
        str.push_back(st.top());
        st.pop();
      }
      reverse(str.begin(), str.end());
      return str;
    }

 
int32_t main()
{
    c_p_c();
    string s;
    cin>>s;
    cout<<decodeString2(s)<<"\n\n";
   // cout<<decodeString(s)<<"\n";
    return 0;
}