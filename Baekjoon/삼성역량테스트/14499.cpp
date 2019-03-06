// [시뮬레이션]
// 1. 크기는 N*M(세로 : N, 가로 : M)
// 2. 동서남북

// 3. 주사위 전개도
//    2
//	4 1 3
//	  5
//	  6

// 4. 윗 면이 1이고, 동쪽을 바라보는 방향이 3인 상태로 놓여져 있다. 좌표는 (x, y)
// 5. 가장 처음에 주사위는 모든 면에 0이 적혀져 있다.
// 6. 지도의 각 칸에는 정수가 하나씩 쓰여져 있다.
// 7. 주사위를 굴렸을 때 이동한 칸에 쓰여 있는 수가 0이면 주사위 바닥면에 쓰여 있는 수가 칸에 복사된다.
// 8. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
// 9. 주사위는 지도의 바깥으로 이동시킬 수 없다. 바깥 이동시 명령을 무시하며 출력을 안한다.
// 10. 1 <= N, M <= 20 
// 11. 0 <= x <= N-1, 0 <= y <= M-1
// 12. 1 <= K <= 1,000
// 13. N개의 줄에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다.
// 14. 주사위를 놓은 칸에 쓰여 있는 수는 항상 0이다. 지도의 각 칸에 쓰여 있는 수는 10을 넘지 않는 자연수이다.
// 15. 마지막 줄에는 이동하는 명령이 순서대로 주어진다.
// 16. 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
// 17. 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안된다.

#include <iostream>
using namespace std;

int board[20][20];

// N, x : row			M, y : col
int N, M, x, y, K;

// 마지막이 바닥면
// 5. 가장 처음에 주사위는 모든 면에 0이 적혀져 있다.
int dice[7];

// 16. 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4로 주어진다.
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };

void print_all() {
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			cout << board[row][col];
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	cin >> N >> M >> x >> y >> K;

	// 6. 지도의 각 칸에는 정수가 하나씩 쓰여져 있다.
	// 13. N개의 줄에 쓰여 있는 수가 북쪽부터 남쪽으로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다.
	for (int row = 0; row < N; ++row) {
		for (int col = 0; col < M; ++col) {
			cin >> board[row][col];
		}
	}

	// 15. 마지막 줄에는 이동하는 명령이 순서대로 주어진다.
	while (K--) {
		int c;
		cin >> c;

		c -= 1;

		int next_x = x + dx[c];
		int next_y = y + dy[c];
		int temp;

		// 9. 주사위는 지도의 바깥으로 이동시킬 수 없다. 바깥 이동시 명령을 무시하며 출력을 안한다.
		if (next_x >= N || next_y >= M || next_x < 0 || next_y < 0)	continue;

		if (c == 0) {
			temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		else if (c == 1) {
			temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
		else if (c == 2) {
			temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}else{
			temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}

		// 8. 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
		if (board[next_x][next_y] == 0) {
			board[next_x][next_y] = dice[6];
		}
		// 7. 주사위를 굴렸을 때 이동한 칸에 쓰여 있는 수가 0이면 주사위 바닥면에 쓰여 있는 수가 칸에 복사된다.
		else {
			dice[6] = board[next_x][next_y];
			board[next_x][next_y] = 0;
		}
		x = next_x;
		y = next_y;

		// 17. 이동할 때마다 주사위의 윗 면에 쓰여 있는 수를 출력한다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안된다.
		cout << dice[1] << "\n";
	}
	return 0;
}