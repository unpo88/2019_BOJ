#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n, T;
	cin >> n >> T;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		T -= num;
		if (T >= 0) {
			cnt++;
		}
	}
	
	cout << cnt << "\n";

	return 0;
}