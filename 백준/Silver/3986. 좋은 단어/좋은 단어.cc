#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <algorithm>
#include <list>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;

    cin >> n;



    int cnt = 0;
    while (n--)
    {
        stack<int> s;

        string input;
        cin >> input;
        for (int i = 0; i < input.size(); i++)
        {
            if (s.empty())
            {
                s.push(input[i]);
            }
            else
            {
                if (s.top() == input[i])
                    s.pop();
                else
                    s.push(input[i]);
            }
        }
        if (s.size() == 0) cnt++;
    }

    cout << cnt; 


    return 0;
}