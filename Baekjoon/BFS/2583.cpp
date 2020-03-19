#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[101][101];

int N, M, K;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<int> v;

int DFS(int x, int y) {
	int ret = 1;
	map[x][y] = 1;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)	continue;
		if (!map[nx][ny])	ret += DFS(nx, ny);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;

	while (K--) {
		int e, b, c, d;
		cin >> e >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = e; j < c; j++) {
				map[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j])	v.push_back(DFS(i, j));
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto vec : v)	cout << vec << " ";

	return 0;
}