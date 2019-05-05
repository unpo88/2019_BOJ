#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int map[20][20];

int answer; 

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void BFS(int y, int x){
    queue<pair<int, int> > q;

    bool visited[20][20] = { false, };

    q.push(make_pair(y, x));
    visited[y][x] = true;

    int cnt = map[y][x];

    while(!q.empty()){
        for(int K = 1; K <= 2 * N; ++K){
            int qSize = q.size();
            int price = M * cnt - (K * K + (K - 1) * (K - 1));

            if(price >= 0 && answer < cnt){
                answer = cnt;
            }

            while(qSize--){
                int cur_y = q.front().first;
                int cur_x = q.front().second;
                q.pop();

                for(int dir = 0; dir < 4; ++dir){
                    int next_y = cur_y + dy[dir];
                    int next_x = cur_x + dx[dir];

                    if(next_y < 0 || next_x < 0 || next_y >= N || next_x >= N || visited[next_y][next_x])   continue;

                    q.push(make_pair(next_y, next_x));
                    visited[next_y][next_x] = true;
                    if(map[next_y][next_x] == 1)    ++cnt;
                }
            }
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        answer = 0;

        cin >> N >> M;

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                cin >> map[y][x];
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                BFS(y, x);
            }
        }
        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}