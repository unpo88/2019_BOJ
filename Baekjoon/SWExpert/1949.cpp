#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, K;

int map[8][8];
bool visited[8][8];

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0 ,0 };

int height;
int answer;

void check_height(){
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            if(height < map[y][x])  height = map[y][x];
        }
    }
}

void input(){
    cin >> N >> K;
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            cin >> map[y][x];
        }
    }
}

void DFS(int y, int x, int len, int status){
    visited[y][x] = true;
    
    for(int dir = 0; dir < 4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])  continue;
        if(map[y][x] > map[ny][nx]){
            DFS(ny, nx, len + 1, status);
        }else if(!status && map[y][x] > map[ny][nx] - K){
            int temp = map[ny][nx];
            map[ny][nx] = map[y][x] - 1;
            DFS(ny, nx, len + 1, 1);
            map[ny][nx] = temp;
        }
    }

    visited[y][x] = false;
    answer = max(answer, len);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        answer = 0;
        height = 0;

        input();
        check_height();

        vector<pair<int, int> > v;
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                if(height == map[y][x]) v.push_back(make_pair(y,x));
            }
        }

        for(int i = 0; i < v.size(); ++i){
            DFS(v[i].first, v[i].second, 1, 0);
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}