// [시뮬레이션 + DFS]

// 1. 연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
// 2. 일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
// 3. 연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.
// 4. 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
// 5. 둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
// 6. 빈 칸의 개수는 3개 이상이다.
// 7. 첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;

int map[8][8];
int check[9][9];

queue<pair<int, int> > q;

int answer;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { -1, 1, 0, 0 };

int go() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = map[i][j];
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
			if (check[nx][ny] == 0) {
				check[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
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

	int answer = 0;
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			if (map[x1][y1] != 0)    continue;
			for (int x2 = 0; x2 < N; x2++) {
				for (int y2 = 0; y2 < M; y2++) {
					if (map[x2][y2] != 0)    continue;
					for (int x3 = 0; x3 < N; x3++) {
						for (int y3 = 0; y3 < M; y3++) {
							if (map[x3][y3] != 0)    continue;
							if (x1 == x2 && y1 == y2)    continue;
							if (x2 == x3 && y2 == y3)    continue;
							if (x1 == x3 && y1 == y3)    continue;
							map[x1][y1] = map[x2][y2] = map[x3][y3] = 1;
							answer = max(answer, go());
							map[x1][y1] = map[x2][y2] = map[x3][y3] = 0;
						}
					}
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}