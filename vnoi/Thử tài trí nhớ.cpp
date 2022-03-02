#include <bits/stdc++.h>

using namespace std;

// commmunist variables;
    vector<unsigned> ta;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif

    unsigned n, m, z;
    cin >> n >> m; ta.resize(n);
    while (n--)
        cin >> ta[n];
    while (m-- && (cin >> n))
        if (n == 1)
        {
            cin >> n >> z;
            reverse(ta.end()-z, ta.end()-n+1);
        }
        else {
            cin >> z;
            cout << *(ta.end()-z) << "\n";
        }
}