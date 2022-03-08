#include <bits/stdc++.h>
#define ONLINE FALSE
#define DEBUG TRUE
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if ((__linux__ || _WIN32) && !ONLINE && !ONLINE_JUDGE)
    freopen(".inp", "r", stdin);
    if (!DEBUG) freopen(".out", "w", stdout);
#endif

    
}