#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long N;
	cin >> N;

	int num;
	cin >> num;

	long long max = num;
	long long min = num;

	for (int i = 1; i < N; i++) {
		int num;
		cin >> num;
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}
	}

	cout << max - min;
	return 0;
}