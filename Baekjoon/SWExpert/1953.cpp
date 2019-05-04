#include <iostream>
#include <queue>
using namespace std;

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

int check(int direction, int y, int x, int ny, int nx, int map[][50]){
    int flag = false;
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
        int N, M, R, C, L;
        int map[50][50];
        int time_map[50][50] = { 0, };

        // 오른쪽, 왼쪽, 아래, 위
        const int dy[] = { 0, 0, 1, -1 };
        const int dx[] = { 1, -1, 0, 0 };

        int answer = 0;
        queue<pair<int, int> > q;

        cin >> N >> M >> R >> C >> L;
        q.push(make_pair(R, C));
        time_map[R][C] = 1;

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                cin >> map[y][x];
            }
        }

        while(--L){
            int q_size = q.size();
            while(q_size--){
                int y = q.front().first;
                int x = q.front().second;
                q.pop();
                
                for(int dir = 0; dir < 4; ++dir){
                    int next_y = y + dy[dir];
                    int next_x = x + dx[dir];
                    if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)  continue;
                    if(check(dir, y, x, next_y, next_x, map) && !time_map[next_y][next_x]){
                        time_map[next_y][next_x] = 1;
                        q.push(make_pair(next_y, next_x));
                    }
                }
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                if(time_map[y][x]){
                    answer++;
                }
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}