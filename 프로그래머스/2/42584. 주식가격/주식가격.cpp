#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size(); 
    
    vector<int> ans(n,0);
    stack<int> s;
    
    // 1 3 5 4 3 1
    // 4 3 1 1 1 0 
    
    // 1 2 3 2 2
    // 4 3 1 1 0
    
    
    for(int i = 0 ; i < n ; i++)
    {
        
        while(!s.empty() && prices[s.top()] > prices[i])
        {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
    }

    while(!s.empty())
    {
        
        ans[s.top()] = n - 1 - s.top();
        s.pop();
    }
    
    return ans;
    
}