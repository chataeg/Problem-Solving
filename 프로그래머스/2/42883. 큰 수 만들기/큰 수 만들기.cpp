#include <string>
#include <vector>
#include <deque>



using namespace std;
string mx = "";
int gk;
string gnumber;


string solution(string number, int k) {
    gk = k;
    gnumber = number;


    deque<char> dq;

    for (int i = 0; i < number.size(); i++)
    {

        if (dq.empty() || k == 0)
        {
            dq.push_back(number[i]);
        }
        else
        {
            while (!dq.empty() && k > 0 && dq.back() < number[i])
            {
                dq.pop_back();
                k--;
           }
            dq.push_back(number[i]);
        }
    }
    
    for (int i = 0; i < k; ++i) {
        dq.pop_back();
    }

    string ans = "";
    for (auto iter : dq)
        ans += iter;


    return ans;
}