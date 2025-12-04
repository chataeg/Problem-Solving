#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size(); 
    stack<int> s;
    
    vector<int> answers(n,0);
    
    for(int i = 0 ; i < n ; i++)
    {
        
        
        while(!s.empty() && prices[s.top()] > prices[i])
        {
            answers[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
    }
    
    while(!s.empty())
    {
        
        answers[s.top()] = n - 1 - s.top();
        
        s.pop();
    }
    
    return answers;
    
    
}