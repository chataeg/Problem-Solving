#include <iostream>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int arr[85][85];
vector<pair<int, int>> v;

bool checkright(int x, int num)
{
	for (int i = 1; i <= 9; i++)
		if (num == arr[x][i])
			return false;
	return true;
}

bool checkdown(int y, int num)
{
	for (int i = 1; i <= 9; i++)
		if (num == arr[i][y])
			return false;
	return true;
}

bool checkright()
{
	for (int i = 1; i <= 9; i++)
	{
		set<int> s;
		for (int j = 1; j <= 9; j++)
		{
			s.insert(arr[i][j]);
		}
		if (s.size() != 9) return false;
	}

	return true;
}

bool checkdown()
{
	for (int i = 1; i <= 9; i++)
	{
		set<int> s;
		for (int j = 1; j <= 9; j++)
		{
			s.insert(arr[j][i]);
		}
		if (s.size() != 9) return false;
	}
	return true;
}

bool checkbox(int x, int y, int num)
{
	x = (x-1) / 3 * 3 + 1;
	y = (y-1) / 3 * 3 + 1;
		
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (arr[i][j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool checkbox()
{
	for (int i = 1; i <= 9; i+=3)
	{
		for (int j = 1; j <= 9; j+=3)
		{
			set<int> s;
			

			for (int x = i; x <= i + 3; x++)
				for (int y = j; y <= j + 3; y++)
					s.insert(arr[x][y]);
		
			if (s.size() != 9) return false;
		}
	}
	return true;
}


void solve(int depth)
{
	if (depth == v.size())
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
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
	for (int i = 1; i <= 9; i++)
	{
	
	
		if (checkbox(x, y, i) &&
			checkdown(y, i) &&
			checkright(x, i))
		{
			arr[x][y] = i;
		}
		else
			continue;
	
		solve(depth+1);
	
		arr[x][y] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				v.push_back({ i,j });
		}


	solve(0);

	return 0;
}