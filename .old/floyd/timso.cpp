#include <bits/stdc++.h>

using namespace std;

typedef pair<unsigned, unsigned> pp;

// communist variables
    set<pp> ta[101];
    unsigned t[105][105], d[105][105];
    int n, m, k;

void dijkstra(int s) 
{
    priority_queue<pp> q; q.push(pp(0, s));
    memset(d[s], -1, sizeof(d[s]));
    d[s][s] = 0; t[s][s] = s;
    while(q.size())
    {
        int du = q.top().first, u = q.top().second; q.pop();
        if (du > d[s][u]) 
            continue;
        for (auto& it : ta[u])
        {
            int v = it.second, l = it.first;
            if (d[s][v] > du + l) 
            {
                d[s][v] = du + l; t[s][v] = u;
                q.push(pp(d[s][v], v));
            }
        }
    }
}

int main() 
{
    freopen("timso.inp", "r", stdin);
    freopen("timso.out", "w", stdout);
    cin >> n >> m >> k;
    while(m--) {
        int u, v, l; cin >> u >> v >> l;
        ta[u].insert(pp(l, v));
        ta[v].insert(pp(l, u));
    }
    for(int i = 1; i <= n; ++i ) 
        dijkstra(i);
    while(k--) 
    {
        int q, u, v; cin >> q >> u >> v;
        if(q) 
        {
            stack<int> st; int x = v; st.push(x);
            do 
            {
                x = t[u][x];
                st.push(x);
            } 
            while (x != u);
            cout << st.size();
            while (!st.empty()) 
            {
                cout << " " << st.top();
                st.pop();
            }
            cout << "\n";
        } 
        else 
            cout << d[u][v] << "\n";
    }
}
