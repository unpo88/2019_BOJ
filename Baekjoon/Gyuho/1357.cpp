#include <iostream>
using namespace std;

int REV(int num) {
	int ret;

	if (num >= 1000) {
		ret = (num % 10) * 1000 + (num / 10 % 10) * 100 + (num / 100 % 10) * 10 + num / 1000;
	}
	else if (num >= 100) {
		ret = (num % 10) * 100 + (num / 10 % 10) * 10 + (num / 100);
	}
	else if (num >= 10) {
		ret = num % 10 * 10 + num / 10;
	}
	else {
		ret = num;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int X, Y;
	cin >> X >> Y;

	cout << REV(REV(X) + REV(Y));
	return 0;
}