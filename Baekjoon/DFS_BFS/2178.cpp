#include <iostream>
#include <queue>
#include <utility>
#include <limits.h>
#include <algorithm>
using namespace std;

int N, M;

char map[101][101];
int count_map[101][101];
bool visited[101][101];

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    cin >> N >> M;

    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= M; ++x){
            cin >> map[y][x];
        }
    }

    queue<pair<int, int> > q;
    visited[1][1] = true;
    count_map[1][1] = 1;

    q.push(make_pair(1, 1));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny <= 0 || nx <= 0 || ny > N || nx > M || visited[ny][nx])  continue;
            if(!visited[ny][nx] && map[ny][nx] == '1'){
                count_map[ny][nx] = count_map[y][x] + 1;
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }

    cout << count_map[N][M] << "\n";
    return 0;
}