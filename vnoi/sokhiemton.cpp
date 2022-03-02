#include <bits/stdc++.h>

using namespace std;

struct sokhienton
{
    unsigned value, prime, index;
};

bool mycomp(sokhienton& a, sokhienton& b)
{
    return (a.value < b.value);
}

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("sokhiemton.inp", "r", stdin);
    freopen("sokhiemton.out", "w", stdout);
#endif
    
    unsigned n, m; cin >> n >> m;
    sokhienton ta[n];
    for (auto& ta : ta)
    {
        cin >> ta.prime;
        ta.value = ta.prime;
        ta.index = 0;
    }
    vector<long long> luu; auto ou = m-1;
    while (m--)
    {
        auto temp2sokhiemton = min_element(ta, ta + n, mycomp);
        luu.push_back(temp2sokhiemton->value);
        for (auto& ta : ta)
            if (ta.value == luu.back())
                ta.value = ta.prime * luu[ta.index++];
    }
    cout << luu[ou];
}