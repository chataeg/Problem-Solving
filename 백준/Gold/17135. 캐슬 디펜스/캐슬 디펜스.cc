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

vector<vector<int>> arr(20, vector<int>(20,0));
vector<vector<int>> backup(20, vector<int>(20,0));

vector<int> pos; 

int mx;
int cnt;

int dy[3] = {0,-1,0};
int dx[3] = {-1,0,1};

vector<pair<int, int>> enemy;

void onestep()
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 0; j < m; j++)
			arr[i][j] = arr[i - 1][j];
	
	for (int i = 0; i < m; i++)
		arr[0][i] = 0;
}

void getenemy(int sty, int stx)
{
	queue<pair<int, int>> q;
	vector<vector<int>> vis(20, vector<int>(20, 0));

	q.push({ sty,stx });
	vis[sty][stx] = 1;

	if (arr[sty][stx] == 1 && d >= 1)
	{
		enemy.push_back({ sty,stx });
		return;
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 3; dir++)
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m || vis[ny][nx]) continue;

			int dist = abs(stx - nx) + abs(sty + 1 - ny);

			if (dist > d) continue;

			if (arr[ny][nx] == 1 && dist <= d)
			{
				enemy.push_back({ ny,nx });
				return;
			}

			vis[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

void shoot()
{
	for (auto iter : enemy)
	{
		if (arr[iter.first][iter.second] == 1)
		{
			arr[iter.first][iter.second] = 0;
			cnt++;
		}
	}
}

void dogame()
{
	arr = backup;
	cnt = 0;

	for (int i = 0; i < n; i++)
	{
		enemy.clear();
		for(auto iter : pos)
			getenemy(n-1,iter);	
		shoot();
		onestep();
	}
	mx = max(mx, cnt);
}


void solve(int depth, int start)
{
	if (depth == 3)
	{
		dogame();
		return;
	}

	for (int i = start; i < m; i++)
	{
		pos.push_back(i);
		solve(depth + 1, i + 1);
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

	backup = arr;

	solve(0, 0);

	cout << mx;

	return 0;
}
