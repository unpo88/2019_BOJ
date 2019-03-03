// [시뮬레이션 문제]
// 1. 사과를 먹으면 뱀의 길이가 늘어난다.
// 2. 벽 또는 자기 자신의 몸과 부딪치면 게임은 끝난다.
// 3. 몇몇 칸에는 사과가 있을 수 있다.
// 4. 보드의 상하좌우 끝에 벽이 있다.
// 5. 뱀은 맨위 맨좌측에서 시작한다. 뱀의 길이는 1이다.
// 6. 맨위 맨좌측에는 사과가 없다.
// 7. 뱀의 첫 시작은 오른쪽을 향한다.
// 8. 뱀은 몸 길이를 늘려서 머리를 다음칸에 위치시킨다.
// 9. 이동한 칸에 사과가 있으면 사과가 없어지고, 꼬리는 움직이지 않는다.
// 10. 이동한 칸에 사과가 없으면 몸길이를 줄여서 꼬리가 위치한 칸을 비운다. 즉, 몸 길이는 변하지 않는다.
// 11. 사과의 위치와 뱀의 이동경로가 주어질 대 이 게임은 몇 초에 끝나는지 구하시오. 

#include <iostream>
using namespace std;

// 보드 크기, 사과 개수, 방향 변환 횟수
int n, k, m;

// 보드 크기
int map[101][101];

// 머리, 꼬리 인덱스
int head_y, head_x, tail_index;

// 뱀의 좌표
int snake_y[10101], snake_x[10101];

// 명령어
char cmd[10001];

// 오른쪽 아래 왼쪽 위
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> k;

	int y, x;
	for (int i = 0; i < k; ++i) {
		cin >> y >> x;
		map[y][x] = 1;
	}

	int time;
	char c;

	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> time >> c;
		cmd[time] = c;
	}

	int dir = 0;

	// 처음 시간은 0
	time = 0;

	// 최초 위치는 맨 왼쪽 맨 위, 인덱스는 시간과 같음
	head_y = 1, head_x = 1, tail_index = time;

	// 좌표를 저장
	snake_y[time] = head_y, snake_x[time] = head_x;
	
	// 뱀이 있을 때는 -1
	map[head_y][head_x] = -1;

	// 시간은 계속 지나가기 때문에 무한루프
	while (1) {
		++time;

		// 뱀이 이동경로대로 계속해서 움직인다.
		head_y += dy[dir];
		head_x += dx[dir];

		// 다음 조건이면 무조건 끝남 범위를 벗어나거나 자기 자신을 만나거나
		if (head_y < 1 || head_y > n || head_x < 1 || head_x > n || map[head_y][head_x] == -1) {
			break;
		}

		// 시간마다 좌표를 저장
		snake_y[time] = head_y;
		snake_x[time] = head_x;

		// 만약에 사과가 없다면, 뱀의 꼬리를 한칸 줄여준다.
		if (map[head_y][head_x] == 0) {
			int tail_y = snake_y[tail_index];
			int tail_x = snake_x[tail_index];
			map[tail_y][tail_x] = 0;	// 꼬리를 줄여줬기 때문에 0으로 바꾼다. -1을 0으로 바꾸어줌
			++tail_index;
		}
		// 뱀의 머리가 위치한 곳에 -1
		map[head_y][head_x] = -1;

		// 오른쪽 그리고 왼쪽으로 회전할 때
		if (cmd[time] == 'D') {
			dir = (dir + 1) % 4;
		}

		if (cmd[time] == 'L') {
			dir = (dir + 3) % 4;
		}
	}

	cout << time << "\n";

	return 0;
}