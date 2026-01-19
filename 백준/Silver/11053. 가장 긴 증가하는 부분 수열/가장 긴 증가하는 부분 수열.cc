#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> a, dp;


    int N;
    cin >> N;

       
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        a.push_back(input);
    }
    
    dp.assign(N, 1);

    int ans = 0;
    


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
     
        ans = max(dp[i], ans);
    }

    cout << ans;



    return 0;
}

