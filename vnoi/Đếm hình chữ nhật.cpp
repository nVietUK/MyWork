#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Đếm hình chữ nhật.inp", "r", stdin);
    freopen("Đếm hình chữ nhật.out", "w", stdout);
#endif
    
    unsigned n, m; cin >> n >> m; unsigned long long ou = 0; long long f[n][m];
    memset(f, 0, sizeof(f));
    for (unsigned i = 0; i < n; i++)
    {
        bool ta[m]; for (unsigned j = 0; j < m; j++) cin >> ta[j];
        for (unsigned j = 0; j < m-1; j++)
            if (ta[j])
                for (unsigned z = j+1; z < m; z++)
                    if (ta[z])
                    {
                        ou += f[j][z];
                        ++f[j][z];
                    }
    }
    cout << ou;
}