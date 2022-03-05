#include <bits/stdc++.h>
#define ONLINE FALSE

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned> uu;

template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {}

    T* begin() const noexcept { return begin_; }
    T* end() const noexcept { return end_; }

    T* begin_;
    T* end_;
};

map<string, string> tagmap;

void create(unsigned& n, string pretag) {
    if (!n) return;

    string line = "", tag, attr, value;
    cin >> line;

    unsigned i = 1;
    if (line[i] == '/') {
        while (line[i]!='>'); i++;
        tag = (pretag.size() > (i-2)) ? pretag.substr(0, pretag.size()-i+1) : "";
    }
    else {
        while ((line[i] != ' ') && (line[i] != '>')) i++;
        tag = line.substr(1, i-1);
        if (pretag != "") tag = pretag + "." + tag;

        unsigned j; while (line[i] != '>') {
            j = ++i; while (line[i] != ' ') i++;
            attr = line.substr(j, i-j);

            while (line[i] != '\"') i++;
            j = ++i; 
            while (line[i] != '\"') i++;
            value = line.substr(j, i-j);
            i++;

            tagmap[tag+"~"+attr] = value;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if ((__linux__ || _WIN32) && !ONLINE)
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    unsigned n, q; cin >> n >> q;
    create(n, "");

    string attr, value;
    while (q--) {
        cin >> attr; value = tagmap[attr];
        if (value == "") value = "Not Found!";
        cout << value << "\n";
    }
}