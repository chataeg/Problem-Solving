#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;

set<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    // 1 3 6 7 9
    //  2     8
    // 1  1  2  1 

    // 2 3 1 2 

    // 2 1 2

    cin >> n >> k;
    while (n--)
    {
        int input;
        cin >> input;
        s.insert(input);
    }
    vector<int> v;
  
    for (auto iter : s)
        v.push_back(iter);
    
    vector<int> interval;

    for (int i = 1; i < v.size(); i++)
        interval.push_back(v[i] - v[i - 1]);

    sort(interval.begin(), interval.end());

    for (int i = 0; i < k-1; i++)
        if(!interval.empty())
            interval.pop_back();

    int sum = 0;
    for (auto iter : interval)
        sum += iter;

    cout << sum;
  
    return 0;
}