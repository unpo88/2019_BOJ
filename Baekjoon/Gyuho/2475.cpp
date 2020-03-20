#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int answer = 0;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;

		answer += (num * num);
	}

	cout << answer % 10 << "\n";
	return 0;
}