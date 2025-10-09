#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    list<int> l;

    for(int i = 0 ; i < operations.size() ; i++)
    {
        string numstring = operations[i].substr(2);
        int num= 0;
        if(numstring[0] == '-')
        {
            numstring = numstring.substr(1);
            num = -stoi(numstring);
        }
        else
        {
            num = stoi(numstring);
        }


        if(operations[i][0] == 'I')
        {
            minheap.push(num);
            maxheap.push(num);
            l.push_back(num);

        }
        else if (operations[i][0] == 'D' && !l.empty())
        {

            if(num == 1)
            {
                auto result = find(l.begin(),l.end(), maxheap.top());
                if(result != l.end())
                {
                    l.erase(result);
                    if(minheap.top() == maxheap.top()) minheap.pop();
                    maxheap.pop();
                }
            }
            else // -1
            {
                auto result = find(l.begin(),l.end(), minheap.top());
                if(result != l.end())
                {
                    l.erase(result);

                    if(minheap.top() == maxheap.top()) maxheap.pop();
                    minheap.pop();
                }
            }
        }
    }

    for(auto iter : l)
    {
        answer.push_back(iter);
    }

    if(!answer.empty())
    {
        sort(answer.begin(),answer.end());

        return {answer.back(),answer.front()};
    }
    else
        return {0,0}; 
}