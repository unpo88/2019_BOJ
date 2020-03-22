#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int answer_max = -1;
		int answer_min = 100;

		int shop[20];
		for (int i = 0; i < n; i++) {
			cin >> shop[i];

			answer_max = max(answer_max, shop[i]);
			answer_min = min(answer_min, shop[i]);
		}

		cout << (answer_max - answer_min) * 2 << "\n";
	}

	return 0;
}