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
string curfloor; 

int change[10][10];

string arr[10] =
{
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

void inversion()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int cnt = 0;
            for (int k = 0; k < 7; k++)
                if (arr[j][k] ^ arr[i][k]) cnt++;

            change[i][j] = cnt;
        }
    }
}

int result;

void solve(int depth, string cur, int cnt)
{
    if (cnt > p) return;

    if (depth == k)
    {
        if (stoi(cur) >= 1 && stoi(cur) <= n)
            result++;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        cur.push_back(i + '0');
        cnt += change[curfloor[depth]-'0'][i];
        solve(depth+1,cur,cnt);
        cur.pop_back();
        cnt -= change[curfloor[depth]-'0'][i];
    }

}

int main()
{
    cin >> n >> k >> p >> x;

    while (x > 0)
    {
        curfloor.push_back((x % 10) + '0');
        x /= 10;
    }
    int sze = curfloor.size();

    for (int i = 0; i < k - sze; i++)
        curfloor.push_back('0');

    reverse(curfloor.begin(), curfloor.end());

    inversion();

    solve(0,"",0);

    cout << result-1;
    return 0;
}
