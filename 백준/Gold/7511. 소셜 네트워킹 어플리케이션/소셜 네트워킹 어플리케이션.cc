#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m;

vector<int> p(1000007, -1);


int find(int num)
{
	if (p[num] < 0)
		return num;
	return p[num] = find(p[num]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	if (p[u] < p[v])
		swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	int k;

	for(int i = 0 ; i < t ; i++)
	{

		cin >> n >> k;
		fill(p.begin() + 1, p.begin() + n + 1, -1);
		while (k--)
		{
			int a, b;
			cin >> a >> b;
			uni(a, b);
		}

		cin >> m;

		cout << "Scenario " << i + 1 << ":\n";

		while (m--)
		{
			int u, v;
			cin >> u >> v;

			if (find(u) == find(v))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}

		cout << endl;
	}



	return 0;
}