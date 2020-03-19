#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;

char map[101][101];
bool visited[101][101];
int cnt_map[101][101];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int BFS(int start_x, int start_y) {
	queue<pair<int, int>> q;
	visited[start_x][start_y] = true;
	cnt_map[start_x][start_y] = 1;
	q.push(make_pair(start_x, start_y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M || map[nx][ny] == '0')	continue;
			if (!visited[nx][ny] && map[nx][ny] == '1') {
				visited[nx][ny] = true;
				cnt_map[nx][ny] += cnt_map[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return cnt_map[N][M];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	cout << BFS(1, 1) << "\n";

	return 0;
}