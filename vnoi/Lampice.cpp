#include <bits/stdc++.h>
#define limax 50000 + 1
#define pp pair<unsigned, vector<unsigned>>
#define ham(a, c) find(a.begin(), a.end(), c) == a.end()

using namespace std;

// communist variables
    unsigned n; string s;
    set<unsigned> ta[limax];

vector<unsigned> la()
{
    vector<unsigned> ou;
    stack<unsigned> wa; bool vi[limax]; 
    memset(vi, false, sizeof(vi)); wa.push(1); vi[1] = true;
    while (wa.size())
    {
        auto curr = wa.top(); wa.pop();
        bool chay = true;
        for (auto& temp2 : ta[curr])
            if (!vi[temp2])
            {
                wa.push(temp2);
                chay = false;
                vi[temp2] = true;
            }
        if (chay) ou.push_back(curr);
    }
    return ou;
}

bool doixungrun(vector<unsigned> in)
{
    unsigned si = in.size()-1;
    for (unsigned i = 0; i <= in.size()/2; i++)
        if (s[in[i]] != s[in[si-i]])
            return false;
    return true;
}
unsigned doixung(vector<unsigned>& in)
{
    unsigned ou = 0;
    for (unsigned i = 0; i < in.size()-1; i++)
    {
        for (int j = in.size()-1; j > i; j--)
            if (doixungrun(vector<unsigned>(in.begin() + i, in.begin() + j + 1)))
                ou = max(ou, j - i);
    }
    return ou + 1;
}

vector<vector<unsigned>> pass; bool laVi[limax];
unsigned chay(unsigned start, unsigned tranh)
{
    unsigned oum = 0; laVi[start] = true;
    queue<pp> wa; wa.push({start, vector<unsigned>{start}});
    while (wa.size())
    {
        auto curr = wa.front(); wa.pop(); bool imp = true;

        if (ta[curr.first].size() > 2 && ham(ta[curr.first], tranh) && curr.first != start)
        {
            pass.push_back(vector<unsigned>(curr.second.begin(), curr.second.end()-1));
            oum = max(chay(curr.first, *(curr.second.end()-2)), oum);
            pass.pop_back();
            continue;
        }

        for (auto& temp : ta[curr.first])
            if (temp != tranh && ham(curr.second, temp))
            {
                auto next = curr;
                next.first = temp;
                next.second.push_back(temp);                
                wa.push(next); 
                imp = false;
            }
        if (imp && !laVi[curr.first]) 
        {
            auto temp3V = curr.second;
            int i = pass.size(); while (i--)
                temp3V.insert(temp3V.begin(), pass[i].begin(), pass[i].end());
            oum = max(doixung(temp3V), oum);
        }
    }
    return oum;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Lampice.inp", "r", stdin);
    freopen("Lampice.out", "w", stdout);
#endif
    
    unsigned u, v;
    cin >> n >> s; s.insert(s.begin(), '.');
    for (unsigned i = 1; i < n && cin >> u >> v; i++)
    {
        ta[u].insert(v);
        ta[v].insert(u);
    }

    memset(laVi, false, sizeof(laVi)); unsigned ou = 0;
    for (auto& temp1 : la())
        ou = max(ou, chay(temp1, 0));
    cout << ou;
}