#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos {
	int y;
	int x;
};
int r, c, t;

int arr[55][55];
int tmp[55][55];

pos head;
pos body;

void executehead()
{
	queue<int> q;


	pos cur = { head.y,head.x };
	int dy[4] = { 0,-1,0,1 };
	int dx[4] = { 1,0,-1,0 };

	q.push(0);

	int dir = 0;
	while (1)
	{

		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];

		if (nx < 0 || ny < 0 || ny >= r || nx >= c)
		{
			dir++;
			continue;
		}

		if (arr[ny][nx] == -1 && nx == 0)
		{
			break;
		}

		q.push(arr[ny][nx]);
		cur = { ny,nx };
	}

	cur = { head.y , head.x };
	dir = 0;

	while (1)
	{

		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];

		if (nx < 0 || ny < 0 || nx >= c || ny >= r)
		{
			dir++;
			continue;
		}

		if (arr[ny][nx] == -1 && nx == 0)
		{
			break;
		}

		arr[ny][nx] = q.front();
		q.pop();
		cur = { ny,nx };
	}


}

void executebody()
{
	queue<int> q;

	pos cur = { body.y,body.x };
	int dy[4] = { 0,1,0,-1 };
	int dx[4] = { 1,0,-1,0 };

	q.push(0);

	int dir = 0;
	while (1)
	{

		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];

		if (nx < 0 || ny < 0 || ny >= r || nx >= c)
		{
			dir++;
			continue;
		}

		if (arr[ny][nx] == -1 && nx == 0)
		{
			break;
		}

		q.push(arr[ny][nx]);
		cur = { ny,nx };
	}

	cur = { body.y , body.x };
	dir = 0;

	while (1)
	{

		int ny = cur.y + dy[dir];
		int nx = cur.x + dx[dir];

		if (nx < 0 || ny < 0 || ny >= r || nx >= c)
		{
			dir++;
			continue;
		}

		if (arr[ny][nx] == -1 && nx == 0)
		{
			break;
		}

		arr[ny][nx] = q.front();
		q.pop();
		cur = { ny,nx };
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> t;


	bool found = false;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];

			if (!found && arr[i][j] == -1)
			{
				head = { i,j };
				body = { i+1,j };
				found = true;
			}
		}
	}

	for (int tcase = 0; tcase < t; tcase++)
	{
		int dx[4] = { 1,-1,0,0 };
		int dy[4] = { 0,0,-1,1 };

		memcpy(tmp, arr, sizeof(arr));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (tmp[i][j] > 0)
				{

					int spread = tmp[i][j] / 5;


					for (int dir = 0; dir < 4; dir++)
					{
						int ny = i + dy[dir];
						int nx = j + dx[dir];

						if (nx < 0 || ny >= r || ny < 0 || nx >= c)
							continue;
						if (arr[ny][nx] == -1)
							continue;

						arr[ny][nx] += spread;
						arr[i][j] -= spread;
					}

				}


			}
		}

		executebody();
		executehead();
	}

	int sum = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (arr[i][j] != -1)
				sum += arr[i][j];
		}
	}

	cout << sum;

	return 0;
}