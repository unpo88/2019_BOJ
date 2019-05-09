#include <iostream>
#include <utility>
#include <queue>
using namespace std;

struct CELL{
    int power;
    int time;
};

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int answer;
 
int N, M, K;

CELL map[600][600];

void init(){
    for(int y = 0; y < 600; ++y){
        for(int x = 0; x < 600; ++x){
            map[y][x].power = 0;
            map[y][x].time = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        init();
        answer = 0;

        cin >> N >> M >> K;

        queue<pair<int, int> > q[11];

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                int num;
                cin >> num;

                map[300 + y][300 + x].power = num;
                map[300 + y][300 + x].time = 2 * num;

                if(num != 0){
                    q[num].push(make_pair(300 + y, 300 + x));
                }
            }
        }

        while(K--){
            for(int index = 10; index >= 1; --index){
                int qSize = q[index].size();

                while(qSize--){
                    int cur_y = q[index].front().first;
                    int cur_x = q[index].front().second;
                    q[index].pop();

                    --map[cur_y][cur_x].time;

                    if(map[cur_y][cur_x].power > map[cur_y][cur_x].time){
                        for(int dir = 0; dir < 4; ++dir){
                            int ny = cur_y + dy[dir];
                            int nx = cur_x + dx[dir];

                            if(map[ny][nx].power == 0){
                                map[ny][nx].power = map[cur_y][cur_x].power;
                                map[ny][nx].time = 2 * map[cur_y][cur_x].power;

                                q[index].push(make_pair(ny, nx));
                            }
                        }
                    }

                    if(map[cur_y][cur_x].time != 0){
                        q[index].push(make_pair(cur_y, cur_x));
                    }
                }
            }
        }
        
        for(int index = 1; index <= 10; ++index){
            answer += q[index].size();
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}