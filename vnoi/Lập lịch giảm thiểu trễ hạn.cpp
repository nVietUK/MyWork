#include <bits/stdc++.h>
#define ppp pair<pair<unsigned, unsigned>, unsigned> 

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Lập lịch giảm thiểu trễ hạn.inp", "r", stdin);
    freopen("Lập lịch giảm thiểu trễ hạn.out", "w", stdout);
#endif
    
    unsigned n; cin >> n;

    ppp ta[n]; bool ma[n]; memset(ma, true, sizeof(ma));
    for(int i=0;i<n;++i) cin >> ta[i].first.second;
    for(int i=0;i<n;++i) cin >> ta[i].first.first;
    for(int i=0;i<n;++i) ta[i].second = i+1;
    sort(ta, ta + n);

    priority_queue<pair<unsigned, int>> wa; int total = 0;
    for (unsigned i = 0; i < n; i++)
    {
        total += ta[i].first.second;
        wa.push( make_pair( ta[i].first.second, i));
        if(total>ta[i].first.first) {
            pair<int,int> p = wa.top(); wa.pop();
            total -= p.first;
            ma[p.second] = false;
        }
    }

    unsigned ou = 0;
    for (unsigned i = 0; i < n; i++)
        if (!ma[i])
            ou++;
    cout << ou << "\n";
    for (unsigned i = 0; i < n; i++) 
        if (ma[i])
            cout << ta[i].second << " ";
    for (unsigned i = 0; i < n; i++)
        if (!ma[i])
            cout << ta[i].second << " ";
}