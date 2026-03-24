#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int n;

set<string> names;
map<string, vector<string>> g;
map<string, int> indeg;
map<string, set<string>> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input; 
        cin >> input;
        
        names.insert(input);
        indeg[input] = 0;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;

        g[b].push_back(a);
        indeg[a]++;
    }

    queue<string> q;
    set<string> numberoffamily;

    for(auto iter : names)
        if (indeg[iter] == 0)
        {
            q.push(iter);
            numberoffamily.insert(iter);
        }
       
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto iter : g[cur])
        {
            indeg[iter]--;

            if (indeg[iter] == 0)
            {
                ans[cur].insert(iter);
                q.push(iter);
            }
        }
    }

    cout << numberoffamily.size() << endl;

    for (auto iter : numberoffamily)
        cout << iter << " ";

    cout << endl;
    
    for(auto name : names)
    {
        cout << name << " " << ans[name].size() << " ";
        for (auto child : ans[name])
            cout << child << " ";
        cout << '\n';
    }


    return 0;
}
