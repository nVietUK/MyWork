#include <bits/stdc++.h> 

using namespace std;

unsigned *parr, N, i, q, x, y;
void init() {
    parr = new unsigned[N+2];
    for (i = 0; i < N+2; i++) 
        parr[i] = i;
}

unsigned getparr(const unsigned &p) { return (p != parr[p]) ? getparr(p) : p; }

void union_set(unsigned& u, unsigned& v) { 
    u = getparr(u), v = getparr(v);
    if (u == N+1 || v == N+1) {
        cout << -1 << '\n';
        return;
    }
    parr[v] = u, parr[u] = N;
}

void noinu_set(unsigned& u, unsigned& v) {
    u = getparr(u), v = getparr(v);
    if (u == N || v == N) {
        cout << -1 << '\n';
        return;
    }
    parr[v] = u, parr[u] = N+1;
}

void same_ali(unsigned &u, unsigned &v) { u = getparr(u); cout << ((u == getparr(v)) ? 1 : 0) << '\n'; return; }

void hate_eot(unsigned &u, unsigned &v) { u = getparr(u); cout << ((u != getparr(v)) ? 1 : 0) << '\n'; return; }

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; init(); while (cin >> q >> x >> y && q) {
        if (q == 1) union_set(x, y);
        else if (q == 2) noinu_set(x, y);
        else if (q == 3) same_ali(x, y);
        else if (q == 4) hate_eot(x, y);
    }
}
