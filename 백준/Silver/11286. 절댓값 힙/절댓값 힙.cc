#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[100007];
int n;
int ind;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    while (n--)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout <<  pq.top().second << endl;
                pq.pop();
            }
        }
        else
        {
            pq.push({ abs(input), input });
        }
    }



    return 0;
}