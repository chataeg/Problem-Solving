#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

#define MOD 10007

long long dp[1007][1007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*        
            n!
        k!(n! - k!)

        4C2

        10C3

        10 9 8
        1 2 3 

        4 3
        2 1


        4C2

        A B C D

        AB AC BC
        A  B  C

        AB AC BC
        AD BD CD

        dp[1][1] = 1    
        dp[2][1] = 2
        dp[3][1] = 3
        dp[4][1] = 4

        dp[2][2] = 1
        dp[3][2] = 3  dp[2][2] + dp[2][1]
        dp[4][2] = 6  dp[3][2] + dp[3][1]
        dp[5][2] = 10
    */

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        dp[i][1] = i;

    for (int i = 1; i <= n; i++)
        dp[i][i] = 1;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j <= k; j++)
        {
            if (i == j) continue;

            dp[i][j] = (dp[i - 1][j] % MOD) + (dp[i - 1][j - 1] % MOD);
        }
    }
    
    cout << dp[n][k] % MOD;

    return 0;
}
