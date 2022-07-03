#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<unsigned, unsigned>uu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](unsigned char c) { return function(c); });
template <typename T> struct dyArray {
    dyArray(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    dyArray(T* first, std::ptrdiff_t size)
        : dyArray {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (!nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen(".out", "w", stdout);
    #endif
    freopen(".inp", "r", stdin);
#endif

    
}