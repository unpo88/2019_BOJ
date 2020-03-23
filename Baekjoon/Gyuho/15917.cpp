#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long Q;
	cin >> Q;

	while (Q--) {
		int n;
		cin >> n;
		if (n & (n - 1)) 
			cout << "0\n";
		else 
			cout << "1\n";
	}

	return 0;
}