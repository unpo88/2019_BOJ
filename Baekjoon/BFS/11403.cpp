#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int map[100][100] = { 0, };
	int visited[100][100] = { 0, };
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				visited[i][j] = 1;
				q.push(make_pair(i, j));

				while (!q.empty()) {
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < N; k++) {
						if (map[y][k] == 1 && !visited[i][k]) {
							visited[i][k] = 1;
							q.push(make_pair(y, k));
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}