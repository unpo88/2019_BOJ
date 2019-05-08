#include <iostream>
#include <queue>
using namespace std;

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

int N, M, R, C, L;

int map[50][50];
bool visited[50][50];

// 오른쪽, 왼쪽, 아래, 위
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void init(){
    for(int y = 0; y < 50; ++y){
        for(int x = 0; x < 50; ++x){
            map[y][x] = 0;
            visited[y][x] = false;
        }
    }
}


bool check(int y, int x, int ny, int nx, int direction){
    bool flag = false;
    switch(direction){
        case RIGHT:
            if((map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5)
            && (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7)){
                flag = true;
            }
            break;

        case LEFT:
            if((map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7)
            && (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5)){
                flag = true;
            }
            break;

        case DOWN:
            if((map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6)
            && (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7)){
                flag = true;
            }
            break;

        case UP:
            if((map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7)
            && (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6)){
                flag = true;
            }
            break;
    }
    return flag;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){

        init();

        cin >> N >> M >> R >> C >> L;

        int answer = 0;
        queue<pair<int, int> > q;


        q.push(make_pair(R, C));
        visited[R][C] = true;

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                cin >> map[y][x];
            }
        }

        while(--L){
            int q_size = q.size();
            while(q_size--){
                int cur_y = q.front().first;
                int cur_x = q.front().second;
                q.pop();

                for(int dir = 0; dir < 4; ++dir){
                    int ny = cur_y + dy[dir];
                    int nx = cur_x + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= N || nx >= M)  continue;
                    if(check(cur_y, cur_x, ny, nx, dir) && !visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                if(visited[y][x]){
                    answer++;
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}