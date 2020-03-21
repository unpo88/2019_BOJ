#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int answer[] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++) {
		int num;
		cin >> num;

		cout << answer[i] - num << " ";
	}

	return 0;
}