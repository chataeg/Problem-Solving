#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    stack<int> s;
    
    for(auto iter = arr.rbegin() ; iter != arr.rend() ; iter++)
        s.push(*iter);
    
    
    
    while(1)
    {
        auto cur = s.top();
        s.pop();
        if(s.empty())
        {
            answer.push_back(cur);
            break;
        }
        if(!s.empty() && cur != s.top())
        {
            answer.push_back(cur);
        }
    }
    
    

    return answer;
}