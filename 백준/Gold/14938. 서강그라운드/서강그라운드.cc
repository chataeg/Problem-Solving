#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;


int arr[107][107];

int item[107];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        cin >> item[i];


    fill(&arr[0][0], &arr[106][107], 30007);

    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;

        arr[a][b] = l;
        arr[b][a] = l;
    }

    for(int k = 1 ; k <= n ; k++)
        for(int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                




    int mn = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) sum += item[i];
            else
            {
                if (arr[i][j] <= m)
                  sum += item[j];
            }
            
  
        }
        mn = max(mn, sum);
        sum = 0;
     }

    cout << mn;

    return 0;
}