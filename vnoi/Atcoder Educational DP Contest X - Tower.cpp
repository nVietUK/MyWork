#include <bits/stdc++.h>

using namespace std;

struct vnoi
{
    unsigned w, s, v;
};


// communist variables
    vector<vnoi> ta;
    long long s = 0;
    unsigned n;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    cin >> n; ta.resize(n);
    while (n--)
    { cin >> ta[n].w >> ta[n].s >> ta[n].v; s += ta[n].s; }
    n = ta.size();
    cout << chay();
}