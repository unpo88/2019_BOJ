#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int sum = 0;
	int answer = 0;
	for (int i = 0; i < 10; i++) {
		int A, B;
		cin >> A >> B;
		sum = sum - A + B;
		answer = max(answer, sum);
	}

	cout << answer << "\n";

	return 0;
}