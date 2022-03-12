#include <bits/stdc++.h>
#define ONLINE false
#define DEBUG false
#define fi first
#define se second
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

typedef pair<float, pair<int, int>> edge;

int *parent;

int findSet(int x) { return (parent[x] == x) ? x : (parent[x] = findSet(parent[x])); }
bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }
void unionSet(int x, int y)  { parent[findSet(x)] = findSet(y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
#if ((__linux__ || _WIN32) && !ONLINE && !ONLINE_JUDGE)
    freopen("Kruskal.inp", "r", stdin);
    if (!DEBUG) freopen("Kruskal.out", "w", stdout);
#endif

    int n, m; cin >> n >> m;
    edge edgeList[m];
    parent = new int[n];

    for (unsigned i = 0; i < m; i++)
        cin >> edgeList[i].se.fi >> edgeList[i].se.se >> edgeList[i].fi;
    sort(edgeList, edgeList + m);

    for (unsigned i = 0; i < n; i++) parent[i] = i;
    int u[m], v[m], dem = 0; float ans = 0;
    for (unsigned i = 0; i < m; i++) {
        edge curr = edgeList[i];
        if (!isSameSet(curr.se.fi, curr.se.se)) {
            ans=curr.fi, dem++, u[dem]=curr.se.fi, v[dem]=curr.se.se;
            unionSet(curr.se.fi, curr.se.se);
        }
    }
    cout << ans << "\n";
    for (unsigned i = 1; i <= dem; i++) 
        cout << u[i] << ' ' << v[i] << "\n";
}

struct bignum
{
    vector<short> digit; bool negative = false;
    bignum() {
        digit = vector<short>();
        negative = false;
    };
    bignum(int in) {
        if (in < 0) {
            negative = true;
            in *= -1;
        }
        else 
        if (in == 0) {
            digit = vector<short>({0});
            negative = false;
            return;
        }
        while (in) {
            digit.push_back(in % 10);
            in /= 10;
        }
    }
    bignum(vector<short> inp1, bool inp2) {
        digit = inp1;
        negative = inp2;
    }
    void check(bignum& a, bignum& b) {
        while (a.digit.size() < b.digit.size())
            a.digit.push_back(0);
        while (a.digit.size() > b.digit.size())
            b.digit.push_back(0);
    }
    bignum check(bignum in) {
        if (in.digit.size() == 0)
            return tobignum(0, false);
        while(*(in.digit.end() - 1) == 0 && in.digit.size() > 1)
            in.digit.pop_back();
        return in;
    }
    long long toll(bignum in) {
        long long ou = 0;
        for (unsigned i = 0; i < in.digit.size(); i++)
            ou += in.digit[i] * (pow(10, i));
        if (in.negative)
            ou = 0 - ou;
        return ou;
    }
    bignum tobignum(long long in, bool negative) {
        bignum ou;
        ou.negative = negative;
        in = abs(in);
        if (!in)
            ou.digit = {0};
        else 
            while (in) {
                ou.digit.push_back(in % 10);
                in /= 10;
            }
        return ou;
    }
    friend istream& operator>>(istream& iostr, bignum& in) {
        string input; iostr >> input;
        in.digit.clear();
        while (input.size()) {
            if (isdigit(*(input.end()-1)))
                in.digit.push_back(*(input.end()-1) - '0');
            else 
            if (*(input.end()-1) == '-')
                in.negative = true;
            input.pop_back();
        }
        while (*(in.digit.end()-1) == 0)
            in.digit.pop_back();
        return iostr;
    }
    friend ostream& operator<<(ostream& iostr, bignum in) {
        if (in.negative) iostr << "-";
        while (in.digit.size()) {
            iostr << (*(in.digit.end()-1));
            in.digit.pop_back();
        }
        return iostr;
    }
    bignum operator+(bignum in) {
        auto a = check(*this); auto b = check(in); check(a, b);
        if (a.negative != b.negative) {
            if (a.negative) return check(tru(b, a));
            else            return check(tru(a, b));
        }
        return check(cong(a, b));
    }
    bignum operator-(bignum in) {
        auto a = check(*this); auto b = check(in); check(a, b);
        if (b.negative)
            return check(bignum{b.digit, false} + a);
        return check(tru(a, b));
    }
    bignum operator-=(bignum in){
        *this = *this - in;
        return *this;
    }
    bignum operator*(bignum in) {
        auto a = check(*this); auto b = check(in);
        if (a > b)
            swap(a, b);
        if (a.digit.size() == 1)
            return nhan1(a, b);
        auto length = a.digit.size()/2;
        bignum  righA = {vector<short> (a.digit.begin(), a.digit.begin() + length), false},
                leftA = {vector<short> (a.digit.begin() + length, a.digit.end()), false},
                righB = {vector<short> (b.digit.begin(), b.digit.begin() + length), false},
                leftB = {vector<short> (b.digit.begin() + length, b.digit.end()), false},                
        t0 = righA * righB,
        t1 = (leftA * righB) + (leftB * righA),
        t2 = leftA * leftB, 
        ou = nhan10(t2,(length) * 2) + nhan10(t1, length) + t0;
        ou.negative = (a.negative ^ b.negative);
        return ou;
    }
    bignum operator/(bignum in) {
        bignum a = check(*this), b = check(in), ou, temp(0);
        if (a.digit.size() < b.digit.size())
            return tobignum(0, false);
        ou.digit.clear(); b.negative = a.negative = false;
        auto iter = a.digit.rbegin();
        while (iter != a.digit.rend()) {
            temp = temp * 10 + bignum(*iter);
            unsigned count = 0;
            while (temp >= b) 
                temp -= b, count++;
            ou = ou * 10 + count;
            iter++;
        }
        ou.negative = ((*this).negative ^ in.negative);
        return ou;
    }
    short tru(short a, short b, unsigned* du) {
        *du = 0; short ou = a - b;
        if (ou < 0) {
            *du = 1;
            return 10 + ou;
        }
        return ou;
    }
    bignum tru(bignum a, bignum b) {
        bignum ou;
        if (less(a, b)) {
            ou = bignum{b.digit, false} - a;
            ou.negative = true;
            return ou;
        }
        unsigned du = 0; ou.negative = a.negative;
        ou.digit.push_back(tru(a.digit[0], b.digit[0], &du));
        for (unsigned i = 1; i < a.digit.size(); i++) {
            unsigned Du1 = 0, Du2 = 0;
            ou.digit.push_back(tru(tru(a.digit[i], b.digit[i], &Du1), du, &Du2) % 10);
            du = Du1 || Du2;
        }
        if (!toll(ou))
            ou.negative = false;
        return ou;
    }
    bignum cong(bignum a, bignum b) {
        unsigned du = 0; vector<short> ou; ou.clear();
        ou.push_back((a.digit[0] + b.digit[0]) % 10);
        du = bool(a.digit[0] + b.digit[0] > 9);
        for (unsigned i = 1; i < a.digit.size(); i++) {
            ou.push_back((a.digit[i] + b.digit[i] + du) % 10);
            du = bool(a.digit[i] + b.digit[i] + du > 9);
        }
        ou.push_back(du);
        while (*ou.begin() == '0')
            ou.erase(ou.begin());
        return {ou, a.negative};
    }
    bignum nhan1(bignum a, bignum b) {
        int gun = toll(a), du = 0;
        for (auto& digit : b.digit) 
            digit *= gun, digit += du, du = digit / 10, digit %= 10;
        b.digit.push_back(du);
        return b;
    }
    bignum nhan10(bignum in, long long length) {
        while (length--)
            in.digit.insert(in.digit.begin(), 0);
        return in;
    }
    bool operator<(bignum in) {
        auto a = *this; auto b = in;
        if (a.negative != b.negative)
            return a.negative;
        bool equal, ou = less(a, b, &equal);
        return ou ^ a.negative && !equal;
    }
    bool operator>(bignum in) {
        auto a = *this; auto b = in;
        if (a.negative != b.negative)
            return !a.negative;
        bool equal, ou = !less(a, b, &equal);
        return ou ^ a.negative && !equal;
    }
    bool operator==(bignum in) {
        bool ou = false;
        less(*this, in, &ou);
        return ou && ((*this).negative == in.negative);
    }
    bool operator>=(bignum in) {
        return !(*this < in) || *this == in;
    }
    bool operator<=(bignum in) {
        return *this < in || *this == in;
    }
    bool less(bignum left, bignum righ, bool* equal = nullptr) {
        if (equal   != nullptr) *equal = false; check(left, righ);
        while (*(left.digit.end()-1) == *(righ.digit.end()-1) && left.digit.size() > 0) {
            left.digit.pop_back();
            righ.digit.pop_back();
        }
        if (left.digit.size()) {
            bool ou = (*(left.digit.end()-1) < *(righ.digit.end()-1));
            return ou;
        }
        if (equal != nullptr) *equal = true;
        return false;
    }
};