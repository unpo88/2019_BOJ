#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	long long DP[100010];

	cin >> n;

	DP[1] = 2;

	for (int i = 2; i <= n; ++i) {
		if (i % 2 == 0) {
			DP[i] = DP[i - 1];
		}
		else {
			DP[i] = (DP[i - 1] * 2) % 16769023;
		}
	}

	cout << DP[n] << endl;

	return 0;
}