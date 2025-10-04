#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> g[505];
queue<int> q;
int dist[505];
int ans = 0;


void bfs(int start)
{
	fill(dist, dist + 504, -1);

	dist[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto iter : g[cur])
		{
			if (dist[iter] == -1)
			{
				q.push(iter);
				dist[iter] = dist[cur] + 1;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	while (m--)
	{
		int a, b;
		cin >> a >> b;

		g[a].push_back(b);
		g[b].push_back(a);
	}

	bfs(1);

	for (auto iter : dist)
		if (iter <= 2 && iter >= 1) ans++;
	
	cout << ans;

	return 0;
}