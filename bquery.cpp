#include <bits/stdc++.h>
#include <functional>
#include <queue>

using namespace std;
typedef pair<unsigned, unsigned> uu;
char inp; unsigned p[2009][2009], a[2009][2009], N, M;

void init() {
    fill(p[0], p[0]+2009*2009, 0); unsigned ou=0;
    for (unsigned i = 1; i <= N; i++) for (unsigned j = 1; j <= M; j++) {
    priority_queue<uu> q; q.push({i, j});
    while (q.size()) {
        uu cu = q.top(); q.pop();

        if (p[cu.first][cu.second] || !a[cu.first][cu.second] || cu.first > N || cu.first < 1 || cu.second > M || cu.second < 1) continue;
        p[cu.first][cu.second] = ou++;

            q.push({cu.first-1, cu.second});
            q.push({cu.first, cu.second-1});
            q.push({cu.first+1, cu.second});
            q.push({cu.first, cu.second+1});
        }    
    }
}

signed main() { unsigned i, j, Q, x, y;
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N >> M >> Q;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M && cin >> inp; j++)
            a[i][j] = (inp == '1');
    init(); while (Q--) { cin >> x >> y >> N >> M;
        for (i = x; i <= N; i++)
            for (j = y; j <= M; j++)
                if (!p[i][j] && a[i][j]) 

        cout << ou << '\n';
    }
}

