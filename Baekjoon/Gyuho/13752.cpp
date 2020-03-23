#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;

		while (n--) {
			cout << "=";
		}
		cout << "\n";
	}

	return 0;
}