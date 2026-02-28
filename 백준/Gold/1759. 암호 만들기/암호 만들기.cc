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
string vowel = "aeiou";

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
    if (cur.length() == l)
    {
        if (possible(cur))
            cout << cur << '\n';
        return;
    }

    for (int i = depth; i < c; i++)
    {
        cur.push_back(arr[i]);
        solve(i + 1, cur);
        cur.pop_back();
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
