#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> people, int limit) {
    int answer = 0;

    int l = 0;
    int r = people.size()-1;

    sort(people.begin(),people.end());


    while(l <= r)
    {
        if(people[l] + people[r] > limit)
        {
            r--;
            answer++;
        }
        else
        {
            answer++;
            l++;
            r--;
        }
    }

    return answer;
}
