#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b; 

		cout << "You get " << a / b << " piece(s) and your dad gets " << a % b << " piece(s).\n";
	}

	return 0;
}