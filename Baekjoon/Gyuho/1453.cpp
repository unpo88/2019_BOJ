#include <iostream>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	map<int, int> m;

	while (N--) {
		int num;
		cin >> num;
		m[num]++;
	}

	int sum = 0;
	for (auto pair : m) {
		if (pair.second >= 2) {
			sum += pair.second - 1;
		}
	}

	cout << sum << "\n";

	return 0;
}