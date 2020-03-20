#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		int arr[4] = { 0, };
		int check[2] = { 0, };
		for (int j = 0; j < 4; j++) {
			cin >> arr[j];
			if (arr[j] == 0) {
				check[0]++;
			}
			else {
				check[1]++;
			}
		}
		if (check[1] == 4) {
			cout << "E\n";
		}
		else if (check[1] == 3) {
			cout << "A\n";
		}
		else if (check[1] == 2) {
			cout << "B\n";
		}
		else if (check[1] == 1) {
			cout << "C\n";
		}
		else {
			cout << "D\n";
		}
	}
	return 0;
}