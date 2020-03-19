#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<vector<int>> v(1001);
bool visited[1001];

void DFS(int x) {
	visited[x] = true;
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		if (!visited[v[x][i]]) {
			DFS(v[x][i]);
		}
	}
}

void BFS(int x) {
	queue<int> q;
	memset(visited, false, sizeof(visited));
	q.push(x);
	visited[x] = true;
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		cout << first << " ";
		for (int i = 0; i < v[first].size(); i++) {
			if (!visited[v[first][i]]) {
				visited[v[first][i]] = true;
				q.push(v[first][i]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);	v[e].push_back(s);
	}

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	DFS(V);
	cout << "\n";
	BFS(V);
	cout << "\n";

	return 0;
}