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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;

    while (n--)
    {
        int in;
        cin >> in;
        pq.push(in);
    }

    int a = 0;
    int b = 0;
    int cnt = 0;
    while (!pq.empty())
    {
        if (a == 0)
        {
            a = pq.top();
            pq.pop();
        }

        if (pq.empty())
        {
            break;
        }

        if (b == 0)
        {
            b = pq.top();
            pq.pop();
        }

        pq.push(a + b);

        cnt += a + b;

        a = 0;
        b = 0;
    }

    cout << cnt;

    return 0;
}
