#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	priority_queue<int, vector<int>, greater<int>> minheap;
	priority_queue<int> maxheap;


	while (n--)
	{
		int input;
		cin >> input;

		if (maxheap.size() <= minheap.size())
			maxheap.push(input);
		else
			minheap.push(input);

		if (!minheap.empty() && maxheap.top() > minheap.top())
		{
			minheap.push(maxheap.top());
			maxheap.pop();
			maxheap.push(minheap.top());
			minheap.pop();
		}

		cout << maxheap.top() << '\n';

	}
	return 0;
}