// [시뮬레이션 + BFS]
// 1. 한 번의 이동은 상하좌우의 움직임이다.
// 2. 같은 값의 블록은 충돌하면 합친다.
// 3. 이미 합친 블록은 또 다른 블록과 합칠 수 없다.
// 4. 블록은 추가 되지 않는다.
// 5. 똑같은 수가 여러개 있다면 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
// 6. 최대 5번 이동해서 얻을 수 있는 가장 큰 블록의 값을 구하여라.

#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cmath>

// 1. 상하좌우의 움직임
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

using namespace std;

int board[20][20];
int n;
int ans = INT_MIN;

// 6. 가장 큰 블록의 값을 구하여라
int FindMax(){
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            ans = max(ans, board[y][x]);
        }
    }
    return ans;
}

void Change(int direction){
    queue<int> q;

    // 4가지 방향
    switch(direction){
        case UP:
            for(int x = 0; x < n; ++x){
                for(int y = 0; y < n; ++y){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);    // 값을 저장한다.
                        board[y][x] = 0;
                    }
                }

                // 5. 똑같은 수가 여러개 있다면 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                int idx = 0;
                while(!q.empty()){
                    int block = q.front();
                    q.pop();
                    
                    // 5. 똑같은 수가 여러개 있다면 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                    if(board[idx][x] == 0){
                        board[idx][x] = block;
                    }else if(board[idx][x] == block){
                        // 2. 같은 값의 블록은 충돌하면 합친다.
                        board[idx][x] *= 2;
                        ++idx;
                    }else{
                        // 3. 이미 합친 블록은 또 다른 블록과 합칠 수 없다.
                        board[++idx][x] = block;
                    }
                }
            }
            break;
        case DOWN:
            for(int x = 0; x < n; ++x){
                for(int y = n - 1; y >= 0; --y){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = n - 1;
                while(!q.empty()){
                    int block = q.front();
                    q.pop();
                    
                    if(board[idx][x] == 0){
                        board[idx][x] = block;
                    }else if(board[idx][x] == block){
                        board[idx][x] *= 2;
                        --idx;
                    }else{
                        board[--idx][x] = block;
                    }
                }
            }
            break;
        case LEFT:
            for(int y = 0; y < n; ++y){
                for(int x = 0; x < n; ++x){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = 0;
                while(!q.empty()){
                    int block = q.front();
                    q.pop();

                    if(board[y][idx] == 0){
                        board[y][idx] = block;
                    }else if(board[y][idx] == block){
                        board[y][idx] *= 2;
                        ++idx;
                    }else{
                        board[y][++idx] = block;
                    }
                }
            }
            break;
        case RIGHT:
            for(int y = 0; y < n; ++y){
                for(int x = n - 1; x >= 0; --x){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = n - 1;
                while(!q.empty()){
                    int block = q.front();
                    q.pop();

                    if(board[y][idx] == 0){
                        board[y][idx] = block;
                    }else if(board[y][idx] == block){
                        board[y][idx] *= 2;
                        --idx;
                    }else{
                        board[y][--idx] = block;
                    }
                }
            }
            break;
    }
}

void DFS(int depth){
    // 6. 최대 5번 이용하여 가장 큰 블록의 값을 구하여라
    if(depth == 5){
        ans = max(ans, FindMax());
        return;
    }

    int temp[20][20];

    // 현재의 상황을 temp에 저장하자
    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            temp[y][x] = board[y][x];
        }
    }

    // 상하좌우 한번씩 움직인다.
    for(int dir = 0; dir < 4; ++dir){
        // 상하좌우 한번씩 움직인다.
        Change(dir);
        // 움직인 횟수는 증가한다.
        DFS(depth + 1);
        // 움직이기 전 상태로 돌아온다.
        for(int y = 0; y < n; ++y){
            for(int x = 0; x < n; ++x){
                board[y][x] = temp[y][x];
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cin.tie(NULL);

    cin >> n;

    for(int y = 0; y < n; ++y){
        for(int x = 0; x < n; ++x){
            cin >> board[y][x];
        }
    }
    DFS(0);

    cout << ans << "\n";

    return 0;
}