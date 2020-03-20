#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int sum = 0;
	int sum_cnt = 1;
	while (N--) {
		int num;
		cin >> num;
		if (num == 1) {
			sum += (num * sum_cnt);
			sum_cnt++;
		}
		else {
			sum_cnt = 1;
		}
	}

	cout << sum << "\n";

	return 0;
}