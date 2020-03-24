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

	int sum = 0;
	while (N--) {
		for (int i = 0; i < 5; i++) {
			cin >> s[i];
		}

		cin >> n;

		int hour, minute;
		hour = (s[0] - '0') * 10 + (s[1] - '0');
		minute = (s[3] - '0') * 10 + (s[4] - '0');

		while (n--) {

			if (hour >= 7 && hour < 19) {
				sum += 10;
			}
			else {
				sum += 5;
			}

			minute += 1;
			if (minute == 60) {
				hour += 1;
				if (hour == 24) {
					hour = 0;
				}
				minute = 0;
			}
		}
	}

	cout << sum << "\n";

	return 0;
}