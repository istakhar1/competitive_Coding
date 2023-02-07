#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
There are two integers n, m where 0 ≤ n ≤ m ≤ 1018 . Find the number of integers between
n and m inclusive containing exactly k d digits. n, m, k, d are given in input.
Sample Input
(n, m, k, d) = (7, 111, 2, 1)
This translates to finding the number of integers in the range [7, 111] with exactly two 1
digits. There are three such integers: 11, 101, 110.

*/
const int max_num_digits = 100;
int dp[max_num_digits][max_num_digits][2];
int n, m, k, d;

void reset()
{
    for (int i = 0; i < max_num_digits; i++)
    {
        for (int j = 0; j < max_num_digits; j++)
        {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }
}

int dfs(int c, int x = 0, int y = 0, bool z = 0)
{ // range [0, c] with
    // state [x][y][z]
    if (dp[x][y][z] != -1)
    { // memoization
        return dp[x][y][z];
    }
    dp[x][y][z] = (y == k);
    if (x == to_string(c).length())
    {
        return dp[x][y][z];
    }
    int limit = 9;
    if (!z)
    {                                  // if the number being formed CAN exceed c
        limit = to_string(c)[x] - '0'; // the xth digit of c
    }
    // now setting the xth digit of the number we're building
    dp[x][y][z] = 0; // going to permanently set dp[x][y][z] now
    for (int xth_digit = 0; xth_digit <= limit; xth_digit++)
    {
        if (z)
        {
            dp[x][y][z] += dfs(c, x + 1, y + (xth_digit == d), 1);
        }
        else
        {
            dp[x][y][z] += dfs(c, x + 1, y + (xth_digit == d), xth_digit < limit);
        }
    }
    return dp[x][y][z];
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    reset();
    cin >> n >> m >> k >> d;
    int total = dfs(m);
    reset();
    cout << total - dfs(n - 1) << endl;
}