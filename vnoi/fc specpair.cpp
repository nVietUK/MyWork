#include <bits/stdc++.h>

using namespace std;

bool chk(unsigned in) {
    if (in < 10)
        return true;
    unsigned c = in % 10, d; in /= 10;
    do {
        d = in % 10; in /= 10;
        if (d != c)
            return false;
        if (in < 10)
            in = 0;
    }
    while (in);
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    unsigned N, ou = 0; cin >> N; vector<unsigned> arr(N);

    for (auto& ele : arr)
        cin >> ele;

    arr.push_back(0);

    for (unsigned i = 0; i < N-1; i++) 
        for (unsigned j = i + 1; j < N; j++) 
            if (chk(arr[i] + arr[j]))
                ou++;

    cout << ou;
}