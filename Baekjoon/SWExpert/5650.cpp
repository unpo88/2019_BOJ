#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int map[101][101];

// 우 하 좌 상
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int answer;

vector<pair<int,int> > hole[5];
vector<pair<int, int> > start;

int start_y, start_x;

int checkDir(int block, int dir) {
    if(block == 1){
        if(dir == 0)    return 2;
        if(dir == 1)    return 0;
        if(dir == 2)    return 3;
        if(dir == 3)    return 1;
    }else if(block == 2){
        if(dir == 0)    return 2;
        if(dir == 1)    return 3;
        if(dir == 2)    return 1;
        if(dir == 3)    return 0;
    }else if(block == 3){
        if(dir == 0)    return 1;
        if(dir == 1)    return 3;
        if(dir == 2)    return 0;
        if(dir == 3)    return 2;
    }else if(block == 4){
        if(dir == 0)    return 3;
        if(dir == 1)    return 2;
        if(dir == 2)    return 0;
        if(dir == 3)    return 1;
    }else if(block == 5){
        if(dir == 0)    return 2;
        if(dir == 1)    return 3;
        if(dir == 2)    return 0;
        if(dir == 3)    return 1;
    }
    return dir;
}

void DFS(int y, int x, int dir, int score) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
 
    //벽만나면 (n*2)+1
    if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
        int s = (score * 2) + 1;
        if (answer < s) answer = s;
        return;
    }
    //있던 곳 되돌아오기
    else if (ny == start_x && nx == start_y) {
        if (answer < score) answer = score;
        return;
    }
    //방향 유지 다음 DFS
    else if (map[ny][nx] == 0) {
        DFS(ny, nx, dir, score);
    }
    //블록, 점수 획득, 방향 바꾸기
    else if (map[ny][nx] > 0 && map[ny][nx] < 6) {
        dir = checkDir(map[ny][nx], dir);
        DFS(ny, nx, dir, score + 1);
    }
    //웜홀, 좌표바꿔서 다음턴
    else if (map[ny][nx] > 5 && map[ny][nx] < 11) {
        int _y = hole[map[ny][nx]-6].at(0).first;
        int _x = hole[map[ny][nx]-6].at(0).second;
        if (_y == ny && _x == nx) {
            _y = hole[map[ny][nx]-6].at(1).first;
            _x = hole[map[ny][nx]-6].at(1).second;
        }
        DFS(_y, _x, dir, score);
    }
    //블랙홀
    else if (map[ny][nx] == -1) {
        if (answer < score) answer = score;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        answer = 0;

        for (int i = 0; i < 5; i++) {
            hole[i].clear();
        }
        start.clear();

        cin >> N;

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                cin >> map[y][x];
                //웜홀
                if(map[y][x] >= 6 && map[y][x] <= 10){
                    int num = map[y][x] - 6;
                    hole[num].push_back(make_pair(y, x));
                }
            }
        }

        for (int i = 0; i < start.size(); i++) {
            for(int dir = 0; dir < 4; ++dir){
                start_x = start[i].first;
                start_y = start[i].second;
                DFS(start_x, start_y, dir, 0);
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}