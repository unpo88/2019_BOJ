#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int map[500][500];
bool c[500][500];

int ans;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum)   ans = sum;
		return;
	}
	if (x < 0 || y < 0 || x >= N || y >= M)  return;
	if (c[x][y]) return;
	c[x][y] = true;
	for (int i = 0; i < 4; i++) {
		go(x + dx[i], y + dy[i], sum + map[x][y], cnt + 1);
	}
	c[x][y] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			go(i, j, 0, 0);
			if (j + 2 < M) {
				int temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
				if (i - 1 >= 0) {
					int temp2 = temp + map[i - 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (i + 1 < N) {
					int temp2 = temp + map[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
			}
			if (i + 2 < N) {
				int temp = map[i][j] + map[i + 1][j] + map[i + 2][j];
				if (j + 1 < M) {
					int temp2 = temp + map[i + 1][j + 1];
					if (ans < temp2) ans = temp2;
				}
				if (j - 1 >= 0) {
					int temp2 = temp + map[i + 1][j - 1];
					if (ans < temp2) ans = temp2;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}