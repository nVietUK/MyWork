#include <bits/stdc++.h> 

using namespace std;
unsigned long long Q, N, M, i, res;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> Q; while(Q--) {
        cin >> N >> M;
        cout << (1+N*(M*M-1))%(1000000000+7) << "\n";
    }
}
