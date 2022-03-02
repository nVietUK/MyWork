#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    string c1, c2; cin >> c1 >> c2;
    if (c1.size()  > c2.size()) swap(c1, c2);
    for (unsigned l = c1.size(); l; --l)    
        for (int p = c1.size() - l; p != -1; p--)
        {
            string tp = c1.substr(p, l);
            do 
            {
                string re = tp; reverse(re.begin(), re.end());
                if (c2.find(tp) != string::npos || c2.find(re) != string::npos)
                { cout << l; return 0; }
            }
            while (next_permutation(tp.begin(), tp.end()));
        }
}