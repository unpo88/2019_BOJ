#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int A, B, C, D, E;
		double sum = 0;
		cin >> A >> B >> C >> D >> E;

		sum = A * 350.34 + B * 230.90 + C * 190.55 + D * 125.30 + E * 180.90;

		cout << fixed;
		cout.precision(2);
		cout << "$" << sum << "\n";
	}

	return 0;
}