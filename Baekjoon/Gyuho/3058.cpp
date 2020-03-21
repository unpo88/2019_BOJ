#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int sum = 0;
		int min_even = 100;
		for (int i = 0; i < 7; i++) {
			int num;
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				min_even = min(min_even, num);
			}
		}
		cout << sum << " " << min_even << "\n";
	}

	return 0;
}