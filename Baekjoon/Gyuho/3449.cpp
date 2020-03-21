#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int ans = 0;
		string a, b;
		cin >> a >> b;

		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])	ans++;
		}

		cout << "Hamming distance is " << ans << "." << "\n";

	}


	return 0;
}