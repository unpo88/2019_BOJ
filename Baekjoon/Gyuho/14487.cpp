#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int maxi = 0;
	long long ans = 0;
	int n; cin >> n;
	for (int i = 0; i<n; i++) {
		int t; cin >> t;
		maxi = max(maxi, t);
		ans += t;
	}
	ans -= maxi;
	cout << ans;

	return 0;
}