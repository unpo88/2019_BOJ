#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int i, j, n, a[3], Max = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (Max < a[i]) {
			Max = a[i];
		}
	}

	for (i = 1; i <= Max; i++) {
		int cnt = 0;
		for (j = 0; j < n; j++) {
			if (a[j] % i == 0) {
				cnt++;
			}
		}
		if (cnt == n)
			cout << i << '\n';
	}

	return 0;
}