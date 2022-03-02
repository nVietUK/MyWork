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

template <typename T>
    wrapped_array<T> wrap_array(T* first, std::ptrdiff_t size) noexcept
    { return {first, size}; }

using namespace std;

unsigned n, *a, **dp;
ull d;
bool **vis;

unsigned get(short u,short v){
    if (vis[u][v]) 
        return dp[u][v];
    vis[u][v]=true;

    if (u+1==v) 
        return dp[u][v]=0;
    dp[u][v]=0;
    for (short i=u+1;i<v;++i)
        dp[u][v] += get(u,i) + get(i,v);

    dp[u][v]+=a[v]-a[u];
    return dp[u][v];
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    freopen("shopping.inp","r",stdin);
    freopen("shopping.out","w",stdout);

    cin >> n >> d;
    a = new unsigned[n];
    vis = new bool*[n]; for (auto&& ele : wrap_array(vis, n)) ele = new bool[n];
    dp = new unsigned*[n]; for (auto&& ele : wrap_array(dp, n)) ele = new unsigned[n];
    for (auto&& ele : wrap_array(a, n))
        cin >> ele;
    cout << get(0, n-1);
}
