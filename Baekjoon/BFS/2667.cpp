#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

char map[26][26];
bool visited[26][26];

vector<int> answer;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int result;

void DFS(int start_x, int start_y) {
	visited[start_x][start_y] = true;
	result++;
	for (int dir = 0; dir < 4; dir++) {
		int nx = start_x + dx[dir];
		int ny = start_y + dy[dir];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N || visited[nx][ny])	continue;
		if (map[nx][ny] == '1' && !visited[nx][ny]) {
			DFS(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				DFS(i, j);
				answer.push_back(result);
				result = 0;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}