#include <bits/stdc++.h>
using namespace std;

const int N = 1E7 + 5;

int n, x, a[N];
long long ans = 0;

void fastscan(int &number) 
{
    bool negative = false; 
    register int c;
    number = 0;
    c = getchar(); 
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    }
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48;
    if (negative) 
        number *= -1; 
}

int main() {
    freopen("BONPAIR.inp", "r", stdin);
    freopen("BONPAIR.out", "w", stdout);
    fastscan(n); fastscan(x);
    for (int i = 1; i <= n; i++) {
        fastscan(a[i]);
    }
    for (int i = 1, pt = n; i <= n && a[i] <= x; i++) {
        for (; pt > 0 && a[pt] + a[i] > x; pt--);
        ans += min(pt, i - 1);
    }
    cout << ans;
}
