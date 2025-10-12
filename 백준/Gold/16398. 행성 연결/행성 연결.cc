#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m;

vector<pair<int,int>> adj[1007];
int check[1007];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cost;
			cin >> cost;

			if (i == j) continue;

			adj[i].push_back({cost, j});
			adj[j].push_back({cost, i});
		}
	}

	int cnt = 0;

	priority_queue < tuple<int, int, int>, vector <tuple<int, int, int>> , greater<tuple<int, int, int>>> minheap;

	for (auto iter : adj[0])
		minheap.push({ iter.first, 0, iter.second });

	check[0] = 1;
	

	long long ans = 0;

	while (cnt < n - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = minheap.top();
		minheap.pop();

		if (check[b]) continue;
		check[b] = 1;
		ans += cost;

		for (auto iter : adj[b])
			if(!check[iter.second])
				minheap.push({ iter.first,b,iter.second });

		cnt++;
	}

	cout << ans;

	return 0;

}