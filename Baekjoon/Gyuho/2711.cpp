#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		string x;
		cin >> x;

		for (int i = 0; i < x.size(); i++) {
			if (i == n - 1) {
				continue;
			}
			cout << x[i];
		}
		cout << "\n";
	}

	return 0;
}