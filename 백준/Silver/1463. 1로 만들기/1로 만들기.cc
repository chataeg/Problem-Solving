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

int dp[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    fill(dp, dp + 1000007, 1000007);
    dp[n] = 0;

    for (int i = n; i > 0; i--)
    {
        if (i % 3 == 0 && i / 3 > 0)
            dp[i / 3] = min(dp[i / 3], dp[i] + 1);
        if (i % 2 == 0 && i / 2 > 0)
            dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        if (i - 1 > 0)
            dp[i - 1] = min(dp[i - 1], dp[i] + 1);
    }

    cout << dp[1];

    return 0;
}
