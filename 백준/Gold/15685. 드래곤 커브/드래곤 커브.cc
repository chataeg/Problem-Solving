#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

vector<vector<int>> arr(101, vector<int>(101, 0));

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
int n;

void dragon(int x, int y, int d, int g)
{
	vector<int> trail;
	
	arr[y][x] = 1;
	y += dy[d];
	x += dx[d];
	arr[y][x] = 1;
	trail.push_back(d);
	int curg = 0;

	while(curg < g)
	{
		int size = trail.size();
		for (int i = size - 1; i >= 0; i--)
		{
			int next = (trail[i] + 1) % 4;
			y += dy[next];
			x += dx[next];
			arr[y][x] = 1;
			trail.push_back(next);
		}
		curg++;
	}
}

int check()
{
	int cnt = 0;

	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			
			if (i + 1 >= 101 || j + 1 >= 101) continue;

			if ((arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1]) == 4)
				cnt++;
		}
	}
	
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	while (n--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		dragon(x, y, d, g);

	}

	cout << check();
	return 0;
}