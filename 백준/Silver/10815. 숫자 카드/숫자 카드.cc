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

    int have[500000]  = {0};

    for(int i = 0 ; i < N ; i++)
    {
        cin >> have[i];
    }

    sort(have, have+N);
    int M;

    cin >> M;
    for(int i = 0 ; i < M ; i++)
    {
        int input;
        cin >> input;

        bool p = binary_search(have, have + N, input);
        
        if(p == false) cout << "0 ";
        else cout << "1 ";

    }



    return 0;
}