// [�ùķ��̼� + DFS]

// 1. �����Ҵ� ũ�Ⱑ N��M�� ���簢������ ��Ÿ�� �� ������, ���簢���� 1��1 ũ���� ���簢������ �������� �ִ�.�����Ҵ� �� ĭ, ������ �̷���� ������, ���� ĭ �ϳ��� ���� �����Ѵ�.
// 2. �Ϻ� ĭ�� ���̷����� �����ϸ�, �� ���̷����� �����¿�� ������ �� ĭ���� ��� �������� �� �ִ�. ���� ���� �� �ִ� ���� ������ 3���̸�, �� 3���� ������ �Ѵ�.
// 3. �������� ������ �־����� �� ���� �� �ִ� ���� ���� ũ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// 4. ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (3 �� N, M �� 8)
// 5. ��° �ٺ��� N���� �ٿ� ������ ����� �־�����. 0�� �� ĭ, 1�� ��, 2�� ���̷����� �ִ� ��ġ�̴�. 2�� ������ 2���� ũ�ų� ����, 10���� �۰ų� ���� �ڿ����̴�.
// 6. �� ĭ�� ������ 3�� �̻��̴�.
// 7. ù° �ٿ� ���� �� �ִ� ���� ������ �ִ� ũ�⸦ ����Ѵ�.

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;

int map[8][8];
int check[9][9];

queue<pair<int, int> > q;

int answer;
const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { -1, 1, 0, 0 };

int go() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = map[i][j];
			if (map[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
			if (check[nx][ny] == 0) {
				check[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0) {
				cnt += 1;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			if (map[x1][y1] != 0)    continue;
			for (int x2 = 0; x2 < N; x2++) {
				for (int y2 = 0; y2 < M; y2++) {
					if (map[x2][y2] != 0)    continue;
					for (int x3 = 0; x3 < N; x3++) {
						for (int y3 = 0; y3 < M; y3++) {
							if (map[x3][y3] != 0)    continue;
							if (x1 == x2 && y1 == y2)    continue;
							if (x2 == x3 && y2 == y3)    continue;
							if (x1 == x3 && y1 == y3)    continue;
							map[x1][y1] = map[x2][y2] = map[x3][y3] = 1;
							answer = max(answer, go());
							map[x1][y1] = map[x2][y2] = map[x3][y3] = 0;
						}
					}
				}
			}
		}
	}

	cout << answer << '\n';

	return 0;
}