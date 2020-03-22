#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	cout << min(a, min(b, c)) + min(d, e) - 50 << "\n";

	return 0;
}