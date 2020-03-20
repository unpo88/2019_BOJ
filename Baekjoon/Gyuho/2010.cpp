#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		result += temp;
	}
	cout << result - N + 1;
	return 0;
}