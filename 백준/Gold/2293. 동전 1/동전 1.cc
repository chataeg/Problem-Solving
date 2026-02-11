#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int n, k; 
int arr[10007];
int dp[10007];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }

    cout << dp[k];

    return 0;
}
