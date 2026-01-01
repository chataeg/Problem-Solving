#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    가장 긴 증가하는 부분 수열

    dp[i] : 해당 원소를 포함했을 때의 부분수열 길이 최댓값

*/

int dp[1007];
int arr[1007];

vector<pair<int, int>> v;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    fill(dp, dp + n, 1);
    sort(v.begin(), v.end());
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j].second < v[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << n - *max_element(dp, dp + n);

    return 0;
}

/*

    1	8
 	2	2
 	3	9
 	4	1
 	6	4
 	7	6
	9	7
 	10	10
*/