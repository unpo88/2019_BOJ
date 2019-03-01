#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char map[10][11];

class INFO{
public:
    int ry, rx, by, bx, count;
    INFO() {};
    INFO(int _ry, int _rx, int _by, int _bx, int _count):
        ry(_ry), rx(_rx), by(_by), bx(_bx)  {};
};

INFO start;

int BFS(){
    const int dx[] = { 0, 0, 1, -1 };
    const int dy[] = { 1, -1, 0, 0 };
    
    int visit[10][10][10][10] = { 0, };
    queue<INFO> q;
    visit[start.ry][start.rx][start.by][start.bx] = 1;
    q.push(start);

    int ret = -1;
    while(!q.empty()){
        INFO cur = q.front();   q.pop();
        
        // 4 최대 10번 까지만
        if(cur.count > 10)  break;

        // 1 빨간 구슬은 빠지고 파란 구슬은 빠지면 안된다. 이 경우에만 정답을 출력 나머지는 -1
        if(map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O'){
            ret = cur.count;
            break;
        }

        // 4방향 계속 탐색할거야
        for(int dir = 0; dir < 4; ++dir){
            int next_rx = cur.rx;
            int next_ry = cur.ry;
            int next_bx = cur.bx;
            int next_by = cur.by;

            //  5 한쪽 방향 끝까지 간다.
            while(1){
                if(map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O'){
                    next_ry += dy[dir], next_rx += dx[dir];
                }else{
                    if(map[next_ry][next_rx] == '#'){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            // 5 한쪽 방향으로 끝까지 간다. 벽을 만나면 한칸 뒤로 빠꾸, 골인 지점은 다른 코드에서 검사
            while(1){
                if(map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O'){
                    next_by += dy[dir], next_bx += dx[dir];
                }else{
                    if(map[next_by][next_bx] == '#'){
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            if(next_rx == next_bx && next_ry == next_by){
                // 3 둘다 동시에 빠지면 안되기 때문에 이 조건을 여기다 적용
                if(map[next_by][next_bx] != 'O'){
                    // 2 두 구슬이 같은 위치에 있을 수 없는 것을 적용
                    int red_dist = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
                    int blue_dist = abs(next_bx - cur.bx) + abs(next_by - cur.by);
                    if(red_dist > blue_dist){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }else{
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }
            
            // 6. 한번도 방문을 안한 녀석이여야 함
            if(visit[next_ry][next_rx][next_by][next_bx] == 0){
                INFO next;
                visit[next_ry][next_rx][next_by][next_bx] = 1;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
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

    for(int i = 0; i < N; i++){
        cin >> map[i];
    }

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            if(map[y][x] == 'R'){
                start.ry = y;
                start.rx = x;
            }else if(map[y][x] == 'B'){
                start.by = y;
                start.bx = x;
            }
        }
    }
    start.count = 0;

    int ret = BFS();

    cout << ret << "\n";

    return 0;
}