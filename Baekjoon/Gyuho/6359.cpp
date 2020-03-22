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

		bool check[101] = { false, };
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				check[j] ^= true;
			}
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i])	++cnt;
		}

		cout << cnt << "\n";
	}

	return 0;
}