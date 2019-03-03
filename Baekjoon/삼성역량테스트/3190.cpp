// [시뮬레이션 문제]
// 1. 사과를 먹으면 뱀의 길이가 늘어난다.
// 2. 벽 또는 자기 자신의 몸과 부딪치면 게임은 끝난다.
// 3. 몇몇 칸에는 사과가 있을 수 있다.
// 4. 보드의 상하좌우 끝에 벽이 있다.
// 5. 뱀은 맨위 맨좌측에서 시작한다. 뱀의 길이는 1이다.
// 6. 맨위 맨좌측에는 사과가 없다.
// 7. 뱀의 첫 시작은 오른쪽을 향한다.
// 8. 뱀은 몸 길이를 늘려서 머리를 다음칸에 위치시킨다.
// 9. 이동한 칸에 사과가 있으면 사과가 없어지고, 꼬리는 움직이지 않는다.
// 10. 이동한 칸에 사과가 없으면 몸길이를 줄여서 꼬리가 위치한 칸을 비운다. 즉, 몸 길이는 변하지 않는다.
// 11. 사과의 위치와 뱀의 이동경로가 주어질 대 이 게임은 몇 초에 끝나는지 구하시오.
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 100

// 오른쪽, 아래, 왼쪽, 위
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

// 사과 위치
bool apple[MAX_SIZE][MAX_SIZE] = { false, };

// 지도
int board[MAX_SIZE][MAX_SIZE];

// 크기
int N;

// 사과 개수
int K;

// 명령어 개수
int L;

// 명령어 형태
// 초, (왼, 오)
int M;
char ch;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    cin >> N;
    cin >> K;
    while(K--){
        int y, x;
        cin >> y >> x;
        apple[y - 1][x - 1] = true;
    }

    memset(board, -1, sizeof(board));

    int x = 0;
    int y = 0;
    int dir = 0;
    int len = 1;
    board[y][x] = 0;
    cin >> L;
    int now = 0;
    

    for(int k = 0; k <= L; k++){
        M = N * N + 1;
        ch = 'L';
        if(k < L){
            cin >> M >> ch;
        }
        while(now < M){
            now += 1;
            x += dx[dir];
            y += dy[dir];
            if(x < 0 || x >= N || y < 0 || y >= N){
                cout << now << '\n';
                return 0;
            }
            if(apple[y][x]){
                apple[y][x] = false;
                len += 1;
            }
            if(board[y][x] != -1 && now - board[y][x] <= len){
                cout << now << '\n';
                return 0;
            }
            board[y][x] = now;
        }
        if(ch == 'L'){
            dir = (dir + 3) % 4;
        }else{
            dir = (dir + 1) % 4;
        }
    }
    return 0;
}