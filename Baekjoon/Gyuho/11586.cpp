#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	string arr[105];
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> K;
	if (K == 1) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << endl;
		}
	}
	else if (K == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = arr[i].length() - 1; j >= 0; j--) {
				cout << arr[i].at(j);
			}
			cout << endl;
		}
	}
	else if (K == 3) {
		for (int i = N - 1; i >= 0; i--) {
			cout << arr[i] << endl;
		}
	}

	return 0;
}