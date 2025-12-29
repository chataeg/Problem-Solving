#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int n, k;

long long sum;
int arr[100007];

int a, b;

long long mn = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int l, r;

    l = 0;
    r = n - 1;

    if (arr[l] >= 0)
    {
        a = arr[l];
        b = arr[l + 1];
    }
    else if (arr[r] < 0)
    {
        a = arr[r - 1];
        b = arr[r];
    }
    else
    {
        while (l < r)
        {
            sum = arr[l] + arr[r];

            long long oldmn = abs(mn);

            mn = min(abs(mn), abs(sum));

            if (mn != oldmn)
            {
                a = arr[l];
                b = arr[r];
            }

            if (sum >= 0) r--;
            else if (sum < 0) l++;
        }
    }

    cout << a << " " << b;

    return 0;
}