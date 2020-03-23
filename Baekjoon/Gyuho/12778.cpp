#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int M;
		char C;
		cin >> M >> C;

		if (C == 'C') {
			for (int i = 0; i<M; i++) {
				char c;
				cin >> c;
				cout << c - 'A' + 1 << " ";
			}
		}
		else {
			for (int i = 0; i<M; i++) {
				int n;
				cin >> n;
				cout << char(n - 1 + 'A') << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}