#include <cstdio>
#include <ios>
#include <iostream>

using namespace std;

void solve() {
    long long a, b; scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    if (a*2 > b) 
}

signed main() {
    unsigned t; scanf("%u", &t); while(t--) solve();
}
