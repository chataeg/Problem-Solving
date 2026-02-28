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

int l, c;

char arr[16];
int vis[16];

string vowel = "aeiou";

set<string> st;

bool order(string in)
{
    int cur = in[0];
    for (auto iter : in)
    {
        if (cur > iter)
            return false;
        cur = iter;
    }
    return true;
}

bool possible(string in)
{
    int v = 0;
    int c = 0;
    
    for (auto iter : in)
    {
        if(vowel.find(iter) != string::npos)
            v++;
        else
            c++;
    }

    if (v >= 1 && c >= 2) return true;
    else return false;
}

void solve(int depth, string cur)
{
    if (!order(cur)) return;

    if (depth == l)
    {
        if (order(cur) && possible(cur))
            cout << cur << '\n';
        return;
    }

    for (int i = depth; i < c; i++)
    {
        if (!vis[i])
        {
            cur.push_back(arr[i]);
            vis[i] = 1;

            solve(depth + 1, cur);

            vis[i] = 0;
            cur.pop_back();
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> arr[i];

    sort(arr, arr + c);

    solve(0, "");

    return 0;
}
