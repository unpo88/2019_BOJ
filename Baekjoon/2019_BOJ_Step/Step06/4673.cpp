#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	bool a[10001] = { false, };

	for (int i = 1; i <= 10000; ++i) {
		if (i + (i / 10000) + (i % 10000 / 1000) + (i % 10000 % 1000 / 100) + (i % 10000 % 1000 % 100 / 10) + (i % 10000 % 1000 % 100 % 10) <= 10000) {
			a[i + (i / 10000) + (i % 10000 / 1000) + (i % 10000 % 1000 / 100) + (i % 10000 % 1000 % 100 / 10) + (i % 10000 % 1000 % 100 % 10)] = true;
		}
	}

	for (int i = 1; i <= 10000; ++i) {
		if (!a[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}