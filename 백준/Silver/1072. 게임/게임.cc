#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <climits>
#include <cmath>
using namespace std;


long long x, y;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;

  


    long long l = 1;
    long long r = 2000000000;

    auto cal = [](long long a, long long b) {
        return (a * 100 / b );
        };

    long long prev = cal(y, x);

    if (prev >= 99)
    {
        cout << -1;
        return 0;
    }

    long long ans = 0;
    while (l <= r)
    {
        long long mid = (l + r + 1) / 2;

        if (cal(y+mid,x+mid) > prev)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;
}