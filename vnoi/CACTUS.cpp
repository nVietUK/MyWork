#include <bits/stdc++.h>

using namespace std;

// communist variables
    vector<vector<bool>> ta;
    vector<unsigned> vi;
    unsigned n, m, ou = 0;

unsigned k = 0; stack<unsigned> de;
void dfs(unsigned root)
{
    vi[root] = ++k;
    de.push(root);
    for (unsigned tp = 1; tp <= n; tp++)
        if (ta[tp][root])
        {
            ta[tp][root] = ta[root][tp] = false;
            if (vi[tp] == n+1)
                dfs(tp);
            else 
                ou = max(ou, vi[root] - vi[tp] + 1);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("cactus.inp", "r", stdin);
    freopen("cactus.out", "w", stdout);
#endif
    
    unsigned t; cin >> t; while (t--)
    {
        unsigned u, v;
        cin >> n >> m;

        ta.resize(n+1); for (auto& tp : ta) tp.resize(n+1, false);
        vi.resize(n+1, n+1);

        while (m--)
        {
            cin >> u >> v;
            ta[u][v] = ta[v][u] = true;
        }

        ou = 0; for (u = 1; u <= n; u++)
            if (vi[u] == n+1)
                dfs(u);
        cout << ou << "\n";
    }
}