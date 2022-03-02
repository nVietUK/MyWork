#include <bits/stdc++.h>

using namespace std;

// communist variablse
    vector<vector<unsigned>> ta;
    vector<unsigned> co;
    unsigned c, n;

queue<pair<unsigned, unsigned>> wa;
vector<bool> vi;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned m, u, v; 
    cin >> n >> m; 
    ta.clear(); ta.resize(100000+1, {});
    co.clear(); co.resize(100000+1, 0);
    while (m-- && cin >> u >> v)
    {
        ta[u].push_back(v);
        ta[v].push_back(u);
    }

    cin >> m;
    while (m-- && cin >> u >> v >> c)
    {
        wa.push(make_pair(u, v));
        vi.clear(); vi.resize(100000+1, false);
        while (wa.size())
        {
            auto tr = wa.front(); wa.pop();
            co[tr.first] = c; vi[tr.first] = true;
            if (tr.second > 0)
                for (auto& a : ta[tr.first])
                    if (!vi[a])
                        wa.push(make_pair(a, tr.second-1));
        }
    }
    
    for (m = 1; m <= n; m++)
        cout << co[m] << "\n";
}
