#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long A, B;

	while (1) {
		cin >> A >> B;

		if (A == 0 && B == 0) {
			break;
		}

		cout << 2 * A - B << "\n";
	}


	return 0;
}