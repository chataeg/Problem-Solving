#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int g[105][105];
int vis[105];

bool dfs(int start,int target)
{
	fill(vis, vis + n + 2, 0);

	stack<int> s;
	s.push(start);

	while (!s.empty())
	{
		auto cur = s.top(); s.pop();
		
		if (vis[cur]) continue;
		if (cur != start) vis[cur] = 1;

		for (int nxt = 0; nxt < n; nxt++) 
		{
			if (vis[nxt]) continue;
			if (g[cur][nxt]) 
			{
				if (nxt == target) return true;
				s.push(nxt);
			}
		}
	}
	return false;
}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
			

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dfs(i, j) << " ";
		}
		cout << '\n';
	}


	return 0;
}