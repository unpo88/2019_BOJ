#include <iostream>
using namespace std;

int dp[90001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 2; i <= N*M; i++) {
		dp[i] = dp[i / 2] + dp[i - i / 2] + 1;
	}

	cout << dp[N*M];

	return 0;
}