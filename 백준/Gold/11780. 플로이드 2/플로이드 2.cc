#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

const int INF = 0x3f3f3f3f;
int g[107][107];
int nxt[107][107];

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	fill(&g[0][0], &g[106][107], INF);

	while (m--)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		
		if(g[a][b] > cost)
			g[a][b] = cost;

		nxt[a][b] = b;
	}

	for (int i = 1; i <= n; i++) g[i][i] = 0;


	for (int num = 1; num <= n; num++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (g[i][num] + g[num][j] < g[i][j]) 
				{
					g[i][j] = min(g[i][j], g[i][num] + g[num][j]);
					nxt[i][j] = nxt[i][num];
				}
			}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j] == INF) cout << 0 << " ";
			else cout << g[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j] == INF || g[i][j] == 0)
			{
				cout << "0\n";
				continue;
			}
			vector<int> path;
			
			int cur = i;
			
			while (cur != j)
			{
				path.push_back(cur);
				cur = nxt[cur][j];
			}
			path.push_back(j);
			cout << path.size() << " ";
			for (auto iter : path)
				cout << iter << ' ';
			cout << endl;
		}
	}

	
	return 0;
}