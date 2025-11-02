#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
queue<int> q; 

int dp[45];
int arr[45];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        q.push(input);
        arr[input] = 1;
    }

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    dp[5] = 8;

    for (int i = 4; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    int ans = 1;

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            if (cnt > 0)
            {
                ans *= dp[cnt];
                cnt = 0;
            }

        }
        else
        {
            cnt++;
        }
    }

    if (cnt > 0)
        ans *= dp[cnt];

    cout << ans;

}