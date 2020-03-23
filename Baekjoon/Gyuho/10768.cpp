#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	if (A < 2) {
		cout << "Before" << "\n";
		return 0;
	}
	else if (A == 2) {
		if (B < 18) {
			cout << "Before" << "\n";
			return 0;
		}
		else if (B == 18) {
			cout << "Special" << "\n";
			return 0;
		}
		else if (B > 18) {
			cout << "After" << "\n";
			return 0;
		}
	}
	else if (A > 2) {
		cout << "After" << "\n";
		return 0;
	}
	return 0;
}