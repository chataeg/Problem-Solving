#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;
int n, m;

vector<int> p(1007, -1);


int find(int num)
{
	if (p[num] < 0)
		return num;
	return p[num] = find(p[num]); // 재귀로 인해 타고 온 길을 root 로 최적화
}

bool uni(int u, int v)
{
	u = find(u);  // 루트 찾기
	v = find(v);  // 루트 찾기

	if (u == v)
		return false; // 루트가 같은 경우
	if (p[u] < p[v]) // u 의 랭크가 더 큰 경우
		swap(u, v);  // swap  (트리 높이 최대한 낮게 유지하기 위해)
	if (p[u] == p[v]) // 랭크가 같은 경우 
		p[u]--;		// u 의 랭크 증가
	p[v] = u;  // v 를 u의 자식으로 만든다.
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; 

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cost;
			cin >> cost;
			if (i <= j) continue;

			minheap.push({ cost,i,j });
		}
	}
	
	int cnt = 0;
	long long ans = 0;

	while (cnt < n - 1)
	{
		int cost, a, b;
		tie(cost, a, b) = minheap.top();
		minheap.pop();

		if (find(a) == find(b)) continue;
		else
		{
			uni(a, b);
			ans += cost;
			cnt++;
		}
	}

	cout << ans;

	return 0;
}