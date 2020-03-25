#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		int X = 1, Y = 1;
		int cnt = 1;
		bool flag = false;
		while (1) {
			if (X < M) {
				X = X + 1;
			}
			else if (X >= M) {
				X = 1;
			}

			if (Y < N) {
				Y = Y + 1;
			}
			else if (Y >= N) {
				Y = 1;
			}
			cnt++;

			if (x == X && y == Y) {
				flag = true;
				break;
			}
			else if (X == M && Y == N) {
				break;
			}
		}
		if (flag) {
			cout << cnt << "\n";
		}
		else {
			cout << "-1\n";
		}
	}

	return 0;
}