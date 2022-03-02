#include <bits/stdc++.h>

using namespace std;

unsigned giai(string in)
{
    unsigned ou = 0;
    while (in.size())
    { ou += (in[0] - '0') * pow(10,in.size()-1); in.erase(in.begin()); };
    return ou;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned t; cin >> t;
    while (t--)    
    {
        unsigned x, k, ou = 0; string s;
        cin >> x >> k >> s;
        for (unsigned l = 1; l <= k; l++)
            for (unsigned i = 0; i + (l-1) < k; i++)
            if ((s[i] != '0') || (l==1)){
                if (!(giai(s.substr(i, l)) % x))
                    ou++;
            }
        cout << ou << "\n";
    }
}