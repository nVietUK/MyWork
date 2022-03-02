#include <bits/stdc++.h>

using namespace std;


int main() {
    unsigned n, q; cin >> n >> q; 
    int **arr = new int*[n];
    for (unsigned i = 0; i < n; i++) {
        unsigned l; cin >> l; arr[i] = new int[l];
        for (auto ele = arr[i]; ele <= arr[i] + l; ele++)
            cin >> *ele;
    }
    
    return 0;
}
