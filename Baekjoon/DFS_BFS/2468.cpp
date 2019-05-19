#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
using namespace std;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int N;

int map[100][100];
int visited[100][100];

int answer = 1;
 
int max_height = INT_MIN;
int min_height = INT_MAX;

void DFS(int y, int x, int height){
    for(int dir = 0; dir < 4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny < 0 || ny >= N || nx < 0 || nx >= N)  continue;
        if(map[ny][nx] <= height || visited[ny][nx])    continue;

        visited[ny][nx]++;

        DFS(ny, nx, height);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);
    
    cin >> N;

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            cin >> map[y][x];
            min_height = min(min_height, map[y][x]);
            max_height = max(max_height, map[y][x]);
        }
    }

    for(int height = min_height; height < max_height; ++height){
        memset(visited,0,sizeof(visited));
        int cnt = 0;
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                if(map[y][x] > height && !visited[y][x]){
                    visited[y][x]++;
                    cnt++;
                    DFS(y, x, height);
                }
            }
        }
        answer = max(answer, cnt);
    }
    cout << answer << "\n";

    return 0;
}