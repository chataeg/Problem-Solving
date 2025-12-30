#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int t;

int dp[31][31];

int combi(int n, int r)
{
    if (n == r || r == 0)
        return 1;

    if (dp[n][r] != 0)
        return dp[n][r];

    return dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        cout << combi(m, n) << '\n';
    }

    return 0;
}