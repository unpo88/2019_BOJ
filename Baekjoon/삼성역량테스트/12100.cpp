// [시뮬레이션 + DFS]
#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// 5. 이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다.
int N;
int board[20][20];

int ret = INT_MIN;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };

//  6. 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
int FindMax(){
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            ret = max(ret, board[y][x]);
        }
    }
    return ret;
}

void Change(int direction){
    queue<int> q;
    
    switch(direction){
        case UP:
            for(int x = 0; x < N; ++x){
                for(int y = 0; y < N; ++y){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = 0;
                while(!q.empty()){
                    int block = q.front();  q.pop();
                    
                    //  4. 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                    if(board[idx][x] == 0){
                        board[idx][x] = block;
                    //  2. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
                    }else if(board[idx][x] == block){
                        board[idx][x] *= 2;
                        ++idx;
                    //  3. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
                    }else{
                        board[++idx][x] = block;
                    }
                }
            }
            break;
        case DOWN:
            for(int x = 0; x < N; ++x){
                for(int y = N - 1; y >= 0; --y){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = N - 1;
                while(!q.empty()){
                    int block = q.front();  q.pop();
                    
                    //  4. 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                    if(board[idx][x] == 0){
                        board[idx][x] = block;
                    //  2. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
                    }else if(board[idx][x] == block){
                        board[idx][x] *= 2;
                        --idx;
                    //  3. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
                    }else{
                        board[--idx][x] = block;
                    }
                }
            }
            break;
        case LEFT:
            for(int y = 0; y < N; ++y){
                for(int x = 0; x < N; ++x){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = 0;
                while(!q.empty()){
                    int block = q.front();  q.pop();
                    
                    //  4. 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                    if(board[y][idx] == 0){
                        board[y][idx]= block;
                    //  2. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
                    }else if(board[y][idx] == block){
                        board[y][idx] *= 2;
                        ++idx;
                    //  3. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
                    }else{
                        board[y][++idx] = block;
                    }
                }
            }
            break;
        case RIGHT:
            for(int y = 0; y < N; ++y){
                for(int x = N - 1; x >= 0; --x){
                    if(board[y][x] != 0){
                        q.push(board[y][x]);
                        board[y][x] = 0;
                    }
                }

                int idx = N - 1;
                while(!q.empty()){
                    int block = q.front();  q.pop();
                    
                    //  4. 똑같은 수가 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
                    if(board[y][idx] == 0){
                        board[y][idx]= block;
                    //  2. 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
                    }else if(board[y][idx] == block){
                        board[y][idx] *= 2;
                        --idx;
                    //  3. 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다.
                    }else{
                        board[y][--idx] = block;
                    }
                }
            }
            break;
    }
}

void DFS(int depth){
    //  6. 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
    // 11. 최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.
    if(depth == 5){
        ret = max(ret, FindMax());
        return ;
    }

    // 현재의 상황을 temp에 저장하자
    int temp_board[20][20];
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            temp_board[y][x] = board[y][x];
        }
    }
    //  1. 이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다. 
    for(int dir = 0; dir < 4; ++dir){
        // 상하좌우 한번씩 움직인다.
        Change(dir);
        // 움직인 횟수는 증가한다.
        DFS(depth + 1);
        // 움직이기 전 상태로 돌아온다.
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                board[y][x] = temp_board[y][x];
            }
        }
    }
}

int main(){
    //  7. 첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다.
    cin >> N;

    //  8. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다.
    //  9. 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 
    // 10. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다.
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            cin >> board[y][x];
        }
    }

    DFS(0);

    cout << ret << "\n";
    return 0;
}