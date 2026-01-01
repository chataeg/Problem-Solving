#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 10007

int main() {
    vector<int> a(1001, 0);
    vector<int> dp(1001, 1);
    vector<int> dp2(1001, 1);

    int N;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> a[i];

    int ans = 0;
    int ans_ind = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);

            }
        }
    }




    for (int i = N; i >= 1; i--)
    {
        for (int j = N; j >= i; j--)
        {
            if (a[i] > a[j])
            {
                dp2[i] = max(dp2[i], dp2[j] + 1);

            }

        }
    }

    int max_length = 0;

    for (int i = 1; i <= N; i++)
    {
        max_length = max(max_length, dp[i] + dp2[i] - 1);
    }

    cout << max_length;

    return 0;
}


