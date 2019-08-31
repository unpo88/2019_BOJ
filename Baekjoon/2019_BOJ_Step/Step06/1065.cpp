#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	
	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		int a, b, c, d;
		a = i / 1000;
		b = i % 1000 / 100;
		c = i % 1000 % 100 / 10;
		d = i % 1000 % 100 % 10;

		if (i >= 100 && i < 1000 && d - c == c - b) {
			cnt++;
		}
		else if (i >= 10 && i < 100) {
			cnt++;
		}
		else if (i < 10) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}