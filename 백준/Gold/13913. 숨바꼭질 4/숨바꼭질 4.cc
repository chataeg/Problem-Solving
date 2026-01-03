#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
* 숨바꼭질 4
* 
*/

int n, k;

queue<int> q;
int ans;

int vis[100007];
int parent[100007];

bool inrange(int in)
{
    return in <= 100000 && in >= 0;
}

void solve()
{
    q.push( n);
    vis[n] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (!inrange(cur)) continue;

        if (cur == k)
        {
            int i = cur;
            vector<int> v;
            while (i != n)
            {
                v.push_back(i);
                i = parent[i];
            }
            
            cout << v.size() << endl << n << " ";
            for (auto iter = v.rbegin(); iter != v.rend(); iter++)
                cout << *iter << " ";
          

            return;
        }

        if (inrange(cur * 2) && !vis[cur * 2])
        {
            vis[cur * 2] = 1;
            parent[cur * 2] = cur;
            q.push(cur * 2);
        }
        if (inrange(cur - 1) && !vis[cur - 1])
        {
            vis[cur - 1] = 1;

            parent[cur -1] = cur;
            q.push(cur - 1);
        }
        if (inrange(cur + 1) && !vis[cur + 1])
        {
            vis[cur + 1] = 1;
            parent[cur + 1] = cur;
            q.push( cur + 1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    solve();

    return 0;
}
