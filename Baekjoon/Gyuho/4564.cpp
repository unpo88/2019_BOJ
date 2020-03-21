#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		int num;
		cin >> num;

		if (num == 0) {
			break;
		}

		int sum = 1;
		cout << num << " ";
		while (sum) {
			if (num < 10) {
				break;
			}
			while (num) {
				sum *= num % 10;
				num /= 10;
			}
			cout << sum << " ";
			if (sum < 10) {
				break;
			}
			num = sum;
			sum = 1;
		}
		
		cout << "\n";

	}

	return 0;
}