#include <iostream>
using namespace std;

int getNum(int a, int b) {
	if (b == 1)
		return 1;
	if (a == 0)
		return b;
	return (getNum(a - 1, b) + getNum(a, b - 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int k, n;
		cin >> k >> n;

		cout << getNum(k, n) << '\n';
	}
	
	return 0;
}