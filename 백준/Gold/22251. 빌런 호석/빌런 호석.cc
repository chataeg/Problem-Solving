#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int n, k, p, x;
vector<int> curfloor;

int change[10][10];

int arr[10] =
{
    0b1110111,
    0b0010010,
    0b1011101,
    0b1011011,
    0b0111010,
    0b1101011,
    0b1101111,
    0b1010010,
    0b1111111,
    0b1111011
};

void inversion()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            change[i][j] = __builtin_popcount(arr[j] ^ arr[i]);
        }
    }
}

int result;

void solve(int depth, int cur, int cnt)
{
    if (cnt > p) return;

    if (depth == k)
    {
        if (cur >= 1 && cur <= n)
            result++;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        solve(depth+1,cur * 10 + i, cnt + change[curfloor[depth]][i]);
    }

}

int main()
{
    cin >> n >> k >> p >> x;

    for(int i = 0 ; i < k ; i++)
    {
        curfloor.push_back((x % 10));
        x /= 10;
    }
    reverse(curfloor.begin(), curfloor.end());
    
    inversion();

    solve(0,0,0);

    cout << result - 1;
    return 0;
}
