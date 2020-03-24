#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int two = 0, five = 0;

		for (int i = 2; i <= N; i *= 2) {
			two += N / i;
		}

		for (int i = 5; i <= N; i *= 5) {
			five += N / i;
		}

		cout << min(two, five) << "\n";
	}

	return 0;
}