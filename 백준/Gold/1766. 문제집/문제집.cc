#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> g[32007];
int indeg[32007];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	while (m--)
	{
		int a, b;

		cin >> a >> b;

		g[a].push_back(b);
		indeg[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	vector<int> v;

	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			pq.push(i);

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		v.push_back(cur);

		for (auto iter : g[cur])
		{
			indeg[iter]--;

			if (indeg[iter] == 0)
				pq.push(iter);
		}
	}

	for (auto iter : v)
		cout << iter << " ";

	return 0;
}
