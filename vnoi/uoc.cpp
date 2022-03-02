#include <bits/stdc++.h>

using namespace std;

// communist variables
    short memo[52][52], pos[52];

short ham(short a, short b)
{
    if (b - a == 1)
        return 0;
    if(memo[a][b] != -1) 
        return memo[a][b];
    
    memo[a][b] = INT16_MAX;
    for(short i = a + 1; i < b; i++)
        memo[a][b] = min(memo[a][b], (short)(ham(a, i) + ham(i, b)));
    return memo[a][b] += pos[b] - pos[a];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    pos[0] = 0; short L, n; while(cin >> L && L)
        {
            cin >> n;
            
            for (auto& memo : memo[0])
                memo = -1;
            for(short i = 1; i <= n && cin >> pos[i]; i++) 
                for (auto& memo : memo[i])
                    memo = -1;
            pos[++n] = L;
            
            cout << ham(0,n) << "\n";
        }
}
