#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("BTND.inp", "r", stdin);
    freopen("BTND.out", "w", stdout);
#endif
    
    unsigned n; cin >> n; string s; getline(cin, s);
    while (n-- && getline(cin, s))
    {
        int ou = 0;
        while (s.size())
        {
            auto c = *(s.end()-1);
            s.pop_back();

            if (c == ')')
                ou++;
            else 
            if (c == '(')
                ou--;
            if (ou < 0)
            {
                cout << 0 << "\n"; ou = 1;
                break;
            }
        }
        if (!ou) cout << 1 << "\n";
    }
}