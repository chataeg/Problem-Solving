#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, d;
int backup[20][20];
int arr[20][20];

int mx = 0;

int vis[20];
vector<int> pos;

vector<pair<int, int>> res;
int cnt;

void onestep()
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr[i - 1][j];
}

int getdist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void getenemy()
{
	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 1)
				res.push_back({ i,j });
}

void shoot()
{
	vector<pair<int, int>> candid;
	for (auto arch : pos)
	{
		int size = res.size();
		vector < tuple <int, int, int >> v;

		for (int i = 0; i < size; i++)
		{
			int dist = getdist(res[i], { n,arch });
			if (dist <= d)
				v.push_back({ dist, res[i].second, res[i].first});
		}
		sort(v.begin(), v.end());

		if (!v.empty())
			candid.push_back({ get<2>(v.front()),get<1>(v.front()) });
	}

	for (auto iter : candid)
	{
		if (arr[iter.first][iter.second] == 1)
		{
			arr[iter.first][iter.second] = 0;
			cnt++;
		}
	}
}

void dodefense()
{
	memcpy(arr, backup, sizeof(arr));

	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		res.clear();
		getenemy();
		shoot();
		onestep();
	}

	mx = max(mx, cnt);
}

void solve(int depth, int start)
{
	if (depth == 3)
	{
		dodefense();

		return;
	}

	for (int i = start; i < m; i++)
	{
		pos.push_back(i);
		solve(depth + 1, i+1);
		pos.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	memcpy(backup, arr, sizeof(arr));

	solve(0, 0);

	cout << mx;

	return 0;
}
