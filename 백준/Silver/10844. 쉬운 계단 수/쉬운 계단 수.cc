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

int n;

#define MOD 1000000000

int dp[107][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;


    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][1] % MOD;
            }
            else if (j == 9)
            {
                dp[i][j] = dp[i - 1][8] % MOD; 
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < 10; i++)
        ans = (dp[n][i] + ans) % MOD;

    cout << ans;

    return 0;
}
