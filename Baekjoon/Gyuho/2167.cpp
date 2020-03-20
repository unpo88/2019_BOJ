#include <iostream>
using namespace std;

int map[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int y = 1; y <= N; y ++) {
		for (int x = 1; x <= M; x++) {
			cin >> map[y][x];
		}
	}

	int K;
	cin >> K;

	while (K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;

		int sum = 0;
		for (int col = i; col <= x; col++) {
			for (int row = j; row <= y; row++) {
				sum += map[col][row];
			}
		}

		cout << sum << "\n";
	}
	return 0;
}