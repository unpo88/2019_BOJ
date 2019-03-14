// [시뮬레이션]
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int T[5][9];
int K;

int d[5];

// 톱니바퀴의 초기 상태와 톱니바퀴를 회전시킨 방법이 주어졌을 때, 최종 톱니바퀴의 상태를 구하는 프로그램을 작성하시오.
int main(){
    // 첫째 줄에 1번 톱니바퀴의 상태, 둘째 줄에 2번 톱니바퀴의 상태, 셋째 줄에 3번 톱니바퀴의 상태, 넷째 줄에 4번 톱니바퀴의 상태가 주어진다.
    // 상태는 8개의 정수로 이루어져 있고, 12시방향부터 시계방향 순서대로 주어진다. N극은 0, S극은 1로 나타나있다.
    for(int i = 1; i <= 4; i++){
       string str = "";
       cin >> str;
        for(int j = 1; j <= 8; j++){
            T[i][j] = str[j-1]-'0';
        }
    }
    // 다섯째 줄에는 회전 횟수 K(1 ≤ K ≤ 100)가 주어진다. 
    cin >> K;

    // 다음 K개 줄에는 회전시킨 방법이 순서대로 주어진다.
    // 각 방법은 두 개의 정수로 이루어져 있고,
    // 첫 번째 정수는 회전시킨 톱니바퀴의 번호, 두 번째 정수는 방향이다. 방향이 1인 경우는 시계 방향이고, -1인 경우는 반시계 방향이다.
    while(K--){
        for(int i = 1; i <= 4; i++){
            d[i] = 0;
        }
        int no, dir;
        cin >> no >> dir;
        d[no] = dir;

        // 왼쪽
        int temp_d = dir;
        for(int i = no - 1; i >= 1; i--){
            if(T[i][3] != T[i+1][7]){
                temp_d *= -1;
                d[i] = temp_d;
            }else{
                break;
            }
        }

        // 오른쪽
        temp_d = dir;
        for(int i = no + 1; i <= 4; i++){
            if(T[i-1][3] != T[i][7]){
                temp_d *= -1;
                d[i] = temp_d;
            }else{
                break;
            }
        }

        for(int i = 1; i <= 4; i++){
            if(d[i] == 1){
                int temp = T[i][1];
                T[i][1] = T[i][8];
                T[i][8] = T[i][7];
                T[i][7] = T[i][6];
                T[i][6] = T[i][5];
                T[i][5] = T[i][4];
                T[i][4] = T[i][3];
                T[i][3] = T[i][2];
                T[i][2] = temp;

            }else if(d[i] == -1){
                int temp = T[i][1];
                T[i][1] = T[i][2];
                T[i][2] = T[i][3];
                T[i][3] = T[i][4];
                T[i][4] = T[i][5];
                T[i][5] = T[i][6];
                T[i][6] = T[i][7];
                T[i][7] = T[i][8];
                T[i][8] = temp;
            }
        }
        /*
        cout << endl;
        for(int i = 1; i <= 4; i++){
            for(int j = 1; j <= 8; j++){
                cout << T[i][j];
            }
            cout << endl;
        }*/
    }

    // 총 K번 회전시킨 이후에 네 톱니바퀴의 점수의 합을 출력한다. 점수란 다음과 같이 계산한다.
    // 1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
    // 2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
    // 3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
    // 4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점
    int answer = 0;
    int mul[5] = {0, 1, 2, 4, 8 };
    for(int i = 1; i <= 4; i++){
        if(T[i][1] == 1){
            answer += mul[i];
        }   
    }
    cout << answer << endl;
    return 0;
}