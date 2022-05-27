#include <bits/stdc++.h> 

using namespace std;
unsigned Q, N, M, i, res;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> Q; while(Q--) {
        cin >> N >> M;
        res = N*M + N + 1;
        for (i = 2; i < M; i++) 
            res += N*i*2;
        cout << res % (unsigned)(1e9+7) << "\n";
    }
}
