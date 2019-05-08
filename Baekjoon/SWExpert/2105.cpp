#include <iostream>
using namespace std;

int N;

int map[20][20];

void init(){
    for(int y = 0; y < 20; ++y){
        for(int x = 0; x < 20; ++x){
            map[y][x] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);
    
    int T;

    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        int answer = -1;
        init();

        cin >> N;

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                cin >> map[y][x];
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                for(int a = 1; a <= N; ++a){
                    for(int b = 1; b <= N; ++b){
                        if(y + b < N
                        && x - b >= 0
                        && y + a + b < N
                        && x + a - b >= 0
                        && y + a < N
                        && x + a < N
                        && answer < (a + b) * 2){
                            int cur_y = y;
                            int cur_x = x;

                            bool check[101] = { false, };
                            bool isAble = true;


                            for(int i = 1; i <= a; ++i){
                                cur_y++;    cur_x++;
                                if(!check[map[cur_y][cur_x]]){
                                    check[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int i = 1; i <= b; ++i){
                                cur_y++;    cur_x--;
                                if(!check[map[cur_y][cur_x]]){
                                    check[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int i = 1; i <= a; ++i){
                                cur_y--;    cur_x--;
                                if(!check[map[cur_y][cur_x]]){
                                    check[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int i = 1; i <= b; ++i){
                                cur_y--; cur_x++;
                                if(!check[map[cur_y][cur_x]]){
                                    check[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            answer = (a + b) * 2;
                        }
                    }
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}