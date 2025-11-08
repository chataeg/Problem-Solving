#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9][9];
vector<pair<int, int>> v; 

bool checkRow(int x, int num)
{
	for (int i = 0; i < 9; i++)
		if (num == arr[x][i])
			return false;
	return true;
}

bool checkCol(int y, int num)
{
	for (int i = 0; i < 9; i++)
		if (num == arr[i][y])
			return false;
	return true;
}

bool checkbox(int x, int y, int num)
{
	int start_x = x / 3 * 3;
	int start_y = y / 3 * 3;

	for (int i = start_x; i < start_x + 3; i++)
	{
		for (int j = start_y; j < start_y + 3; j++)
		{
			if (arr[i][j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

void solve(int depth)
{
	if (depth == v.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}

		exit(0);

		return;
	}

	int x = v[depth].first;
	int y = v[depth].second;

	for (int num = 1; num <= 9; num++)
	{
		if (checkbox(x, y, num) &&
			checkCol(y, num) &&
			checkRow(x, num))
		{
			arr[x][y] = num;
		}
		else
			continue; 

		solve(depth + 1); 

		arr[x][y] = 0; 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v.push_back({ i,j });
		}


	solve(0);

	return 0;
}