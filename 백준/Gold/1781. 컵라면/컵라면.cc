#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n;

priority_queue<pair<int, int>> pq;

int hasharr[200007];
int unionfind[200007];

int find(int i)
{
	if ( unionfind[i] == i)
		return i;

	return unionfind[i] = find(unionfind[i]);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		int a, b;
		cin >> a >> b;

		pq.push({ b,a });
	}


	long long sum = 0;

	for (int i = 1; i < 200007; i++)
		unionfind[i] = i;

	while (!pq.empty())
	{
		auto curweight = pq.top().first;
		auto curdeadline = pq.top().second;
		pq.pop();
		
		int timeslot = find(curdeadline);

		if (timeslot > 0)
		{
			sum += curweight;
			unionfind[timeslot] = timeslot - 1;
		}
	}

	cout << sum;

	return 0;
}