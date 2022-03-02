#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
    
    unsigned N, ou = 0; cin >> N;
    unsigned arr[N];

    for (auto& ele : arr)
        cin >> ele;

    for (unsigned i = 1; i < N; i++) {
        ou += (arr+i)-upper_bound(arr, arr + i, arr[i] * 2);
        sort(arr, arr + i + 1);
    }
    cout << ou;
}