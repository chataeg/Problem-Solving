#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;

    cin >> N;
    int M;

    cin >> M;

    string have[10000];

    for(int i = 0 ; i < N ; i++)
    {
        cin >> have[i];
    }

    sort(have, have+N);
    int cnt = 0;
    
    for(int i = 0 ; i < M ; i++)
    {
        string input;
        cin >> input;

        bool p = binary_search(have, have + N, input);
        
        if(p != false) cnt++;
        
    }

    cout << cnt;


    return 0;
}