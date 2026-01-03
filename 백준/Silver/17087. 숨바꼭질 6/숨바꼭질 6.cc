#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>


using namespace std;

int n, s;

int arr[100007];

int euclid(int a, int b)
{
    if (a % b == 0) return b;
    return euclid(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(abs(arr[i] - s));

    int cur = v[0];

    for (int i = 1; i < n; i++)
        cur = euclid(cur, v[i]);
   
    cout << cur;

    return 0;
}
