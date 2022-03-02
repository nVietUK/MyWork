#include <bits/stdc++.h>

using namespace std;

// communist variables
    vector<unsigned> prime;

int chay(unsigned& x, unsigned& y)
{
    for (unsigned i = 3; i <= x; i += 2)
    {
        unsigned ck = 0;
        for (auto& temp2 : prime)
            ck += bool(i % temp2);
        if (ck == prime.size()) prime.push_back(i);
    }
    for (unsigned i = x + (1 - (x % 2)); i <= y; i += 2)
    {
        unsigned ck = 0; bool runned = true;
        for (auto& temp2 : prime)
            if (i >= temp2)
                if (!(i % temp2))
                {
                    runned = false;
                    break;
                }
        if (runned) return i;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Bàn cờ.inp", "r", stdin);
    freopen("Bàn cờ.out", "w", stdout);
#endif
    
    unsigned n, m; cin >> n >> m;
    cout << chay(n, m);
}