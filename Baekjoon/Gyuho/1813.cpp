#include <iostream>
using namespace std;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		arr[n]++;
	}

	for (int i = N; i >= 0; i--) {
		if (arr[i] == i) {
			cout << i << "\n";
			return 0;
		}
	}

	cout << "-1" << "\n";
	return 0;
}