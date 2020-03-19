#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N;

queue<pair<int, int>> q;

int map[1001][1001];
bool visited[1001][1001];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int result() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				return -1;
			}
			answer = max(answer, map[i][j]);
		}
	}

	return answer - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> M >> N;

	bool flag = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)	q.push(make_pair(i, j));
			else if (map[i][j] == 0)	flag = true;
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M || visited[nx][ny] || map[nx][ny] == -1)	continue;
			if (!visited[nx][ny] && map[nx][ny] == 0) {
				map[nx][ny] = map[x][y] + 1;
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	if (!flag) {
		cout << "0\n";
	}
	else {
		cout << result() << "\n";
	}

	return 0;
}
