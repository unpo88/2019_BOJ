#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	double e = 0;
	int fact = 1;
	cout << "n e" << "\n";
	cout << "- -----------" << "\n";
	for (int i = 0; i <= 9; i++) {
		if (i > 0) {
			fact *= i;
		}
		e += (double)1 / fact;
		if (i < 3) {
			cout << i << " " << e << "\n";
		}
		else {
			cout.precision(9);
			cout << i << fixed << " " << e << "\n";
		}
	}

	return 0;
}