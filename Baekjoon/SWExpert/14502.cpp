#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;

int map[8][8];

int BFS(){
    queue<pair<int, int> > q;

    int temp_map[8][8];

    const int dy[] = { 0, 0, 1, -1 };
    const int dx[] = { 1, -1, 0, 0 };

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            temp_map[y][x] = map[y][x];
            if(temp_map[y][x] == 2){
                q.push(make_pair(y, x));
            }
        }
    }
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; ++dir){
            int next_y = y + dy[dir];
            int next_x = x + dx[dir];
            if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)    continue;
            if(temp_map[next_y][next_x] == 0){
                temp_map[next_y][next_x] = 2;
                q.push(make_pair(next_y, next_x));
            }
        }
    }

    int cnt = 0;
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            if(temp_map[y][x] == 0){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int answer = 0;

    cin >> N >> M;

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            cin >> map[y][x];
        }
    }

    for(int y1 = 0; y1 < N; ++y1){
        for(int x1 = 0; x1 < M; ++x1){
            if(map[y1][x1] != 0)    continue;
            for(int y2 = 0; y2 < N; ++y2){
                for(int x2 = 0; x2 < M; ++x2){
                    if(map[y2][x2] != 0)    continue;
                    for(int y3 = 0; y3 < N; ++y3){
                        for(int x3 = 0; x3 < M; ++x3){
                            if(map[y3][x3] != 0)    continue;
                            if(y1 == y2 && x1 == x2)    continue;
                            if(y2 == y3 && x2 == x3)    continue;
                            if(y1 == y3 && x1 == x3)    continue;
                            map[y1][x1] = map[y2][x2] = map[y3][x3] = 1;
                            answer = max(answer, BFS());
                            map[y1][x1] = map[y2][x2] = map[y3][x3] = 0;                            
                        }
                    }
                }
            }
        }
    }

    cout << answer << "\n";

    return 0;
}