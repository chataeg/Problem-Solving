#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int arr[100007];
int N;

int binarysearch(int querynum)
{
	int st, mid, ed;
	
	st = 0;
	ed = N-1;
	
	while (st <= ed)
	{
		mid = (st + ed) / 2;

		if (arr[mid] > querynum)
		{
			ed = mid - 1;
		}
		else if (arr[mid] < querynum)
		{
			st = mid + 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;


	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int M;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;

		cout << binarysearch(input) << '\n';
	}
	


	return 0;
}