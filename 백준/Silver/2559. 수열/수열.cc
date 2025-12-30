#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int n, k;

int arr[100007];
int mx = 0x80000000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    mx = max(mx, sum);

    for (int i = 0; i < n - k; i++)
    {
        sum -= arr[i];
        sum += arr[i + k];
        mx = max(mx, sum); 
    }

    cout << mx;

    return 0;
}