#include <bits/stdc++.h>
#define ham(in) ((in) * (in-1))/2

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("xoaday.inp", "r", stdin);
    freopen("xoaday.out", "w", stdout);
#endif
    
    unsigned t, in; cin >> t;
    while (t--)
    {
        cin >> in;
        cout << ham(in) + 1 << "\n";
    }
}