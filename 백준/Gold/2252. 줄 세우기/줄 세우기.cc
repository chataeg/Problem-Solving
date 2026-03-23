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

int n, m;

vector<int> g[40007];

int indeg[40007];

vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        g[b].push_back(a);
        indeg[a]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
        {
            q.push(i);
            ans.push_back(i);
        }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto iter : g[cur])
        {
            indeg[iter]--;

            if (indeg[iter] == 0)
            {
                ans.push_back(iter);
                q.push(iter);
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto iter : ans)
        cout << iter << " ";
   
    return 0;
}
