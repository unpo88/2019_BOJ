#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	while (C--) {
		A ^= B;
	}
	cout << A << "\n";

	return 0;
}