// [시뮬레이션]

// 1. 첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
// 2. 둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.
// 3. 첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
// 4. 정사각형은 서로 겹치면 안된다.
// 5. 도형은 모두 연결되어 있어야 한다.
// 6. 정사각형의 꼭짓점끼리 연결되어 있어야 한다. 즉, 변과 꼭짓점이 맞닿아있으면 안된다.
// 7. 정사각형은 서로 겹치면 안된다.
// 8. 도형은 모두 연결되어 있어야 한다.
// 9. 정사각형의 꼭짓점끼리 연결되어 있어야 한다. 즉, 변과 꼭짓점이 맞닿아있으면 안된다.

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