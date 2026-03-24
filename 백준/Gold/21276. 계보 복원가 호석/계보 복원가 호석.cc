#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int n;

map<string, int> STOI;
map<int, string> IOST;

vector<int> g[1007];
int indeg[1007];

vector<int> ans[1007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input; 
        cin >> input;
        
        STOI[input] = i;
    }

    int ind = 0;
    for (auto it = STOI.begin(); it != STOI.end(); it++)
    {
        (*it).second = ind;
        IOST[ind] = (*it).first;
        ind++;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string a, b;
        cin >> a >> b;

        g[STOI[b]].push_back(STOI[a]);
        indeg[STOI[a]]++;
    }

    
    int cnt = 0;

    queue<int> q;
    set<string> backup;

    for (int i = 0; i < n; i++)
        if (indeg[i] == 0)
        {
            q.push(i);
            backup.insert(IOST[i]);
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
                ans[cur].push_back(iter);
                q.push(iter);
            }
        }
    }

    cout << backup.size() << endl;

    for (auto iter : backup)
        cout << iter << " ";

    cout << endl;
    
    for(auto name : STOI)
    {
        cout << name.first << " " << ans[name.second].size() << " ";
        for (auto iter : ans[name.second])
            cout << IOST[iter] << " ";
        cout << '\n';
    }


    return 0;
}
