#include <bits/stdc++.h>
#define limax 255

using namespace std;

const int BASE = 1000000000, MAX_DIGIT = 30, LOG_BASE = 9;
struct bigint 
{
    int d[MAX_DIGIT], n;

    void operator = (const int &x) {
        memset(d, 0, sizeof d); n = 0;
        for(int t = x; t != 0; t /= BASE)
            d[n++] = t % BASE;
    }

    bool operator < (const bigint &a) const {
        if(n < a.n) return true;
        if(n > a.n) return false;
        for(int i = n-1; i >= 0; --i)
            if(d[i] < a.d[i]) return true;
            else if(d[i] > a.d[i]) return false;
        return false;
    }

    void operator += (const bigint &a) {
        int rem = 0; n = max(n, a.n);
        for(int i = 0; i < n; ++i) {
            int p = d[i] + a.d[i] + rem;
            if(p >= BASE) d[i] = p - BASE, rem = 1;
            else d[i] = p, rem = 0;
        }
        if(rem) d[n++] = rem;
    }

    void operator -= (const bigint &a) {
        int rem = 0;
        for(int i = 0; i < n; ++i) {
            int p = d[i] - a.d[i] - rem;
            if(p < 0) d[i] = p + BASE, rem = 1;
            else d[i] = p, rem = 0;
        }
        while(n > 0 && d[n-1] == 0) --n;
    }

    void scan() {
        string s; cin >> s; int l = s.size();
        reverse(s.begin(), s.end());
        memset(d, 0, sizeof d);
        for(n = 0; LOG_BASE * n < l; ++n)
            for(int j = min(LOG_BASE * (n+1), l) - 1; j >= LOG_BASE * n; --j)
                d[n] = d[n] * 10 + s[j] - '0';
    }
};

// communist variables
    bigint f[limax][limax * 2];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("fibbox.inp", "r", stdin);
    freopen("fibbox.out", "w", stdout);
#endif
    
    unsigned n; bigint q;
    cin >> n; q.scan();

    for (unsigned i = 2* n; i >= n; i--)    
        f[n][i] = 1;
    for (unsigned i = n-1; i >= 1; i--)
        for (unsigned j = 2*i; j >= i; j--)
            for (unsigned z = 2*(i+1); z > j; z--)
                f[i][j] += f[i+1][z];
    for (unsigned i = 1, j = 1; i <= n; i++, j++)
    {
        while(f[i][j] < q)
            q -= f[i][j], j++;
        if (i > 1) cout << " ";
        cout << j;
    }
}