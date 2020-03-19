#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
bool visited[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	queue<int> q;

	for (int i = 1; i <= M; i++) {
		int u, v;
		cin >> u >> v;

		map[u][v] = map[v][u] = 1;
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			answer++;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int first = q.front();
				q.pop();
				for (int j = 1; j <= N; j++) {
					if (map[first][j] && !visited[j]) {
						visited[j] = true;
						q.push(j);
					}
				}
			}
		}
	}

	cout << answer << "\n";
	return 0;
}