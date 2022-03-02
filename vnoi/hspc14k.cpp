#include <bits/stdc++.h>
#define limax 1010

using namespace std;

// communist variables
    int n, m;
    long long   fxy[limax][limax], 
                fx[limax][limax], 
                fy[limax][limax],
                f[limax][limax];

void up(int a, int b, long long v, long long (*in)[limax][limax])
{
    for (int i = a; i <= n; i+= i & -i)
        for (int j = b; j <= m; j += j & -j)
            *in[i][j] += v;
}

long long query(long long (*in)[limax][limax], int a, int b) {
    long long ou = 0;
    for (int i = a; i; i &= i-1)
        for (int j = b; j; j &= j-1)
            ou += *in[i][j];
    return ou;
}

long long query(int x, int y) {
    return  query(x, y, &fxy) * x * y + 
            query(x, y, &fx) * x + 
            query(x, y, &fy) * y + 
            query(x, y, &f);
}

long long query(int a, int b, int x, int y) {
    return  query(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("hspc14k.inp", "r", stdin);
    freopen("hspc14k.out", "w", stdout);
#endif
    
    int q, a, b, x, y;
    long long   k;
    cin >> n >> m >> q;
    while (q-- && cin >> k >> a >> b >> x >> y) {
        if (k == 1) {
            cin >> k;
            up(a,   b,    k, &fxy);
            up(a,   y+1, -k, &fxy);
            up(x+1, b,   -k, &fxy);
            up(x+1, y+1,  k, &fxy);
            long long   v1 = (1-b) * k,
                        v2 = (y-b+1) * k;
            up(a,   b,      v1, &fx);
            up(a,   y+1, v2-v1, &fx);
            up(x+1, b,     -v1, &fx); 
            up(x+1, y+1, v1-v2, &fx);
            long long   v3 = (1-a) * k,
                        v4 = (x-a+1) * k;
            up(  a,   b,    v3, &fy);
            up(x+1,   b, v4-v3, &fy);
            up(  a, y+1,   -v3, &fy);
            up(x+1, y+1, v3-v4, &fy);
            long long   v5 = (a-1) * (b-1) * k,
                        v6 = (1-a) * (y-b+1) * k,
                        v7 = (1-b) * (x-a+1) * k,
                        v8 = (x-a+1) * (y-b+1) * k;
            up(a, b, v5, &f);
            up(a, y+1, v6-v5, &f);
            up(x+1, b, v7-v5, &f);
            up(x+1, y+1, v8+v5-v6-v7, &f);
        }
        else 
            cout << 
    }
}