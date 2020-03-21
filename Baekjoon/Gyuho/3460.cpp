#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < 30; i++) {
			if (N&(1 << i)) {
				cout << i << " ";
			}
		}
	}

	return 0;
}