#include <bits/stdc++.h>

typedef unsigned long long ull;

template <typename T>
    struct wrapped_array {
        wrapped_array(T* first, T* last)
            : begin_ {first}, end_ {last} {}
        wrapped_array(T* first, std::ptrdiff_t size)
            : wrapped_array {first, first + size} {}

        T* begin() const noexcept { return begin_; }
        T* end() const noexcept { return end_; }

        T* begin_;
        T* end_;
    };

using namespace std;

unsigned n, *arr1, *arr2, in, l, r;
ull d;

void build(unsigned *in) {
    for (unsigned i = n-1; i >= n>>1; i--) 
        in[i] = in[i<<1] * in[i<<1|1];
}

unsigned run(unsigned be, unsigned en, const unsigned *in, bool **vi, unsigned **dp) {
    if (vi[be][en]) 
        return dp[be][en];
    vi[be][en] = true;

    if (be == en)
        return dp[be][en] = in[be];

    for (unsigned i = be+1; i < en; i++)
        return 1;
}

unsigned get(const unsigned *in, unsigned be, unsigned en) {
    bool **vi = new bool*[en]; for (auto&& e : wrapped_array(vi, en)) e = new bool[en];
    unsigned **dp = new unsigned*[en]; for (auto&& e : wrapped_array(dp, en)) e = new unsigned[en];

    return run(be, en, in, vi, dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
#endif

    cin >> n >> d;
    arr1 = new unsigned[4*(n/2)]; arr2 = new unsigned[4*(n/2)];
    for (auto&& ele : wrapped_array(arr1, 2*n)) ele = 1;
    for (auto&& ele : wrapped_array(arr2, 2*n)) ele = 1;
    if (n%2) {
        l = r = n-1;
        for (unsigned i = 0; i < n; i++) {
            cin >> in;
            if (i > 1) arr1[n+i-1] = in;
            if (i < n-1) arr2[n+i] = in;
        }
    }
    else {
        for (unsigned i = 0; i < n; i++) {
            cin >> in
            arr1[n+i] = in;
            if ((i > 1) && (i < n-1)) arr[n+i-1] = in;
        }
    }
    build(arr1, l); build(arr2, r);

    cout << get(arr1, n>>1, n-1) + get(arr2, (n-1)>>1, n-2);
}