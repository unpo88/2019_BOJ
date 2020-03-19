#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;

int board[8][8];
int temp_board[8][8];

queue<pair<int, int>> q;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int BFS() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			temp_board[y][x] = board[y][x];
			if (temp_board[y][x] == 2) {
				q.push(make_pair(y, x));
			}
		}
	}
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)	continue;
			if (temp_board[ny][nx] == 0) {
				temp_board[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}

	int result = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
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

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}

	
	int answer = 0;
	for (int y1 = 0; y1 < N; y1++) {
		for (int x1 = 0; x1 < M; x1++) {
			if (board[y1][x1] != 0)	continue;
			for (int y2 = 0; y2 < N; y2++) {
				for (int x2 = 0; x2 < M; x2++) {
					if (board[y2][x2] != 0)	continue;
					if (y1 == y2 && x1 == x2)	continue;
					for (int y3 = 0; y3 < N; y3++) {
						for (int x3 = 0; x3 < M; x3++) {
							if (board[y3][x3] != 0)	continue;
							if (y1 == y3 && x1 == x3)	continue;
							if (y2 == y3 && x2 == x3)	continue;
							board[y1][x1] = board[y2][x2] = board[y3][x3] = 1;
							answer = max(answer, BFS());
							board[y1][x1] = board[y2][x2] = board[y3][x3] = 0;
						}
					}
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}