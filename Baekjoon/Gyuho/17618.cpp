#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int temp = i;
		while (temp) {
			sum = sum + temp % 10;
			temp = temp / 10;
		}
		if (i % sum == 0) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}