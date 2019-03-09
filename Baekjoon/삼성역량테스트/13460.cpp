//  [시뮬레이션 + BFS]
#include <iostream>
#include <queue>
using namespace std;

// 15. '.'은 빈 칸, '#'은 장애물, 'O'는 구멍의 위치, 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.
struct INFO{
    int ry, rx, by, bx, cnt;
};

INFO start;

//  2. 보드의 세로 크기는 N, 가로 크기는 M이다. 
int N, M;
char board[10][11];
int visited[10][10][10][10];

//  6. 구슬을 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽, 오른쪽, 위쪽, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };

int BFS(){
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    
    int ret = -1;
    while(!q.empty()){
        INFO cur = q.front();   q.pop();

        // 18. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.
        if(cur.cnt > 10)    break;

        //  1. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.
        //  5. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안된다.
        //  9. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 
        if(board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O'){
            ret = cur.cnt;
            break;
        }

        for(int dir = 0; dir < 4; ++dir){
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;
            
            //  7. 각각의 동작에서 공은 동시에 움직인다. 
            // 11. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
            while(1){
                if(board[next_ry][next_rx] != '#' && board[next_ry][next_rx] != 'O'){
                    next_ry += dy[dir], next_rx += dx[dir];
                }else{
                    if(board[next_ry][next_rx] == '#'){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            //  7. 각각의 동작에서 공은 동시에 움직인다. 
            // 11. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
            while(1){
                if(board[next_by][next_bx] != '#' && board[next_by][next_bx] != 'O'){
                    next_by += dy[dir], next_bx += dx[dir];
                }else{
                    if(board[next_by][next_bx] == '#'){
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            // 10. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
            if(next_ry == next_by && next_rx == next_bx){
                //  8. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
                if(board[next_ry][next_rx] != 'O'){
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if(red_dist > blue_dist){
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }else{
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }
            
            if(visited[next_ry][next_rx][next_by][next_bx] == 0){
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.cnt = cur.cnt + 1;
                q.push(next);
            }
        }
    }

    // 17. 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다.
    return ret;
}


// 12. 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    // 13. 첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 
    cin >> N >> M;

    //  3. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
    //  4. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 
    // 14. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다.
    //     이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. 
    // 16. 입력되는 모든 보드의 가장자리에는 모두 '#'이 있다.
    //     구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.
    for(int y = 0; y < N; ++y){
        cin >> board[y];
    }

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < M; ++x){
            if(board[y][x] == 'R'){
                start.ry = y,   start.rx = x;
            }else if(board[y][x] == 'B'){
                start.by = y,   start.bx = x;
            }
        }
    }
    start.cnt = 0;

    int ret = BFS();

    cout << ret << "\n";
    return 0;
}