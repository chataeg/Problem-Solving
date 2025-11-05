#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main() {

    int input;

    cin >> input;

    stack<int> s;
    stack<int> result;

    int arr[1000000] ;

    for(int i = 0 ; i < input ; i++)
    {
        int tmp;
        cin >> tmp;

        arr[i] = tmp;
    }

    for(int i = 0 ; i < input ; i++)
    {

        while(1)
        {
            if(s.empty())
            {
                s.push(i);
                break;
            }

            if(arr[i] > arr[s.top()])
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

    while(!s.empty())
    {
        int idx = s.top();
        arr[idx] = -1;
        s.pop();
    }

    for(int i = 0 ; i < input ; i++)
    {
        cout << arr[i] <<' ';
    }



    return 0;
}
