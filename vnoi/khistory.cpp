#include <bits/stdc++.h>
#define limax 10000000

using namespace std;

// communist variables
    set<unsigned> ta[limax];
    bool vi[limax];

void dfs(unsigned start)
{
    stack<unsigned> wa; wa.push(start); vi[start] = true;
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop();
        for (auto& temp2 : ta[curr])
            if (!vi[temp2])
            {
                wa.push(temp2);
                vi[temp2] = true;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("khistory.inp", "r", stdin);
    freopen("khistory.out", "w", stdout);
#endif
    
    unsigned n, m, u, v;
    cin >> n >> m;

    while (m-- && cin >> u >> v)
    {
        ta[u].insert(v);
        ta[v].insert(u);
    }

    memset(vi, false, sizeof(vi));
    u = 0; for (v = 1; v <= n; v++)
        if (!vi[v])
        {
            dfs(v);
            u++;
        }
    cout << u;
}