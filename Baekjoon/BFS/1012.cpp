#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int map[50][50] = { 0, };
		bool visited[50][50] = { false, };

		queue<pair<int, int>> q;
		
		int M, N, K;
		cin >> M >> N >> K;

		while (K--) {
			int X, Y;
			cin >> X >> Y;
			map[X][Y] = 1;
		}

		int answer = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					answer++;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						map[x][y] = 0;
						visited[x][y] = true;
						for (int dir = 0; dir < 4; dir++) {
							int nx = x + dx[dir]; 
							int ny = y + dy[dir];
							if (nx < 0 || ny < 0 || nx >= M || ny >= N || visited[nx][ny])	continue;
							if (map[nx][ny] == 1 && !visited[nx][ny]) {
								q.push(make_pair(nx, ny));
								visited[nx][ny] = true;
							}
						}
					}
				}
			}
		}
		
		cout << answer << "\n";
	}
	
	return 0;
}