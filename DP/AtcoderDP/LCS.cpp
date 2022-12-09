#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define ff first
#define ss second
#define int long long
#define pb push_back
// #define mp              make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mii map<int, int>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
int l1, l2;
string s, t;
int dp[3001][3001];

// int getDPSolution(int n,int m){

//     for(int i=1;i<=n;i++){

//         for(int j=1;j<=m;j++){
//             if(s[i-1]==t[j-1]){
//                 dp[i][j] = dp[i-1][j-1]+1;
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }

//     }

//     return dp[n][m];

// }

int getRecursioveSolution(int i, int j)
{
    if (i >= s.size() || j >= t.size())
    {

        return 0;
    }
    int &ans = dp[i][j];
    if (ans != -1)
    {
        return ans;
    }
    return ans = (s[i] == t[j]) ? getRecursioveSolution(i + 1, j + 1) + 1 : max(getRecursioveSolution(i + 1, j), getRecursioveSolution(i, j + 1));

}

string res = "";
void getAnswer(int i, int j)
{
    if (i >= s.size() || j >= t.size())
        return;
    if (s[i] == t[j])
        res += s[i], getAnswer(i + 1, j + 1);
    else
    {
        if (getRecursioveSolution(i + 1, j) == getRecursioveSolution(i, j))
        {
            getAnswer(i + 1, j);
        }
        else
        {
            getAnswer(i, j + 1);
        }
    }
}

void c_p_c()
{

    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    memset(dp, -1, sizeof(dp));

    getAnswer(0, 0);

    cout << res << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    c_p_c();

    return 0;
}