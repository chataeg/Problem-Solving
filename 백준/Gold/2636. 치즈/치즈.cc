#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;

vector<vector<int>> arr(100, vector<int>(100, 0));

vector<pair<int, int>> v;
int prevcnt;

void bfs()
{
	queue<pair<int, int>> q;
	vector<vector<int>> dist(100, vector<int>(100, -1));

	int dy[4] = {0,0,1,-1};
	int dx[4] = {1,-1,0,0};

	q.push({ 0,0 });
	dist[0][0] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (dist[ny][nx] != -1) continue;

			dist[ny][nx] = 1;

			if (arr[ny][nx] == 1)
				v.push_back({ ny,nx });
			else
				q.push({ ny,nx });
		}
	}
}

bool isend()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] != 0)
				return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	int cnt = 0;
	while (!isend())
	{
		v.clear();
		bfs();

		prevcnt = v.size();

		for (auto iter : v)
			arr[iter.first][iter.second] = 0;

		cnt++;
	}

	cout << cnt << '\n' << prevcnt;

	return 0;
}
