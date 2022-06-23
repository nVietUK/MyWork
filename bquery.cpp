#include <bits/stdc++.h>

using namespace std;

char inp; bool p[2009][2009], a[2009][2009];

signed main() { unsigned i, j, N, M, Q, x, y;
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M >> Q;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M && cin >> inp; j++)
            a[i][j] = (inp == '1');
    while (Q--) { cin >> x >> y >> N >> M;
        fill(p[0], p[0]+2009*2009, false);
        for (i = x; x <= N; i++)
            for (j = y; y <= M; y++)
                if (!p[i][j] && a[i][j])
    }
}

