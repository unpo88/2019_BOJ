#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int sing = 1;
	int cnt = 0;

	while (N != 0) {
		if (N < sing) {
			sing = 1;
		}
		N -= sing;
		sing++;
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}