#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[51];
bool check[51];

int root_node;

int result = 0;

void BFS(int start) {
	check[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		int child_cnt = 0;
		for (int i = 0; i < v[node].size(); i++){
			int next = v[node][i];
			if (!check[next]) {
				child_cnt++;
				check[next] = true;
				q.push(next);
			}
		}
		if (child_cnt == 0) {
			result++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num != -1) {
			v[num].push_back(i);
			v[i].push_back(num);
		}
		else {
			root_node = i;
		}
	}

	cin >> num;
	check[num] = true;

	if (!check[root_node])	BFS(root_node);
	
	cout << result << "\n";
	return 0;
}