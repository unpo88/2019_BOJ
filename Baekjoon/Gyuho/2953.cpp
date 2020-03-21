#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int map[5][4];
	int cnt = 0;
	int answer = 0;
	for (int i = 0; i < 5; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
			sum += map[i][j];
		}
		if (sum > answer) {
			cnt = i + 1;
			answer = sum;
		}
	}

	cout << cnt << " " << answer << "\n";

	return 0;
}