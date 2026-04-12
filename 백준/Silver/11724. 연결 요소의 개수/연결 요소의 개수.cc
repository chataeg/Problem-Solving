#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

vector<int> g[1007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<int> q;

	int vis[1007];
	fill(vis, vis + n+1, 0);
	
	int cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			q.push(i);
			vis[i] = 1;
			cnt++;
			while (!q.empty())
			{
				auto cur = q.front(); q.pop();

				for (auto iter : g[cur])
				{
					if (!vis[iter])
					{
						vis[iter] = 1;
						q.push(iter);
					}
				}
			}
		}
	}
	
	cout << cnt;
	
	

	return 0;
}