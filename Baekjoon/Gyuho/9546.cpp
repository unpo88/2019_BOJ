#include <iostream>
using namespace std;

int n, sum, arr[200000], p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int K;
		cin >> K;
		cout << (1 << K) - 1 << "\n";
	}

	return 0;
}