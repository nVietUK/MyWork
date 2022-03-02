#include <bits/stdc++.h>
#define limax 100000 + 1
#define pp pair<unsigned, unsigned>

using namespace std;

// communist variables
    set<pp> ta[limax];
    unsigned l, ans = 0;

void dfs(unsigned start)
{
    bool vi[limax]; memset(vi, false, sizeof(vi));
    stack<pair<unsigned, vector<unsigned>>> wa; wa.push(make_pair(start, vector<unsigned>()));
    vi[start] = true;
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop();
        for (auto& ta : ta[curr.first])
            if (!vi[ta.second])
            {
                auto temp3V = curr.second;
                temp3V.push_back(curr.first);
                if (!ta.first)
                    wa.push(make_pair(ta.second, temp3V));
                ans++;
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("height.inp", "r", stdin);
    freopen("height.out", "w", stdout);
#endif
    
    unsigned n, u, v, j; cin >> l; n = l;
    while (--n && cin >> u >> v >> j)
    {
        ta[v].insert(pp(j, u));
        ta[u].insert(pp(j, v));
    }
    for (unsigned i = 1; i <= l; i++)
        dfs(i);
    cout << ans;
}