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

int cnt[101];
bool breakable[101];

vector<pair<int, int>> v[101];

int indegree[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    while (m--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        v[x].push_back({ y,k });
        indegree[y]++;
        breakable[x] = true;
    }

    queue<int> q;

    q.push(n);
    cnt[n] = 1;

    while (!q.empty())
    {
        auto cur = q.front(); 
        q.pop();

        for (auto iter : v[cur])
        {
            int next = iter.first;
            int cost = iter.second;

            cnt[next] += cnt[cur] * cost; 

            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)
        if (!breakable[i])
            cout << i << " " << cnt[i] << '\n';

    return 0;
}
