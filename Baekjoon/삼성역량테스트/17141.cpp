#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;

int map[51][51];
int visited[51][51];
int copy_map[51][51];

bool check[51] = { false, };

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

vector<pair<int, int> > v;
queue<pair<int, int> > q;

int answer = INT_MAX;

bool check_answer() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (copy_map[y][x] == -1) {
				return false;
			}
		}
	}
	return true;
}

void DFS(int idx, int cnt) {
	if (idx > v.size())	return;

	if (cnt == M) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				if (map[y][x] == 1) {
					copy_map[y][x] = -2;
				}
				else {
					copy_map[y][x] = -1;
				}
				visited[y][x] = 0;
			}
		}
		
		for (int i = 0; i < 51; ++i) {
			if (check[i]) {
				copy_map[v[i].first][v[i].second] = 0;
				q.push(make_pair(v[i].first, v[i].second));
			}
		}

		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			visited[y][x] = true;
			q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int next_y = y + dy[dir];
				int next_x = x + dx[dir];
				if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)	continue;
				if (!visited[next_y][next_x] && map[next_y][next_x] != 1 && copy_map[next_y][next_x] == -1) {
					visited[next_y][next_x] = true;
					copy_map[next_y][next_x] = copy_map[y][x] + 1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}

		/*for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
				cout << copy_map[y][x] << " ";
			}
			cout << endl;
		}*/

		if (check_answer()) {
			int result = 0;
			for (int y = 0; y < N; ++y) {
				for (int x = 0; x < N; ++x) {
					result = max(result, copy_map[y][x]);
				}
			}
			answer = min(answer, result);
		}
		
	}

	for (int i = idx; i < v.size(); ++i) {
		check[i] = true;
		DFS(i + 1, cnt + 1);
		check[i] = false;
	}
}
//�������� ���°� �־����� ��, ��� �� ĭ�� ���̷����� �۶߸��� �ּ� �ð��� ���غ���.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//ù° �ٿ� �������� ũ�� N(5 �� N �� 50), ���� �� �ִ� ���̷����� ���� M(2 �� M �� 10)�� �־�����.
	cin >> N >> M;
	//��° �ٺ��� N���� �ٿ� �������� ���°� �־�����. 0�� �� ĭ, 1�� ��, 2�� ���̷����� ���� �� �ִ� ��ġ�̴�. 2�� ������ M���� ũ�ų� ����, 10���� �۰ų� ���� �ڿ����̴�.
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				v.push_back(make_pair(y, x));
			}
		}
	}

	DFS(0, 0);

	//�������� ��� �� ĭ�� ���̷����� �ְ� �Ǵ� �ּ� �ð��� ����Ѵ�.
	//���̷����� ��� ���Ƶ� ��� �� ĭ�� ���̷����� �۶߸� �� ���� ��쿡�� - 1�� ����Ѵ�.

	if (answer == INT_MAX) {
		cout << "-1" << "\n";
	}
	else {
		cout << answer << "\n";
	}

	return 0;
}