#include <string>
#include <vector>

using namespace std;


int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle);
    
    int cur = triangle.size()-1;
    
    for(; cur > 0 ; cur--)
        for(int i = 0 ; i < triangle[cur].size() - 1 ; i++)
            dp[cur-1][i] = max(dp[cur-1][i] + dp[cur][i], dp[cur-1][i] + dp[cur][i+1]);
        
    
    return dp[0][0];
}