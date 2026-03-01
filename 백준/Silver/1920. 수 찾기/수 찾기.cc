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
int arr[100007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int t;
    cin >> t;
    while (t--)
    {
        int target;
        cin >> target;


        int l = 0;
        int r = n - 1;
        int mid = 0;
        while (l <= r)
        {
            mid = (l + r + 1) / 2;

            if (arr[mid] > target)
            {
                r = mid - 1;
            }
            else if (arr[mid] < target)
            {
                l = mid +1;
            }
            else
                break;
        }

        // 1 2 3 4 5

        if (arr[mid] == target)
            cout << "1\n";
        else
            cout << "0\n";

    }

    




    return 0;
}
