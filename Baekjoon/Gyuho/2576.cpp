#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num;
	int min_num = 100;
	int sum = 0;

	bool flag = false;
	for (int i = 0; i < 7; i++) {
		cin >> num;
		if (num % 2 == 1) {
			sum += num;
			flag = true;
			min_num = min(min_num, num);
		}
	}

	if (!flag) {
		cout << "-1\n";
	}
	else {
		cout << sum << "\n";
		cout << min_num << "\n";
	}
	return 0;
}