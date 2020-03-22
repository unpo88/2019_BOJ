#include <iostream>
using namespace std;

long long cache[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	

	cache[1] = 1;

	for (int i = 2; i <= 100; i++) {
		cache[i] = cache[i - 1] + i*i;
	}

	while (1) {
		int N;
		cin >> N;

		if (N == 0) {
			break;
		}

		cout << cache[N] << "\n";
	}

	return 0;
}