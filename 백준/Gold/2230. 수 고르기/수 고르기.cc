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

int n, m;

int arr[100007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    
    int l = 0;
    int r = 0;
    
    int mn = 0x7fffffff;

    while (l < n)
    {
        int diff = arr[r] - arr[l];
        
        if (diff < m)
        {
            r++;
        }
        else
        {
            mn = min(mn, diff);
            l++;
        }
    }

    cout << mn;

    return 0;
}
