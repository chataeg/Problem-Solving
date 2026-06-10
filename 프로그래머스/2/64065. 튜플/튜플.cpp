#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<int> candid[1000007];

vector<int> solution(string s) {
  
    int sze = s.length();

    int cnt = 0;
    bool isset = false;

    queue<int> q;

    for (int i = 1; i < sze - 1; ++i)
    {
        if (s[i] == '{')
        {
            isset = true;
        }
        else if (s[i] == '}')
        {
            if (isset)
            {
                int num = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    num = num * 10 + cur;
                }

                candid[cnt].push_back(num);
            }

            ++cnt;
            isset = false;
        }
        else if (s[i] == ',')
        {
            if (isset)
            {
                int num = 0;

                while (!q.empty())
                {
                    auto cur = q.front();
                    q.pop();
                    num = num * 10 + cur;
                }

                candid[cnt].push_back(num);
            }
        }
        else
        {
            q.push(s[i] - '0');
        }
    }


    sort(candid, candid + cnt, [&](const auto& a, const auto& b) {
        return a.size() < b.size(); });

    set<int> st;
    vector<int> answer;

	answer.push_back(candid[0][0]);
	st.insert(candid[0][0]);
   
    for (int i = 1; i < cnt; i++)
    {
        for (int j = 0; j < candid[i].size(); j++)
        {
            auto result = st.find(candid[i][j]);

            if (result == st.end())
            {
                answer.push_back(candid[i][j]);
                st.insert(candid[i][j]);
            }

        }
    }



    return answer;
}
