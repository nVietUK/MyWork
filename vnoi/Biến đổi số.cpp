#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned t; cin >> t;
    while (t--)    
    {
        string s; cin >> s;
        string v = s; reverse(s.begin(), s.end());
        if (s.compare(v) < 0)
            cout << s << "\n";
        else 
        {
            *(v.end()-1)--;
            cout << v << "\n";
        }
    }
}