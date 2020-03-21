#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	int C;
	cin >> C;
	
	int hour, minute;
	hour = C / 60;
	minute = C % 60;

	int result_hour = A + hour;
	int result_minute = B + minute;

	if (result_minute >= 60) {
		result_hour += 1;
		result_minute -= 60;
	}

	if (result_hour >= 24) {
		result_hour -= 24;
	}

	cout << result_hour << " " << result_minute << "\n";

	return 0;
}