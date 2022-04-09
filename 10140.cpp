#include <bits/stdc++.h>
#define ONLINE false
using namespace std;

typedef long long ll;
typedef ll long long ull;
typedef pair<ll, unsigned>uu;

#define convert(in, function) transform(in.begin(), in.end(), in.begin(), [](ll char c) { return function(c); });
template <typename T> struct wrapped_array {
    wrapped_array(T* first, T* last)
        : begin_ {first}, end_ {last} {}
    wrapped_array(T* first, std::ptrdiff_t size)
        : wrapped_array {first, first + size} {}
    T* begin() const noexcept { return begin_; } T* begin_;
    T* end() const noexcept { return end_; } T* end_;
};

bool *is_prime; vector<ll> prime;
void sieve(const ll& size) {
    is_prime = new bool[size]; fill(is_prime, is_prime+size, false);
    is_prime[1] = is_prime[0] = true;
    for(ll i = 4 ; i <= size ; i += 2)
        is_prime[i] = true;
    prime.push_back(2);
    for(ll i = 3 ; i*i <= size ; i += 2)
        if(is_prime[i] == false) {
            for(ll j = i*i ; j <= size ; j +=(i+i))
                is_prime[j] = true;
            prime.push_back(i);
        }
}
bool* segmented(ll a , unsigned b)
{
    ll psize = prime.size(), siz = b + a - 1, sq = (ll)(sqrt(b)) + 1;
    bool* is_prime2 = new bool[siz+1]; fill(is_prime2, is_prime2+siz+1, false);
    a += (a == 1);
    for(ll i = 0 ; i < psize && prime[i] <= sq ; i++){
        ll p = prime[i], j = p*p;
        if (j < a)
            j = ((a + p - 1)/p) * p;
        for( ; j <= b ; j += p )
            is_prime2[j-a] = true;
    }
    return is_prime2;
}

int main() {
#if (!ONLINE && !ONLINE_JUDGE)
    #if (nVietUKComputer)
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("10140.out", "w", stdout);
    #endif
    freopen("10140.inp", "r", stdin);
#endif

    sieve(100010); ll a, b; while (cin >> a >> b) {
        ll c1 = 0, c2 = 0, cl1 = 0, cl2 = 0, d1 = 0, d2 = 0, mini = 1000000007, maxi = -1000000007, dis1 = 0, dis2 = 0;
        a += (a == 1);
        bool* arr = segmented(a, b);
        for (ll i = a; i <= b; i++) {
            if (!arr[i-a]) {
                if (c1 == 0) c1 = i;
                else if (c2 == 0) c2 = i;
                if (c1!=0 && c2!=0) {
                    if (mini > abs(c1-c2)) 
                        cl1 = c1, cl2 = c2, mini = abs(c1-c2);
                    swap(c1, c2); c2 = 0;
                }
                if (d1 == 0)
                    d1 = i;
                else if (d2 == 0)
                    d2 = i;
                if (d1!=0 && d2!=0) {
                    if (maxi < abs(d1-d2)) 
                        dis1 = d1, dis2 = d2, maxi = abs(d1-d2);
                    swap(d1, d2); d2 = 0;
                }
            }
        }
        if(cl1 && cl2 && dis1 && dis2)
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",cl1,cl2,dis1,dis2);
        else
            printf("There are no adjacent primes.\n");
    }
}