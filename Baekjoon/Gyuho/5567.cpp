#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[501];
bool visited[501];

void DFS(int nodeNum) {
	for (int i = 0; i < v[nodeNum].size(); i++) {
		int next = v[nodeNum][i];
		visited[next] = true;
	}

	if (nodeNum == 1) {
		for (int i = 0; i < v[nodeNum].size(); i++) {
			int next = v[nodeNum][i];
			DFS(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
	
		v[a].push_back(b);
		v[b].push_back(a);
	}

	DFS(1);

	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (visited[i]) {
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}