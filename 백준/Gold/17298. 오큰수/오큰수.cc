#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;


stack<int> s;
int arr[1000007];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    // 7 2 5 3 
    // 8 4 5 9
    

    // 7 2 5 3
    // 3 2 7

    // 5  7 7 -1

    // 9 5 4 8
    // -1 8 8 -1
    // 
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr[i] = input;
    }

    // 3 5 2 7 

    // arr
    //       5

    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            if (s.empty())
            {
                s.push(i);
                break;
            }

            if (arr[i] > arr[s.top()])
            {
                arr[s.top()] = arr[i];
                s.pop();
            }
            else
            {
                s.push(i);
                break; 
            }
        }
    }
    
    while (!s.empty())
    {
        int idx = s.top();
        arr[idx] = -1;
        s.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}