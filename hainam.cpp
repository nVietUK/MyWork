#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    freopen("Hainam.inp", "r", stdin);
    freopen("Hainam.out", "w", stdout);

    int n, m, r, k, res = 0;
    cin >> n >> m >> r >> k;
    char a[n+5][m+5];
    int p[n+5][m+5];
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; if (a[i][j] == 'S') p[i][j]++;
            p[i][j] += -p[i-1][j-1] + p[i][j-1] + p[i-1][j];
        }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            if(a[i][j] == 'M') {
                int iv = max(i-r, 1), jv = max(j-r, 1), ui = min(i+r, n), uj = min(j+r, m), 
                sl = p[ui][uj] - p[iv-1][uj] - p[ui][jv-1] + p[iv-1][jv-1];
                res += sl >= k;
            }
    cout << res;
}