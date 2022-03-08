#include <bits/stdc++.h>
#define ONLINE false
#define DEBUG true
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
    freopen("test.inp", "r", stdin);
    if (!DEBUG) freopen("test.out", "w", stdout);
#endif

    short a[3], b[3];
    for (auto&& e : wrapped_array<short>a)
        cin >> e;
    for (auto&& e : wrapped_array(a))
        cin >> e;

    short ca=0, cb=0;
    for (short i = 0; i < 3; i++) 
        if (a[i] > b[i])
            ca++;
        else 
        if (a[i] < b[i])
            cb++;
    cout << ca << " " << cb;        
}