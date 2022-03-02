#include <bits/stdc++.h>

using namespace std;

// communist variables
    bool passed[500001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("blackjack.inp", "r", stdin);
    freopen("blackjack.out", "w", stdout);
#endif
    
    unsigned n, m, i, maxU = -1; cin >> n >> m; int j;
    unsigned inp[n]; for (auto& inp : inp)
        cin >> inp;
    sort(inp, inp + n); bool chk [20001]; memset(chk, false, sizeof(chk));
    for (i = 0; i < n-1; i++)
        for (j = i + 1; j < n; j++)
            chk[inp[i] + inp[j]] = true;
    j = inp[n-1] + inp[n-2];
    for (i = 0; i < n - 2; i++)
    {
        while ((j >= 0) && (!chk[j] || (inp[i] + j > m)))
            j--;
        if (inp[i] + j <= m)
            maxU = min(maxU, m - inp[i] - j);
    }
    cout << m - maxU;
}