#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int n;

pair<int,int> arr[1000007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    
    sort(arr, arr + n);

    pair<int, int> cur;

    cur.first = arr[0].first;
    cur.second = arr[0].second;
    long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first <= cur.second && arr[i].second >= cur.second )
        {
            cur.second = arr[i].second;
        }
        
        if (arr[i].first > cur.second)
        {
            sum += cur.second - cur.first;
            cur = arr[i];
        }
    }
    
    sum += cur.second - cur.first;

    cout << sum;

    return 0;
}
