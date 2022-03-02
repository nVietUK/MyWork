#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("sumpow.inp", "r", stdin);
    freopen("sumpow.out", "w", stdout);
#endif
    
    unsigned n; cin >> n;
    stack<unsigned> ou;
    while (n)
    {
        unsigned s = 0;
        while (pow(2, s) <= n) s++;
        ou.push(pow(2, s-1));
        n -= pow(2, s-1);
    }
    while (ou.size())
    { cout << ou.top() << " "; ou.pop(); }
}