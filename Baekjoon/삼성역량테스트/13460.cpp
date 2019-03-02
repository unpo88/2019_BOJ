// [시뮬레이션 + BFS]
// 1. 빨간 구슬은 통과해야하고 파란 구슬은 통과하면 안된다.
// 2. 왼쪽 오른쪽 위 아래 4가지 방향으로 굴린다(중력)
// 3. 구슬은 동시에 움직인다.
// 4. 빨간구슬 파란구슬이 동시에 통과해도 탈락
// 5. 빨간구슬과 파란구슬이 같은 위치에 있을 수 없다.
// 6. 구슬이 움직이지 않을 때 까지 기울인다.
// 7. 최소 몇 번 움직여야 빨간 구슬이 통과하는가?
// 8. 10번 이하로 빨간 구슬을 빼지 못하면 -1을 출력한다.
// 9. 간 방향의 반대 방향으로 다시 갈 필요는 없다. (visit)
// 10. Big O를 계산해보자. 2^20

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// map 크기
char map[10][11];

class INFO{
public:
    int ry, rx, by, bx, count;
    INFO()  {};
    INFO(int _ry, int _rx, int _by, int _bx, int _count):
        ry(_ry), rx(_rx), by(_by), bx(_bx), count(_count)   {};
};

INFO start;

// 7. 최소 몇 번 움직여야하는가? BFS
int BFS(){
    // 2. 왼쪽 오른쪽 위 아래 선언
    const int dy[] = { 0, 0, -1, 1 };
    const int dx[] = { -1, 1, 0, 0 };

    // 방문 체크 배열
    int visited[10][10][10][10] = { 0, };

    queue<INFO> q;
    // 첫 시작은 방문했지요
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    q.push(start);

    int ret = -1;
    while(!q.empty()){
        INFO cur = q.front();   q.pop();
        
        // 8. 10번 이상이면 그냥 -1을 출력
        if(cur.count > 10)  break;

        // 1. 명확한 조건을 만족하는 경우에 최소 count를 대입하고 출력
        if(map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O'){
            ret = cur.count;
            break;
        }

        // 왼쪽, 오른쪽, 위, 아래 4가지 방향에 대해서 계속해서 찾아보는 알고리즘
        for(int dir = 0; dir < 4; ++dir){
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            // 3. 구슬은 동시에 움직인다.
            // 2. 한쪽 방향으로 기울임(중력)
            // 벽을 만나면 한 칸 줄어야겠지요?
            while(1){
                // 6. 구슬이 움직이지 않을 때 가지 기울인다.
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_ry += dy[dir], next_rx += dx[dir];
                }else{
                    if(map[next_ry][next_rx] == '#'){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            // 2. 한쪽 방향으로 기울임(파란구슬)
            // 벽을 만나면 한 칸 줄어야겠지요?
            while(1){
                // 6. 구슬이 움직이지 않을 때 가지 기울인다.
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_by += dy[dir], next_bx += dx[dir];
                }else{
                    if(map[next_by][next_bx] == '#'){
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            // 5. 동시에 같은 칸에 있으면 안된다.
            // 거리를 계산해서 문제를 간단히 해결
            if(next_ry == next_by && next_rx == next_bx){
                // 4. 파란구슬도 같이 빠지면 안됌
                if(map[next_by][next_bx] != 'O'){
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if(red_dist > blue_dist){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }else{
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }
            
            // 9. 간 방향의 반대방향으로 갈 필요 없다.(방문 안한곳으로 가자)
            if(visited[next_ry][next_rx][next_by][next_bx] == 0){
                INFO next;
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);   // BFS 핵심
            }
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i){
        cin >> map[i];
    }

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            if(map[y][x] == 'R'){
                start.ry = y, start.rx = x;
            }else if(map[y][x] == 'B'){
                start.by = y, start.bx = x;
            }
        }
    }
    start.count = 0;

    int ret = BFS();

    cout << ret << "\n";

    return 0;
}