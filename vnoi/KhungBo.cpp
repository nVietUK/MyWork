#include <bits/stdc++.h>

using namespace std;

// communist variables
    

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("khungbo.inp", "r", stdin);
    freopen("khungbo.out", "w", stdout);
#endif
    
    unsigned n, m, in, im;
    while (cin >> n >> m)
    {
        vector<unsigned> tar;
        vector<vector<bool>> ta(n+1); for (auto& tp : ta) tp.resize(n+1, false);
        while (n-- && cin >> in) tar.push_back(in);

        while (m-- && cin >> in >> im)
            ta[in][im] = ta[im][in] = true;
        
        while (tar.size() > 1)
        {
            in = *(tar.begin()); tar.erase(tar.begin());

            vector<unsigned> job;
            for (im = 1; im < ta[0].size(); im++)
                if (ta[im][in])
                {
                    ta[im][in] = ta[in][im] = false;
                    job.push_back(im);
                }
            
            n = false;
            im = job.size(); do
            {
                for (unsigned in = 0; in < im-1; in++)
                    if (!ta[job[in]][job[im-1]])
                    {
                        cout << "NO" << "\n";
                        n = true;
                        break;
                    }
                if (n) break; im--;
            }
            while (im);
            if (n) break;
        }
        if (!n) cout << "YES" << "\n";
    }
}