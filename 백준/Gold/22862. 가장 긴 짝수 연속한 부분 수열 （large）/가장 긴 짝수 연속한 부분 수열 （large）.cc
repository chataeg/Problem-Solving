#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
long long arr[1000007];
int mx; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;

    int l, r;
    l = 0;
    r = 0;

    while (r < n)
    {
        if (arr[r] % 2 != 0)
            cnt++;

        while (cnt > k)
        {
            if (arr[l] % 2 != 0)
                cnt--;
            l++;
        }

        mx = max(mx, r - l + 1 - cnt);

        r++;
    }

    cout << mx;


    return 0;
}