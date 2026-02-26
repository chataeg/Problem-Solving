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

int v, e;
int k;

int dist[20007];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

vector<pair<int, int>> adj[20007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    cin >> k;

    fill(dist, dist + v+1, 0x7ffffff);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ w,v });
    }

    dist[k] = 0;
    pq.push({ 0,k });
    

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (dist[cur.second] < cur.first) continue;

        for (auto iter : adj[cur.second])
        {
            if (dist[iter.second] > dist[cur.second] + iter.first)
            {
                dist[iter.second] = dist[cur.second] + iter.first;
                pq.push({dist[iter.second],iter.second});
            }
        }
    }

    
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == 0x7ffffff)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}
