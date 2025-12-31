#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

int fib(int cur)
{

    if (cur == 0) return 0;
    if (cur == 1) return 1;
    
    return fib(cur - 1) + fib(cur - 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cout << fib(n);

    return 0;
}