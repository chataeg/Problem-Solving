#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m;

vector<pair<int, int>> g[100007];

int check[100007];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		g[from].push_back({ cost,to });
		g[to].push_back({ cost,from });
	}

	priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;
	priority_queue <tuple<int, int, int>> maxheap;
	int ans = 0, cnt = 0;

	for (auto iter : g[1])
		minheap.push({ iter.first,1,iter.second });

	check[1] = 1;

	while (cnt < n - 1)
	{
		int cost, from, to;
		tie(cost, from, to) = minheap.top();
		minheap.pop(); 

		if (check[to]) continue;
		check[to] = 1;
		ans += cost;
		maxheap.push({ cost,from,to });

		for (auto iter : g[to])
			if (!check[iter.second])
				minheap.push({ iter.first,to,iter.second });

		cnt++;
	}

	cout << ans - get<0>(maxheap.top());

	return 0;
}