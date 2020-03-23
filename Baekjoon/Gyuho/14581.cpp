#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string x;
	cin >> x;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				cout << ":" << x << ":";
			}
			else {
				cout << ":fan:";
			}
		}
		cout << "\n";
	}

	return 0;
}