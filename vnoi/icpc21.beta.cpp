#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    double e, w, s; cin >> e >> w >> s;

    double ou = e/(s/w);
    cout << setprecision(6) << fixed;
    cout << ou << "\n";
}