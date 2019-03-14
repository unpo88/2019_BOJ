// [시뮬레이션 + DFS]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y, n;
	point(int x, int y, int n) :
		x(x), y(y), n(n)	{}
};


// 스타트링크의 사무실은 1×1크기의 정사각형으로 나누어져 있는 N×M 크기의 직사각형으로 나타낼 수 있다.
int N, M;

// 사무실에는 총 K개의 CCTV가 설치되어져 있는데, CCTV는 5가지 종류가 있다.
// CCTV의 최대 개수는 8개를 넘지 않는다.
int map[8][8];
int visit[8][8];

int answer = 987654321;

vector<point> v;

// CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며, 감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다.
void check(int x, int y, int dir, int flag) {
	if (dir == 0) {
		--x;
		while (x >= 0) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			x--;
		}
	}
	else if (dir == 1) {
		++y;
		while (y < M) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			y++;
		}
	}
	else if (dir == 2) {
		++x;
		while (x < N) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			x++;
		}
	}
	else if (dir == 3) {
		--y;
		while (y >= 0) {
			if (map[x][y] == 6)	return;
			if (flag)	visit[x][y]++;
			else visit[x][y]--;
			y--;
		}
	}
}

int get_result() {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 && visit[i][j] == 0) {
				sum++;
			}
		}
	}
	return sum;
}


// CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다. 사무실에는 벽이 있는데, CCTV는 벽을 통과할 수 없다. CCTV가 감시할 수 없는 영역은 사각지대라고 한다.
void DFS(int idx) {
	if (idx == v.size()) {
		answer = min(answer, get_result());
		return;
	}

	int x = v[idx].x;
	int y = v[idx].y;
	int num = v[idx].n;

	if (num == 1) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
		}
	}
	else if (num == 2) {
		for (int i = 0; i < 2; i++) {
			check(x, y, i, 0);
			check(x, y, i + 2, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, i + 2, 1);
		}
	}
	else if (num == 3) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			check(x, y, (i + 1) % 4, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1) % 4, 1);
		}
	}
	else if (num == 4) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
			check(x, y, (i + 1) % 4, 0);
			check(x, y, (i + 3) % 4, 0);
			DFS(idx + 1);
			check(x, y, i, 1);
			check(x, y, (i + 1) % 4, 1);
			check(x, y, (i + 3) % 4, 1);
		}
	}
	else if (num == 5) {
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 0);
		}
		DFS(idx + 1);
		for (int i = 0; i < 4; i++) {
			check(x, y, i, 1);
		}
	}
}

// 사무실의 크기와 상태, 그리고 CCTV의 정보가 주어졌을 때, CCTV의 방향을 적절히 정해서,
// 사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 첫째 줄에 사무실의 세로 크기 N과 가로 크기 M이 주어진다. (1 ≤ N, M ≤ 8)
	cin >> N >> M;

    // 둘째 줄부터 N개의 줄에는 사무실 각 칸의 정보가 주어진다. 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타낸다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0 || map[i][j] == 6)	continue;
			v.push_back(point(i, j, map[i][j]));
		}
	}
	
	DFS(0);
    
    // 첫째 줄에 사각 지대의 최소 크기를 출력한다.
	cout << answer << '\n';
	return 0;
}