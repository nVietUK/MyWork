#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

unsigned n;
ull d, dem = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);

    cin >> n >> d; 
    unsigned 
        *a = new unsigned[n+5], 
        *c = new unsigned[n+5], 
        chan = 2, le = 1;
    cin >> a[1]; dem = (a[1] <= d);

    for (unsigned i = 2; i < n+2; i++) {
        if (i <= n) {
            cin >> a[i];
            c[i+1] = (c[i-2])+(a[i])*(a[i-1]);
        }
        if (i > 2) {
            unsigned& curr = (i % 2) ? le : chan;
            while ((c[i] - c[curr] > d) && (curr < i))
                curr += 2;
            dem += (i-curr) / 2;
            unsigned j = curr;
            while ((c[i]-c[j]+a[i] > d) && (j < i)) j += 2;
            dem += (i-j) / 2;
        }
        dem += (a[i] <= d);
    }
    cout << dem;
}