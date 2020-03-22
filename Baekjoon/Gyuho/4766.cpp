#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	double a;
	cin >> a;

	cout << fixed;
	cout.precision(2);
	while (1) {
		double b;
		cin >> b;
		if (b == 999) {
			break;
		}
		cout << b - a << "\n";
		a = b;
	}

	return 0;
}