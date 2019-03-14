// 입력으로 주어지는 가로선이 서로 연속하는 경우는 없다.
// i번 세로선의 결과가 i번이 나오도록 사다리 게임을 조작하려면, 추가해야 하는 가로선 개수의 최솟값을 출력한다. 만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 사다리 게임은 N개의 세로선과 M개의 가로선으로 이루어져 있다. 인접한 세로선 사이에는 가로선을 놓을 수 있는데, 각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H이고, 모든 세로선이 같은 위치를 갖는다. 아래 그림은 N = 5, H = 6 인 경우의 그림이고, 가로선은 없다.
// 초록선은 세로선을 나타내고, 초록선과 점선이 교차하는 점은 가로선을 놓을 수 있는 점이다. 가로선은 인접한 두 세로선을 연결해야 한다. 단, 두 가로선이 연속하거나 서로 접하면 안된다. 또, 가로선은 점선 위에 있어야 한다.
int C, W, H;

int map[100][100];

int start(int c) {
	int r = 1;
	while (r <= H) {
		if (map[r][c] == 1) {
			c += 1;
		}
		else if (map[r][c] == 2) {
			c -= 1;
		}
		r += 1;
	}
	return c;
}

// 가장 위에 있는 점선의 번호는 1번이고, 아래로 내려갈 때마다 1이 증가한다. 세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가한다.
bool go() {
	for (int i = 1; i <= C; i++) {
		if (i != start(i))	return false;
	}
	return true;
}

// 사다리에 가로선을 추가해서, 사다리 게임의 결과를 조작하려고 한다. 이때, i번 세로선의 결과가 i번이 나와야 한다. 그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성하시오.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 첫째 줄에 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을 수 있는 위치의 개수 H가 주어진다. (2 ≤ N ≤ 10, 1 ≤ H ≤ 30, 0 ≤ M ≤ (N-1)×H)
	cin >> C >> W >> H;

    // 둘째 줄부터 M개의 줄에는 가로선의 정보가 한 줄에 하나씩 주어진다.
	for (int i = 0; i < W; i++) {
		int a, b;
    // 가로선의 정보는 두 정수 a과 b로 나타낸다. (1 ≤ a ≤ H, 1 ≤ b ≤ N-1) b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는 의미이다.
		cin >> a >> b;
		map[a][b] = 1;
		map[a][b + 1] = 2;
	}

	vector<pair<int, int> >v;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= C - 1; j++) {
			if (map[i][j] != 0)	continue;
			if (map[i][j + 1] != 0)	continue;
			v.push_back(make_pair(i, j));
		}
	}

	if (go()) {
		cout << 0 << '\n';
		return 0;
	}

	int len = v.size();

	int answer = -1;
	for (int i = 0; i < len; i++) {
		int x1 = v[i].first;
		int y1 = v[i].second;
		if (map[x1][y1] != 0 || map[x1][y1 + 1] != 0)	continue;
		map[x1][y1] = 1;
		map[x1][y1 + 1] = 2;
		if (go()) {
			if (answer == -1 || answer > 1) {
				answer = 1;
			}
		}
		for (int j = i+1; j < len; j++) {
			int x2 = v[j].first;
			int y2 = v[j].second;
			if (map[x2][y2] != 0 || map[x2][y2 + 1] != 0)	continue;
			map[x2][y2] = 1;
			map[x2][y2 + 1] = 2;
			if (go()) {
				if (answer == -1 || answer > 2) {
					answer = 2;
				}
			}
			for (int k = j + 1; k < len; k++) {
				int x3 = v[k].first;
				int y3 = v[k].second;
				if (map[x3][y3] != 0 || map[x3][y3 + 1] != 0)	continue;
				map[x3][y3] = 1;
				map[x3][y3 + 1] = 2;
				if (go()) {
					if (answer == -1 || answer > 3) {
						answer = 3;
					}
				}
				map[x3][y3] = 0;
				map[x3][y3 + 1] = 0;
			}
			map[x2][y2] = 0;
			map[x2][y2 + 1] = 0;
		}
		map[x1][y1] = 0;
		map[x1][y1 + 1] = 0;
	}

	cout << answer << '\n';

	return 0;
}