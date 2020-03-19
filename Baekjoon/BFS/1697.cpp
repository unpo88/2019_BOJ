#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int MAX = 200001;

bool visited[MAX];
int time[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<int> q;
	visited[N] = true;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 >= 0) {
			if (!visited[now - 1]) {
				q.push(now - 1);
				visited[now - 1] = true;
				time[now - 1] = time[now] + 1;
			}
		}

		if (now + 1 < MAX) {
			if (!visited[now + 1]) {
				q.push(now + 1);
				visited[now + 1] = true;
				time[now + 1] = time[now] + 1;
			}
		}

		if (now * 2 < MAX) {
			if (!visited[now * 2]) {
				q.push(now * 2);
				visited[now * 2] = true;
				time[now * 2] = time[now] + 1;
			}
		}
	}

	cout << time[K];

	return 0;
}