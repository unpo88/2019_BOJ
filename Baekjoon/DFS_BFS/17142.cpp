#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;

int map[51][51];
int copy_map[51][51];

bool check[51] = { false, };

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

vector<pair<int, int> > v;
queue<pair<int, int> > q;

int answer = INT_MAX;

int answer_check(){
    int max_time = 0;
    bool isClear = true;
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            if(map[y][x] == 0){
                // 만약 빈 칸인데 바이러스가 퍼지지 않았으면 실패
                if(copy_map[y][x] == -1){
                    isClear = false;
                    break;
                }else{
                    max_time = max(max_time, copy_map[y][x]);
                }
            }
        }
        if(!isClear)    break;
    }
    if(isClear){
        return max_time;
    }else{
        return INT_MAX;
    }
}

void DFS(int idx, int cnt) {
	if (cnt > M)	return;

	if (cnt == M) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < N; ++x) {
                copy_map[y][x] = -1;
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
			q.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int next_y = y + dy[dir];
				int next_x = x + dx[dir];
				if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= N)	continue;
                if(map[next_y][next_x] != 1 && copy_map[next_y][next_x] == -1){
					copy_map[next_y][next_x] = copy_map[y][x] + 1;
					q.push(make_pair(next_y, next_x));
				}
			}
		}

        answer = min(answer, answer_check());
	}

	for (int i = idx; i < v.size(); ++i) {
		check[i] = true;
		DFS(i + 1, cnt + 1);
		check[i] = false;
	}
}
//연구소의 상태가 주어졌을 때, 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간을 구해보자.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	//첫째 줄에 연구소의 크기 N(5 ≤ N ≤ 50), 놓을 수 있는 바이러스의 개수 M(2 ≤ M ≤ 10)이 주어진다.
	cin >> N >> M;
	//둘째 줄부터 N개의 줄에 연구소의 상태가 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스를 놓을 수 있는 위치이다. 2의 개수는 M보다 크거나 같고, 10보다 작거나 같은 자연수이다.
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				v.push_back(make_pair(y, x));
			}
		}
	}

	DFS(0, 0);

	//연구소의 모든 빈 칸에 바이러스가 있게 되는 최소 시간을 출력한다.
	//바이러스를 어떻게 놓아도 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우에는 - 1을 출력한다.

    if(answer == INT_MAX){
        answer = -1;
    }

    cout << answer << "\n";

	return 0;
}