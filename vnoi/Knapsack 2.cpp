#include <bits/stdc++.h>

using namespace std;

const int Limit = 1e5+1;

template<class T> bool ckmin(T& a, const T& b) {
    return a > b ? a = b, 1 : 0;
}

long long dp[Limit];
vector<unsigned> w(100), v(100);

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Knapsack 2.inp", "r", stdin);
    freopen("Knapsack 2.out", "w", stdout);
#endif

    unsigned N, W; cin >> N >> W;
    for(int i = 0; i < N; ++i) cin >> w[i] >> v[i];
    for(int i = 0; i < Limit; ++i) dp[i] = 1e18;

    dp[0] = 0;

    for(int i = 0; i < N; ++i) 
        for(int j = Limit - 1; j >= 0; j--) 
            if(dp[j] + w[i] <= W) 
                ckmin(dp[j + v[i]], dp[j] + w[i]);

    for(int i = Limit - 1; i >= 0; i--) 
        if(dp[i] != 1e18) 
        {   cout << i << "\n";
            break;
        }
}