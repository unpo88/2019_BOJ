#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int arr[10];

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < 10; i++) {
		arr[0] -= arr[i];
	}

	cout << arr[0] << "\n";

	return 0;
}