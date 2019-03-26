#include <iostream>
#include <queue>
using namespace std;

struct SHARK {
	int y, x, time;
};

//아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다.가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
int shark_size, shark_eat;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

//N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다.공간은 1×1 크기의 정사각형 칸으로 나누어져 있다.한 칸에는 물고기가 최대 1마리 존재한다.
int N;
int map[20][20];


SHARK shark;

//공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	//첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.
	cin >> N;

	//둘째 줄부터 N개의 줄에 공간의 상태가 주어진다.공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				shark.y = y, shark.x = x, shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[y][x] = 0;
			}
		}
	}

	bool is_updated = true;
	while (is_updated) {
		is_updated = false;

		bool visited[20][20] = { false, };
		queue<SHARK> q;
		visited[shark.y][shark.x] = true;
		q.push(shark);

		SHARK candi;
		candi.y = 20, candi.time = -1;
		while (!q.empty()) {
			SHARK cur = q.front();	q.pop();

			//더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
			if (candi.time != -1 && candi.time < cur.time)	break;

			//먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
			//먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
			//거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최소값이다.
			if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0) {
				is_updated = true;

				//거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

				if (candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)) {
					candi = cur;
				}
			}


			for (int dir = 0; dir < 4; ++dir) {
				SHARK next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.time = cur.time + 1;

				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)	continue;

				//아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
				//아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
				if (!visited[next.y][next.x] && shark_size >= map[next.y][next.x]) {
					visited[next.y][next.x] = true;
					q.push(next);
				}
			}
		}

		//아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다.즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다.물고기를 먹으면, 그 칸은 빈 칸이 된다.
		//아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.
		if (is_updated) {
			shark = candi;
			++shark_eat;
			if (shark_eat == shark_size) {
				shark_eat = 0;
				shark_size += 1;
			}
			map[shark.y][shark.x] = 0;
		}
	}

	//첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.
	cout << shark.time << "\n";

	return 0;
}