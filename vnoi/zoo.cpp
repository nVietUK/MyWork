#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pp;

unsigned 
    N, M, ou = 1;
int
    row[] = {0, 0, 1, -1},
    col[] = {1, -1, 0, 0};
char
    arr[1000][1000];

bool check(int a, unsigned& b) {
    return a > -1 && a < b;
}

bool bang() {
    bool next = false;
    char chuan = arr[0][0], op = (chuan == 'T') ? 'B' : 'T';
    int x, y;
    queue<pp> q1, q2; q1.push(pp(0, 0));

    while (q1.size()) {
        auto curr = q1.front(); q1.pop();

        for (unsigned i = 0; i < 4; i++) {
            x = curr.first + row[i], y = curr.second + col[i];
            if (check(x, N) && check(y, M)) {
                if (arr[x][y] == chuan)
                    q1.push(pp(x, y));
                else 
                if (arr[x][y] != '*' && arr[x][y] != '!')
                    q2.push(pp(x, y));
            }
        } 

        arr[curr.first][curr.second] = '!';
        if (q1.empty() && q2.size()) {
            swap(q1, q2);
            swap(chuan, op);
            ou++;
        }
    }

    return next;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> M;
    for (unsigned i = 0; i < N; i++)
        for (unsigned j = 0; j < M; j++)
            cin >> arr[i][j];
    
    bang();

    cout << ou;

    return 0;
}