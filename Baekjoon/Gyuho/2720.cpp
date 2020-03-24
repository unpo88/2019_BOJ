#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	int m[4] = { 25, 10, 5, 1 };

	while (T--) {
		int c;
		cin >> c;
		for (int i = 0; i < 4; i++)
		{
			cout << c / m[i] << ' ';
			c %= m[i];
		}
		cout << '\n';
	}

	return 0;
}