// [시뮬레이션]
#include <iostream>
using namespace std;

//  1. 게임은 NxN 정사각 보드위에서 진행된다.
int N;
int board[101][101];

//  2. 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다.
int K;

//  9. 다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
int L;

// 10. 다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며.
int X, C;

int snake_y[10101], snake_x[10101];
char cmd[10001];

//  3. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.
int t = 0;
int head_y = 1, head_x = 1, tail_index = t;
int dir = 0;

//     X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //  5. 첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 
    cin >> N;
    
    //  6. 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)
    cin >> K;

    //  7. 다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 
    //  8. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.
    while(K--){
        int y, x;
        cin >> y >> x;
        board[y][x] = 1;
    }

    //  9. 다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)
    cin >> L;

    // 10. 다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며.
    //     X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
    //     X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.
    for(int i = 0; i < L; ++i){
        cin >> X;
        cin >> cmd[X];
    }

    //  3. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.
    snake_y[t] = head_y, snake_x[t] = head_x;
    board[snake_y[t]][snake_x[t]] = -1;


    //  4. 뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.
    while(1){
        // 매 초 증가
        ++t;
        //      4-1. 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
        head_y += dy[dir],  head_x += dx[dir];
        
        // 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
        if(board[head_y][head_x] == -1 || head_y < 1 || head_x < 1 || head_y > N || head_x > N){
            break;
        }

        // 시간마다 좌표를 저장
        snake_y[t] = head_y,    snake_x[t] = head_x;

        //      4-3. 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
        if(board[snake_y[t]][snake_x[t]] == 0){
            int tail_y = snake_y[tail_index];
            int tail_x = snake_x[tail_index];
            board[tail_y][tail_x] = 0;
            ++tail_index;
        }

        //      4-2. 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
        board[head_y][head_x] = -1;

        //     X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. 
        if(cmd[t] == 'D'){
            dir = (dir + 1) % 4;
        }

        if(cmd[t] == 'L'){
            dir = (dir + 3) % 4;
        }
    }

    //      4-4. 사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.
    // 11. 첫째 줄에 게임이 몇 초에 끝나는지 출력한다.
    cout << t << "\n";
    return 0;
}