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

vector<pair<int, int>> adj[107];

set<int> s;
int cnt[107];
int indeg[107];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    while (m--)
    {
        int x, y, k;
        
        cin >> x >> y >> k;

        adj[x].push_back({y,k});
        indeg[y]++;
        s.insert(x);
    }

    queue<int> q;
    q.push(n);

    cnt[n] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (auto iter : adj[cur])
        {
            indeg[iter.first]--;
            
            cnt[iter.first] += cnt[cur] * iter.second;

            if (indeg[iter.first] == 0)
                q.push(iter.first);
        }
    }
    
    for (int i = 1; i <= n; i++)
        if(s.find(i) == s.end())
            cout << i << " " << cnt[i] << endl; 

    return 0;
}
