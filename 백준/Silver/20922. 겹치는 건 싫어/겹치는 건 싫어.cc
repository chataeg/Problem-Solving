#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000007];
int cnt[1000007];
int n, k;

int mx = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = 0;
    int r = 0;

    while (r < n)
    {
        cnt[arr[r]]++;

        while (cnt[arr[r]] > k)
        {
            cnt[arr[l]]--;
            l++;
        }

        mx = max(mx, r - l + 1);

        r++;
    }

    cout << mx;

    return 0;
}