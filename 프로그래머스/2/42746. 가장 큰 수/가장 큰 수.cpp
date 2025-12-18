#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int& a, const int& b)
{
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    if(s1 + s2 > s2 + s1) return true;
    return false;
}

string solution(vector<int> numbers) {
    
    
    sort(numbers.begin(), numbers.end(), cmp);
    string ans = "";
    
    
    for(auto iter : numbers)
    {
        string tmp = to_string(iter);
        
        ans += tmp; 
    }
    
    if(ans[0] == '0') return "0";
    
    
    return ans; 
}