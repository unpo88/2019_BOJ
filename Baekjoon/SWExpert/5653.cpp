#include <iostream>
#include <utility>
#include <queue>
using namespace std;

#define MAX 350
#define BASE 150

struct CELL{
    int life;
    int time;
};

int answer;

int N, M, K;

CELL map[MAX][MAX];

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void init(){
    answer = 0;
    for(int y = 0; y < MAX; ++y){
        for(int x = 0; x < MAX; ++x){
            map[y][x].life = 0;
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

        cin >> N >> M >> K;

        queue<pair<int, int> > q[11];

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < M; ++x){
                int num;
                cin >> num;
                map[y + BASE][x + BASE].life = num;
                map[y + BASE][x + BASE].time = num * 2;
                if(num) q[num].push(make_pair(y + BASE, x + BASE));
            }
        }        

        while(K--){
            for(int index = 10; index >= 1; --index){
                int qSize = q[index].size();
                while(qSize--){
                    int y = q[index].front().first;
                    int x = q[index].front().second;
                    q[index].pop();

                    --map[y][x].time;

                    if(map[y][x].life > map[y][x].time){
                        for(int dir = 0; dir < 4; ++dir){
                            int ny = y + dy[dir];
                            int nx = x + dx[dir];

                            if(map[ny][nx].life == 0){
                                map[ny][nx].life = map[y][x].life;
                                map[ny][nx].time = 2 * map[y][x].life;
                                q[index].push(make_pair(ny, nx));
                            }
                        }
                    }

                    if(map[y][x].time != 0){
                        q[index].push(make_pair(y, x));
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