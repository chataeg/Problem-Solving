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

int dy[3] = {0,-1,0};
int dx[3] = {-1,0,1};

int mx = 0;

vector<int> pos;

vector<pair<int, int>> res;
int cnt;
int vis[20][20];

void onestep()
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr[i - 1][j];

	for (int j = 0; j < m; j++)
		arr[0][j] = 0;
}

int getdist(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void shoot(int start)
{
	queue<pair<int, int>> q;

	memset(vis, 0, sizeof(vis));
	
	if (arr[n - 1][start] == 1 && d >= 1)
	{
		res.push_back({ n - 1,start });
		return;
	}

	
	q.push({ n-1,start });

	vis[n - 1][start] = 1;


	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (vis[ny][nx]) continue;

			if (getdist({ ny,nx }, { n,start }) > d) continue;


			if (arr[ny][nx] == 1)
			{
				res.push_back({ ny,nx });
				return;
			}
			
			vis[ny][nx] = 1;
			q.push({ ny,nx });

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

		for(auto iter : pos)
			shoot(iter);

		for (auto iter : res)
		{
			if (arr[iter.first][iter.second] == 1)
			{
				arr[iter.first][iter.second] = 0;
				cnt++;
			}

		}
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
