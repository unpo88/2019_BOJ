#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int result = a + b + c + d;

	cout << result / 60 << "\n" << result % 60;

	return 0;
}