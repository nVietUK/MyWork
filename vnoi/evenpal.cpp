#include <bits/stdc++.h>

using namespace std;

// communist variables 
    string s;

string chay()
{
    unsigned i = 2, z; 
    while (s.size())
    {
        if (s[0] != s[1]) s.erase(s.begin());
        else return "YES";
    }
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned n; cin >> n;
    while (n--)    
    {
        cin >> s;
        cout << chay() << "\n";
    }
}