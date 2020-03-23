#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t, n, k, candy, ans;
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> k;
		while (n--)
		{
			cin >> candy;
			ans += candy / k;
		}
		cout << ans << '\n';
	}

	return 0;
}