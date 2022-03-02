#include <bits/stdc++.h>
#define limax 1000000 + 5

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("uoc.inp", "r", stdin);
    freopen("uoc.out", "w", stdout);
#endif
    
    int n, a, minT = INT32_MAX, minH = INT32_MAX, maxT = INT32_MAX + 1, maxH = INT32_MAX + 1; 
    cin >> n;
    int tong[n], hieu[n], i = n, temp1I = INT32_MAX;
    while (n-- && cin >> a)
        tong[n] = a;
    n = i; while (n-- && cin >> a)
    {
        hieu[n] = tong[n] - a;
        tong[n] += a;
        minT = min(minT, tong[n]);
        minH = min(minH, hieu[n]);
        maxT = max(maxT, tong[n]);
        maxH = max(maxH, hieu[n]);
    }
    while (i--)
        cout << max(max(maxT-tong[i], tong[i]-minT), max(maxH-hieu[i], hieu[i]-minH)) << " ";
}