#include <iostream>
#include <algorithm>
using namespace std;

int DP[1010];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;

	DP[1] = 1;
	DP[3] = 1;

	cin >> n;

	for (int i = 4; i <= n; i++) {
		if (!DP[i - 1] && !DP[i - 3] && !DP[i - 4])
			DP[i] = 1;
	}

	if (DP[n] == 1)	cout << "CY";
	else
	{
		cout << "SK";
	}

	return 0;
}