#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> g[1007];

int indeg[1007];

int vis[1007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    while (m--)
    {
        int t;
        cin >> t;

        int prev = 0;
        while (t--)
        {
            int input;
            cin >> input;

            if (prev != 0)
            {
                g[input].push_back(prev);
                indeg[prev]++;
            }

            prev = input;
        }
    }





    queue<int> q;
    vector<int> ans;



    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
            ans.push_back(i);
        }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto iter : g[cur])
        {
            indeg[iter]--;
            vis[iter] = 1;

            if (indeg[iter] == 0)
            {
                q.push(iter);
                ans.push_back(iter);
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i] == 1)
            cnt++;
    
    if (cnt < n)
    {
        cout << 0;
        return 0;
    }

    reverse(ans.begin(), ans.end());

    for (auto iter : ans)
        cout << iter << "\n";
   
    return 0;
}
