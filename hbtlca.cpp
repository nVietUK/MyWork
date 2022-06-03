#include <bits/stdc++.h>

using namespace std;
vector<unsigned> *g;
unsigned n, v, u, *h, **up, i, m, root=1;
char c;

void dfs(unsigned u) {
    for (unsigned &v : g[u]) {
        if (v == g[u][0]) continue;

        h[v] = h[u]+1, up[v][0] = u;
        for (i = 1; i < 17; i++)
            up[v][i] = up[up[v][i-1]][i-1];
        dfs(v);
    }
}

unsigned lca(unsigned u, unsigned v) {
    if (h[u] != h[v]) {
        if (h[u] < h[v]) swap(u, v);

        n = h[u] - h[v];
        for (i = 0; (1 << i) <= n; i++)
            if (n >> i & 1)
                u = up[u][i];
    }
    if (u == v) return u;

    n = __lg(h[u]);
    for (i = n; i >= 0; i--)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    while (cin >> n, n) {
        g = new vector<unsigned>[n+10]; h = new unsigned[n+10]; up = new unsigned*[n+10]; up[0] = new unsigned[17];
        for (i = 1; i <= n; i++) { g[i].clear(); up[i] = new unsigned[17]; }
        for (i = 1; i < n; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        
        cin >> m; while (m--) {
            cin >> c;
            if (c == '!') cin >> root;
            else {
                cin >> u >> v;
                cout << (lca(u, v) ^ lca(u, root) ^ lca(v, root)) << '\n';
            }
        }
    }
}
