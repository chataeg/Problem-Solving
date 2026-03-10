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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    /*
        1                       1
        1 5                     1
        1 2 5                   2
        1 2 5 10                2
      -99 1 2 5 10              2
      -99 1 2 5 7  10           2
      -99 1 2 5 5 7 10          5
    */

    int n;

    cin >> n;

    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;


    /*
    
        maxheap   minheap
           
           4        5
           
            
    
    */

    for(int i = 0 ; i < n ; i++)
    {
        int input;
        cin >> input;

        if (i == 0)
        {
            maxheap.push(input);
        }
        else if (minheap.empty())
        {
            minheap.push(input);

            if (maxheap.top() > minheap.top())
            {
                maxheap.push(minheap.top());
                minheap.pop();

                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        else 
        {
            maxheap.push(input);

            if (maxheap.top() > minheap.top())
            {
                maxheap.push(minheap.top());
                minheap.pop();

                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }

        if ((i + 1) % 2 == 0)
        {
            if (maxheap.size() - minheap.size() >= 2)
            {
                minheap.push(maxheap.top());
                maxheap.pop();

            }

            cout << (maxheap.top() < minheap.top() ? maxheap.top() : minheap.top()) << '\n';
        }
        else 
        {
            if (maxheap.size() < minheap.size())
                cout << minheap.top() << '\n';
            else
                cout << maxheap.top() << '\n';
        }

    }

    return 0;
}
