#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void func(int a, int b, int n)
{
    if(n == 1)
    {
        answer.push_back({a,b});
        return;
    }
    
    func(a,6-a-b, n-1);
    func(a,b,1);
    func(6-a-b,b, n-1);
}

vector<vector<int>> solution(int n) {
   
    func(1,3,n);
    
    return answer;
}