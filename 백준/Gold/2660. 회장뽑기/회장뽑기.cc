#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

int n;

vector<int> g[55];
int dist[55];


vector<int> ans[55];

void bfs(int start)
{
	
	fill(dist, dist + n + 1, -1);

	queue<int> q;

	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto iter : g[cur])
		{
			if (dist[iter] == -1)
			{
				dist[iter] = dist[cur] + 1;
				q.push(iter);
			}
		}
	}

	ans[*max_element(dist, dist + n + 1)].push_back(start);

}



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int a=0 , b = 0;

	while (a != -1 && b != -1)
	{
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}


	for (int i = 1; i <= n; i++)
		bfs(i);
	

	int mnscore = 0;
	int mnsize = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (ans[i].size() != 0)
		{
			mnscore = i; 
			mnsize = ans[i].size();
			sort(ans[i].begin(), ans[i].end());
			break;
		}
	}

	cout << mnscore << " " << mnsize << '\n';
	
	for (auto iter : ans[mnscore])
		cout << iter << ' ';



	return 0;
}