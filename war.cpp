#include <bits/stdc++.h> 

using namespace std;

unsigned *parr, N, i, q, x, y; 
set<unsigned> *hate;
void init() {
    parr = new unsigned[N], hate = new set<unsigned>[N-1];
    for (i = 0; i < N; i++) 
        parr[i] = i;
}

unsigned getparr(unsigned p) { return (p != parr[p]) ? getparr(parr[p]) : p; }

void union_set(unsigned& u, unsigned& v) { 
    u = getparr(u), v = getparr(v);
    if (u > v) swap(u, v);
    if (hate[u].find(v) != hate[u].end()) {
        cout << -1 << '\n';
        return;
    }
    for (unsigned e : hate[v]) hate[u].insert(e); 
    parr[v] = u; 
}

void noinu_set(unsigned& u, unsigned& v) {
    u = getparr(u), v = getparr(v);
    if (u > v) swap(u, v);
    if (u == v) {
        cout << -1 << '\n';
        return;
    }
    hate[u].insert(v);
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
