#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int map[101][101];
bool visited[101][101];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void DFS(int y, int x, int height) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N)	continue;
		if (map[ny][nx] <= height || visited[ny][nx])	continue;
		visited[ny][nx] = true;
		DFS(ny, nx, height);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	int max_height = 0;
	int min_height = 100;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			max_height = max(max_height, map[y][x]);
			min_height = min(min_height, map[y][x]);
		}
	}

	int answer = 1;
	for(int height = min_height; height < max_height; height++){
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x] > height && !visited[y][x]) {
					visited[y][x] = true;
					cnt++;
					DFS(y, x, height);
				}
			}
		}
		answer = max(answer, cnt);
	}

	cout << answer << "\n";
	return 0;
}