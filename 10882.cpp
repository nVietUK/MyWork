#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("10882.inp", "r", stdin);
    freopen("10882.out", "w", stdout);

    unsigned t, s = 1;
    cin >> t;
    while (t--){
        unsigned a, b, c;
        cin >> a >> b >> c;
        unsigned high = min(a, min(b, c)), low;
        if (a + b + c <= 100) 
            low = 0;
        else 
            low = (a+b+c-100+1) / 2;
        cout << "Case #" << s++ << ": ";
        if ((low < 0) || (low > high))
            cout << "The records are faulty.";
        else
            cout << "Between " << low << " and " << high << " times.";
        cout << "\n";
    }
}