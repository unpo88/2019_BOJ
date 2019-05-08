#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int map[8][8];
bool visited[8][8];

int N, K;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int answer;

void init(){
    for(int y = 0; y < 8; ++y){
        for(int x = 0; x < 8; ++x){
            map[y][x] = 0;
        }
    }
    answer = 0;
}

void DFS(int y, int x, int cnt, int status){
    visited[y][x] = true;
    for(int dir = 0; dir < 4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])  continue;
        if(map[y][x] > map[ny][nx]){
            DFS(ny, nx, cnt + 1, status);
        }else if(!status && map[y][x] > map[ny][nx] - K){
            int temp = map[ny][nx];
            map[ny][nx] = map[y][x] - 1;
            DFS(ny, nx, cnt + 1, 1);
            map[ny][nx] = temp;
        }
    }

    visited[y][x] = false;
    answer = max(answer, cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        init();

        cin >> N >> K;

        vector<pair<int, int> > v;
        
        int height = 0;
         
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                cin >> map[y][x];
                if(height < map[y][x]){
                    height = map[y][x];
                }
            }
        }

        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                if(map[y][x] == height){
                    v.push_back(make_pair(y, x));
                }
            }
        }

        for(int index = 0; index < v.size(); ++index){
            DFS(v[index].first, v[index].second, 1, 0);
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}