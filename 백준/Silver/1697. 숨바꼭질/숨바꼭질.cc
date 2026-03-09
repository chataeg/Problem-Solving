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

int n, k;

int vis[100007];

bool inrange(int in)
{
    return in >= 0 && in <= 100000;
}
void bfs(int start)
{
    queue<pair<int,int>> q;

    q.push({ 0,start });
    vis[start] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.second == k)
        {
            cout << cur.first;
            return;
        }
        

        int a = cur.second - 1;
        int b = cur.second + 1;
        int c = cur.second * 2;

        if (inrange(a) && !vis[a])
        {
            vis[a] = true;
            q.push({ cur.first+1, a });
        }
        if (inrange(b) && !vis[b])
        {
            vis[b] = true;
            q.push({ cur.first+1, b });
        }
        if (inrange(c) && !vis[c]) 
        {
            vis[c] = true;
            q.push({ cur.first+1, c });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
      
    bfs(n);

    return 0;
}
