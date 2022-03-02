#include <bits/stdc++.h>

using namespace std;

struct luu
{
    unsigned left;
    bool tanged[1001];
};


// communist variables
    luu ta[1001];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Tặng hoa.inp", "r", stdin);
    freopen("Tặng hoa.out", "w", stdout);
#endif
    
    unsigned n, m, x, y;
    memset(ta, false, sizeof(ta));
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        ta[x][y] = true;
        ta[y][x] = true;
    }
    for (unsigned i = 1; i <= n; i++)
        for (unsigned j = 1; j <= n; j++)
            if (!ta[i][j])
                break;
}