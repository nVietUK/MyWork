#include <bits/stdc++.h>
#define vnoi pair<unsigned, pair<unsigned, unsigned>>

using namespace std;

template<typename _Tp>
    struct myless : public binary_function<_Tp, _Tp, bool>
    {
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(const vnoi& __x, const vnoi& __y) const
      { return __x.first > __y.first; }
    };

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.inp", "r", stdin);
#endif
    unsigned n, k, in;
    cin >> n >> k;
    vector<vector<unsigned>> ta; ta.clear(); ta.resize(n+1); for (unsigned i = 2; i <= n; i++) ta[i].resize(i, 100001);
    priority_queue<vnoi, vector<vnoi>, myless<vnoi>> tp;
    for (unsigned i = 1; i <= n; i++)
        for (unsigned j = 1; j <= n && cin >> in; j++)
            if (i != j)
            {   
                ta[max(i, j)][min(i, j)] = min(ta[max(i, j)][min(i, j)], in);
                if (max(i, j) == i) 
                    tp.push(make_pair(ta[max(i, j)][min(i, j)], make_pair(i, j)));
            }
    in = 0; while (tp.size() && n != k)
    {
        
    }
    cout << in;
}