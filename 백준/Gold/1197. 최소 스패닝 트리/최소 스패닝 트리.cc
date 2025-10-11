#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

#define w first
#define destv second

using namespace std;

int v, e;
int total_weight;

vector<pair<int, int>> g[10007];
int check[10007];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ c,b });
		g[b].push_back({ c,a });
	}

	priority_queue < tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;

	
	check[1] = 1;

	for (auto iter : g[1])
		minheap.push({iter.w, 1, iter.destv });

	int cnt = 0;

	while (cnt < v - 1)
	{
		int cost, a, b;
		tie(cost,a,b) = minheap.top(); 
		minheap.pop();
		
		if (check[b]) continue;

		total_weight += cost;
		check[b] = 1;
		cnt++;
		for (auto iter : g[b])
		{
			if(!check[iter.destv])
				minheap.push({ iter.w,b,iter.destv });
		}

	}

	cout << total_weight;

	return 0;
}