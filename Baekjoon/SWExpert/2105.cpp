#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        int N;
        cin >> N;
        int map[20][20] = { 0, };

        int answer = -1;
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                cin >> map[y][x];
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                for(int a = 1; a <= N; ++a){
                    for(int b = 1; b <= N; ++b){
                        if(y + a < N 
                        && x + a < N
                        && y + a + b < N
                        && x + a - b >= 0
                        && y + b < N
                        && x - b >= 0
                        && answer < 2 * (a + b)){
                            int visited[101] = { false, };
                            bool isAble = true;
                            int cur_y = y;
                            int cur_x = x;

                            for(int n = 0; n < a; ++n){
                                cur_y++;    cur_x++;
                                if(!visited[map[cur_y][cur_x]]){
                                    visited[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int n = 0; n < b; ++n){
                                cur_y++;    cur_x--;
                                if(!visited[map[cur_y][cur_x]]){
                                    visited[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int n = 0; n < a; ++n){
                                cur_y--;    cur_x--;
                                if(!visited[map[cur_y][cur_x]]){
                                    visited[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            for(int n = 0; n < b; ++n){
                                cur_y--;    cur_x++;
                                if(!visited[map[cur_y][cur_x]]){
                                    visited[map[cur_y][cur_x]] = true;
                                }else{
                                    isAble = false;
                                    break;
                                }
                            }
                            if(!isAble) continue;

                            answer = 2 * (a + b);
                        }
                    }
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}