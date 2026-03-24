#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int n;

map<string, int> str2int;
string int2str[1007];

vector<int> g[1007];
int indeg[1007];

set<int> ans[1007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<string> allnames(n);
    for (int i = 0; i < n; i++)
        cin >> allnames[i];
    
    sort(allnames.begin(), allnames.end());

    for (int i = 0; i < n; i++)
    {
        int2str[i] = allnames[i];
        str2int[allnames[i]] = i;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;

        g[str2int[b]].push_back(str2int[a]);
        indeg[str2int[a]]++;
    }

    queue<int> q;
    set<string> family;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
        {
            q.push(i);
            family.insert(int2str[i]);
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

    cout << family.size() << endl;

    for (auto iter : family)
        cout << iter << " ";

    cout << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cout << int2str[i] << " " << ans[i].size() << " ";
        for (auto iter : ans[i])
            cout << int2str[iter] << " ";
        cout << '\n';
    }

    return 0;
}
