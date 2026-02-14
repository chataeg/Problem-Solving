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
int n, k;
int arr[107];
int dp[10007];
set<int> s;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        s.insert(input);
    }

    int ind = 1;
    for (auto iter : s)
        arr[ind++] = iter;


    fill(dp, dp + k + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            if(dp[j] == 0) dp[j] = max(dp[j], dp[j - arr[i]] + 1);
            else dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        } 
    }
     
    if (dp[k] == 1e9)
        cout << -1;
    else
        cout << dp[k];

    return 0;
}
