#include <bits/stdc++.h>
#include <pthread.h>
#define limax 100000 + 1
#define pp pair<unsigned long long, unsigned>

using namespace std;

// communist variables
    vector<pp> diem[limax];
    unsigned long long ou[limax];
    unsigned n; bool hang[limax], rb[limax];

void bfs(unsigned pos)
{
    bool vi[limax]; memset(vi, false, sizeof(vi));
    priority_queue<pp, vector<pp>, greater<pp>> wa; wa.push({0, pos});
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop(); vi[curr.second] = true;
        for (auto& temp2 : diem[curr.second])
            if (!hang[temp2.second])
            {
                if (!vi[temp2.second])
                {
                    wa.push({curr.first + temp2.first, temp2.second}); 
                }
            }
            else 
                ou[pos] = min(ou[pos], curr.first + temp2.first + ou[temp2.second]);
    }
    hang[pos] = true; // xóa chỗ này là test 4 sai nhưng nó ra output nhỏ hơn ở vài đỉnh 
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("rbpath.inp", "r", stdin);
    freopen("rbpath.out", "w", stdout);
#endif
    memset(diem, {}, sizeof(diem));
    memset(ou, -1, sizeof(ou));
    memset(hang, false, sizeof(hang));
    memset(rb, true, sizeof(rb));

    // read input
    unsigned m, u, v, l;
    cin >> n >> m;
    while (m-- && cin >> u >> v >> l)
    {
        diem[u].push_back(pp(l, v)); 
        diem[v].push_back(pp(l, u));       
    }
    cin >> m; thread myThread[limax];
    for (v = 0; v < m && cin >> u; v++)
    {
        hang[u] = true; ou[u] = 0; rb[u] = false;
    }
    for (v = 1; v <= n; v++)
        if (!hang[v])
            myThread[v] = thread(bfs, v);
    for (v = 1; v <= n; v++)
        if (rb[v])
            myThread[v].join();
    for (v = 1; v <= n; v++)
        cout << ou[v] << "\n";
}