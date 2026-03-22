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

int arr[1000007];

int dp[1000007];

int mx = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
        7   2   3   5   4   6   1

        in order 2 3 4
        not ordered 7 5 6 1
    */

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    dp[arr[0]] = 1;

    for (int i = 1; i < n; i++)
        dp[arr[i]] = max(dp[i], dp[arr[i]-1] + 1);

    
    bool alreadysorted = true;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != i+1)
        {
            alreadysorted = false;
            break;
        }
    }
    
    if (alreadysorted)
        cout << 0;
    else
        cout << n - *max_element(dp, dp + n);
   
    return 0;
}
