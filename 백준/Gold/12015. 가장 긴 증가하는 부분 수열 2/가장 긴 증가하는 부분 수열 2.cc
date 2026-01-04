#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int arr[1000007];

vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    v.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (*(v.end() - 1) < arr[i])
        {
            v.push_back(arr[i]);
        }
        else
        {
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
        }

        /*for (auto iter : v)
        {
            cout << iter << " ";
        }
        cout << endl;*/
    }

    cout << v.size();


    return 0;
}
