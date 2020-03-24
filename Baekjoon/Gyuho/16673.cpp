#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int C, K, P;
	cin >> C >> K >> P;

	long long result = (C * (C + 1) / 2) * K + (C * (C + 1) * (2 * C + 1) / 6) * P;

	cout << result << "\n";

	return 0;
}