#include <bits/stdc++.h> 

using namespace std;
const unsigned inf = 1e9 + 7; 
unsigned N, M, *a, i, op, l, r, k;
multiset<unsigned> *st;

void build(unsigned id, unsigned l, unsigned r) {
    if (l == r) { st[id].insert(a[l]); return; }

    unsigned mid = l+r >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = st[2*id+1]; for (auto x : st[2*id]) st[id].insert(x);
}

void update(unsigned id, unsigned l, unsigned r, unsigned i, unsigned old, unsigned val) {
    if (i < l || r < i) return;
    if (l == r) { st[id].clear(); st[id].insert(val); return; };

    unsigned mid = l+r >> 1;
    update(2*id, l, mid, i, old, val); update(2*id+1, mid+1, r, i, old, val);
    st[id].erase(st[id].find(old)); st[id].insert(val);
}

unsigned get(unsigned id, unsigned l, unsigned r, unsigned u, unsigned v, unsigned k) {
    if (v < l || r < u) return inf;
    if (l <= u && v <= r) {
       auto it = st[id].lower_bound(k);
       return (it == st[id].end()) ? inf : *it;
    }

    unsigned mid = l+r >> 1;
    return min(get(2*id, l, mid, u, v, k), get(2*id+1, mid+1, r, u, v, k));
}

signed main() {
    cin >> N >> M; a = new unsigned[N+1];
    st = new multiset<unsigned>[N*4];
    for (i = 1; i <= N && cin >> a[i]; i++);
    build(1, 1, N);

    while (M--) {
        cin >> op;
        if (op == 1) { cin >> l >> k; update(1, 1, N, l, a[l], k); a[l] = k; }
        else {
            cin >> l >> r >> k;
            cout << ((op = get(1, 1, N, l, r, k) == inf) ? -1 : op) << "\n";
        }
    }
}
