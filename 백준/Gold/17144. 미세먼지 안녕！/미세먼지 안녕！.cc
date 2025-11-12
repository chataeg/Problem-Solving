#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct pos {
	int x;
	int y;
};
int r, c, t;

int arr[55][55];
int tmp[55][55];

pos head;
pos body;

void executehead()
{
	queue<int> q;


	pos cur = { head.x,head.y };
	int dx[4] = {0,-1,0,1};
	int dy[4] = {1,0,-1,0};

	q.push(0);

	int dir = 0;
	while (1)
	{
	
		int nx = cur.x + dx[dir];
		int ny = cur.y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
		{
			dir++;
			continue;
		}

		if (arr[nx][ny] == -1 && ny == 0)
		{
			break;
		}

		q.push(arr[nx][ny]);
		cur = { nx,ny };
	}
	
	cur = { head.x , head.y };
	dir = 0;

	while (1)
	{
		
		int nx = cur.x + dx[dir];
		int ny = cur.y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
		{
			dir++;
			continue;
		}

		if (arr[nx][ny] == -1 && ny == 0)
		{
			break;
		}

		arr[nx][ny] = q.front();
		q.pop();
		cur = { nx,ny };
	}


}

void executebody()
{
	queue<int> q;

	pos cur = { body.x,body.y };
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	q.push(0);

	int dir = 0;
	while (1)
	{

		int nx = cur.x + dx[dir];
		int ny = cur.y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
		{
			dir++;
			continue;
		}

		if (arr[nx][ny] == -1 && ny == 0)
		{
			break;
		}

		q.push(arr[nx][ny]);
		cur = { nx,ny };
	}

	cur = { body.x , body.y };
	dir = 0;

	while (1)
	{

		int nx = cur.x + dx[dir];
		int ny = cur.y + dy[dir];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
		{
			dir++;
			continue;
		}

		if (arr[nx][ny] == -1 && ny == 0)
		{
			break;
		}

		arr[nx][ny] = q.front();
		q.pop();
		cur = { nx,ny };
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
				body = { i + 1,j };
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
						int nx = i + dx[dir];
						int ny = j + dy[dir];

						if (nx < 0 || nx >= r || ny < 0 || ny >= c)
							continue;
						if (arr[nx][ny] == -1)
							continue;

						arr[nx][ny] += spread;
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