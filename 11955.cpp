#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);    

	freopen("11955.INP", "r", stdin);
	freopen("11955.OUT", "w", stdout);
    
	int T, t; cin >> T;

	for (t = 1; t <= T; t++){
		string str, A, B, K = "";
		cin >> str;
		for (int i = 0; i < str.length(); i++)
			if ((str[i] == '(') || (str[i] == ' ') || (str[i] == '^'))
				continue;
			else if (str[i] == '+')
				A = K, K = "";
			else if (str[i] == ')')
				B = K, K = "";
			else K += str[i];
		int k = atoi(K.c_str());
		unsigned long long cof[k+1]; cof[0] = 1;
		for (int i = 1; i <= k; i++)
			cof[i] = (cof[i-1] * (k - i + 1)) / i;
		cout << "Case " << t << ": ";
		for (int i = 0; i <= k; i++) {
			if (cof[i] > 1) cout << cof[i];
			if (k - i > 0) 	cout << A.c_str();
			if (k - i > 1) 	cout << k-i;
			if ((cof[i] > 1 || k - i > 0) && i > 0)
							cout << "*";
			if (i > 0)		cout << B.c_str();
			if (i > 1)		cout << i;
			if (i < k) 		cout << "+";
		}
		cout << "\n";
	}

	return 0;
}