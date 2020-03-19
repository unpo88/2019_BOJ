#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;

		int answer = 1;
		for (int i = 0; i < b; i++) {
			answer = (answer * a) % 10;
		}

		if (answer == 0)	answer = 10;
		cout << answer << "\n";
	}

	return 0;
}