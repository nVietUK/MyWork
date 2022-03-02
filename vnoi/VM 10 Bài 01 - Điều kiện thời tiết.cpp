#include <bits/stdc++.h>
#define limax 100 + 1

using namespace std;

// communist variables
    vector<unsigned> ta[limax];    
    pair<unsigned, unsigned> luu[limax];

unsigned thu = 0, pass[limax]; 
void chay(unsigned pos, unsigned tranh)
{
    luu[pos].first = limax; luu[pos].second = ++thu;
    pass[pos] = 1;
    for (auto& tempFo : ta[pos])
        if (tempFo != tranh)
        {
            if (luu[tempFo].second == 0)
            {
                chay(tempFo, pos);
                luu[pos].first = min(luu[pos].first, luu[tempFo].first);
                pass[pos] += pass[tempFo];
            }
            else 
                luu[pos].first = min(luu[pos].first, luu[tempFo].second);
        }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen(" VM 10 Bài 01 - Điều kiện thời tiết.inp", "r", stdin);
    freopen(" VM 10 Bài 01 - Điều kiện thời tiết.out", "w", stdout);
#endif
    
    unsigned n, m, x, y;  
    cin >> n >> m;

    for (unsigned i = 0; i < m; i++)
    {
        cin >> x >> y;
        ta[x].push_back(y); ta[y].push_back(x);
    }
    chay(1, 0);
    unsigned ou = 0; for (unsigned i = 2; i <= n; i++)
        if (luu[i].first >= luu[i].second)
            ou += pass[i] * (n - pass[i]);
    cout << ou;
}