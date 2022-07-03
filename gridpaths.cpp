#include <stdio.h>

unsigned p[48];
bool onp[9][9];

int tryP(int idx, int cR, int cC) {
    if ((onp[cR][cC-1] && on
}

signed main() {
    char s[48]; scanf("%s", s);

    for (unsigned i = 0; i < 48; i++) {
        char c = s[i];

        if (c == 'U') p[i]=0;
        else if (c == 'R') p[i]=1;
        else if (c == 'D') p[i]=2;
        else if (c == 'L') p[i]=3;
        else p[i]=4;
    }

    fill(onp[0], onp[0]+81, true);
    for (unsigned i = 1; i <= 7; i++) for (unsigned j = 1; j <= 7; j++)
        onp[i][j] = false;

    int idx, sR, sC, ans = tryP(idx, sR, sC);
}
