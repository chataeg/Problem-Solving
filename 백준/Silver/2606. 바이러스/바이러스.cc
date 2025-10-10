#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> g[101];
int dist[101];

void dfs(int curnum, int curcount)
{
	dist[curnum] = curcount;

	for (int nextnum : g[curnum])
	{
		if (dist[nextnum] == -1)
		{
			dfs(nextnum, curcount + 1);
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		g[a].push_back(b);
		g[b].push_back(a);
	}

	fill(dist, dist + n + 1, -1);
	
	dfs(1, 0);

	int infected_count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != -1)
		{
			infected_count++;
		}
	}

	cout << infected_count - 1 << '\n';

	return 0;
}