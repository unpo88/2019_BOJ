#include <iostream>
#include <queue>
using namespace std;

struct SHARK{
    int y, x, time;
};

// N*N 크기의 공간
int N;

// N*N크기의 공간
int map[21][21];

// 상어 사이즈, 먹은 수
int shark_size, shark_eat;

// 상어
SHARK shark;

// 인접한 4칸
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);
    
    // 첫째 줄에 공간의 크기 N(2 <= N <= 20)이 주어진다.
    cin >> N;

    // 둘째 줄부터 N개의 줄에 공간의 상태가 주어진다.
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            cin >> map[y][x];
            if(map[y][x] == 9){
                shark.y = y,    shark.x = x,    shark.time = 0;
                shark_size = 2, shark_eat = 0;
                map[y][x] = 0;
            }
        }
    }

    bool is_update = true;
    while(is_update){
        is_update = false;

        bool visited[21][21] = { false, };
        queue<SHARK> q;
        visited[shark.y][shark.x] = true;
        q.push(shark);

        SHARK candi;
        candi.y = 20,   candi.time = -1;
        while(!q.empty()){
            SHARK cur = q.front();  q.pop();

            if(candi.time != -1 && candi.time < cur.time)   break;

            if(map[cur.y][cur.x] < shark_size && map[cur.y][cur.x] != 0){
                is_update = true;
                if(candi.y > cur.y || (candi.y == cur.y && candi.x > cur.x)){
                    candi = cur;
                }
            }

            for(int dir = 0; dir < 4; ++dir){
                SHARK next;
                next.y = cur.y + dy[dir],   next.x = cur.x + dx[dir],   next.time = cur.time + 1;

                if(next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)  continue;

                if(visited[next.y][next.x] == false && shark_size >= map[next.y][next.x]){
                    visited[next.y][next.x] = true;
                    q.push(next);
                }
            }
        }

        if(is_update){
            shark = candi;
            ++shark_eat;
            if(shark_eat == shark_size){
                ++shark_size;
                shark_eat = 0;
            }
            map[shark.y][shark.x] = 0;
        }
    }

    cout << shark.time << "\n";
    return 0;
}