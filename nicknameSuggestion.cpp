#include <bits/stdc++.h>

using namespace std;
struct node {
    node* next[26];
} a;

void build(unsigned id, string s, node *a) {
    if (id == s.size()) return;
    if (a->next[s[id]-'a'] == NULL)
        a->next[s[id]-'a'] = new node;
    build(id+1, s, a->next[s[id]-'a']);
}

signed main() { unsigned N;
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> N; string s, q[1000009];
    for (unsigned i = 1; i <= N && cin >> s; i++) {
        build(0, s, &a); q[i] = s;
    }
}
