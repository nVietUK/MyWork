#include <bits/stdc++.h>

using namespace std;

map<unsigned, unsigned long long> ta;

unsigned long long giaithua(unsigned in)
{
    if (ta[in])
        return ta[in];
    else 
    {
        if (in == 1 || !in)
            return ta[in] = 1;
        return ta[in] = in * giaithua(in-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("vnoi.inp", "r", stdin);
    freopen("vnoi.out", "w", stdout);
#endif
    
    unsigned n, ou = 2; 
    for (unsigned n = 0; n <= 100; n++)
    {
        ou = 0;
        for (unsigned i = 0; i <= n; i++)
            if ((giaithua(n)/(giaithua(i) * giaithua(n-i))) % 2)
                ou++;
        cout << ou << "\n";
    }
}