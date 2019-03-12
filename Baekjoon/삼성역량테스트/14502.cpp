//[시뮬레이션 + DFS + BFS]
//연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <queue>
using namespace std;

//연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다.연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다.
int N, M;
int board[9][9];
int temp_board[9][9];

//일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int ans;
queue<pair<int, int> > q;

int go() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			temp_board[y][x] = board[y][x];
			if (temp_board[y][x] == 2) {
				q.push(make_pair(y, x));
			}
		}
	}
	//일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int next_y = y + dy[dir];
			int next_x = x + dx[dir];
			if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)	continue;
			if (temp_board[next_y][next_x] == 0) {
				temp_board[next_y][next_x] = 2;
				q.push(make_pair(next_y, next_x));
			}
		}
	}

	int result = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (temp_board[y][x] == 0) {
				result += 1;
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
	cin >> N >> M;

	//둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> board[y][x];
		}
	}

	//빈 칸의 개수는 3개 이상이다.
	for (int y1 = 0; y1 < N; ++y1) {
		for (int x1 = 0; x1 < M; ++x1) {
			if (board[y1][x1] != 0)	continue;
			for (int y2 = 0; y2 < N; ++y2) {
				for (int x2 = 0; x2 < M; ++x2) {
					if (board[y2][x2] != 0)	continue;
					for (int y3 = 0; y3 < N; ++y3) {
						for (int x3 = 0; x3 < M; ++x3) {
							if (board[y3][x3] != 0)	continue;
							if (y1 == y2 && x1 == x2)	continue;
							if (y2 == y3 && x2 == x3)	continue;
							if (y1 == y3 && x1 == x3)	continue;
							board[y1][x1] = board[y2][x2] = board[y3][x3] = 1;
							ans = max(ans, go());
							board[y1][x1] = board[y2][x2] = board[y3][x3] = 0;
						}
					}
				}
			}
		}
	}

	//첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.
	cout << ans << "\n";

	return 0;
}