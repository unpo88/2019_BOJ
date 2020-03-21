#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	char s[6];
	int n;
	int charge;

	int sum = 0;
	while (N--) {
		for (int i = 0; i < 5; i++) {
			cin >> s[i];
		}
		cin >> n;

		int hour, minute;
		hour = (s[0] - '0') * 10 + (s[1] - '0');
		minute = (s[3] - '0') * 10 + (s[4] - '0');

		if (hour >= 7 && hour <= 19) {
			charge = 10;
		}
		else if (hour >= 19 && hour <= 7) {
			charge = 5;
		}

		sum += n * charge;
	}

	cout << sum << "\n";

	return 0;
}