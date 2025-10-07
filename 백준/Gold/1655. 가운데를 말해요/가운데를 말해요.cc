#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n;
int arr[100007];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	priority_queue<int,vector<int>,greater<int>> minheap;
	priority_queue<int,vector<int>,less<int>> maxheap;

	int middle = 0;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		if (maxheap.size() <= minheap.size())
			maxheap.push(input);
		else
			minheap.push(input);

		if (!minheap.empty() && minheap.top() < maxheap.top())
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