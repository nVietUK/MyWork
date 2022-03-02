#include <bits/stdc++.h>

using namespace std;

// communist variables
    bool allow;

bool ck(string in)
{
    for (auto& a : in)
        if (!isdigit(a))
            return false;
    while (in.size() < 3) in.insert(in.begin(), '0');
    if (in >= "018")
        allow = true;
    else 
        allow = false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned n, ou = 0; cin >> n;
    map<string, bool> ta; 
    ta["ABSINTH"] = true;
    ta["TEQUILA"] = true;
    ta["VODKA"] = true;
    ta["WHISKEY"] = true;
    ta["WINE"] = true;
    ta["BEER"] = true;
    ta["BRANDY"] = true;
    ta["CHAMPAGNE"] = true;
    ta["GIN"] = true;
    ta["RUM"] = true;
    ta["SAKE"] = true;
    string s;
    while (n--)
    {
        cin >> s;
        if (ck(s)) { if (!allow) ou++; }
        else       { if (ta[s]) ou++;}
    }
    cout << ou;
}