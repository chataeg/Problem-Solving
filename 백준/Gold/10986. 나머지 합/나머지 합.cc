#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;

long long arr[1000007];
long long mem[1000007];
long long mod[1000007];

long long cnt = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    mem[1] = arr[0];

    for (int i = 1; i < n; i++)
        mem[i + 1] = mem[i] + arr[i];

    for (int i = 1; i <= n; i++)
        mod[mem[i] % m]++;

    for (int i = 0; i < m; i++)
        cnt += mod[i] * (mod[i] - 1) / 2;

    cnt += mod[0];

    cout << cnt;

    return 0;
}