#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits.h>
#include <algorithm>
using namespace std;
#define MAX 50

int N, M;

int map[MAX][MAX];
int copy_map[MAX][MAX];

vector<pair<int, int> > virus;

bool check[10];

int answer = INT_MAX;

bool check_answer(){
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            if(copy_map[y][x] == -1){
                return false;
            }
        }
    }
    return true;
}

void input(){
    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            cin >> map[y][x];
            if(map[y][x] == 2){
                virus.push_back(make_pair(y, x));
            }
        }
    }
}

void DFS(int idx, int cnt){
    if(cnt > M) return;
    
    if(cnt == M){
        bool visited[MAX][MAX];
        for(int y = 0; y < N; ++y){
            for(int x = 0; x < N; ++x){
                if(map[y][x] == 1){
                    copy_map[y][x] = -2;
                }else{
                    copy_map[y][x] = -1;
                }
                visited[y][x] = false;
            }
        }

        queue<pair<int, int> > q;
        const int dy[] = { 0, 0, 1, -1 };
        const int dx[] = { 1, -1, 0, 0 };

        for(int i = 0; i < 10; ++i){
            if(check[i]){
                copy_map[virus[i].first][virus[i].second] = 0;
                q.push(make_pair(virus[i].first, virus[i].second));
            }
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            visited[y][x] = true;
            q.pop();

            for(int dir = 0; dir < 4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])  continue;
                if(copy_map[ny][nx] == -1 && !visited[ny][nx] && map[ny][nx] != 1){
                    copy_map[ny][nx] = copy_map[y][x] + 1;
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }
            }
        }
        
        if(check_answer()){
            int result = 0;
            for(int y = 0; y < N; ++y){
                for(int x = 0; x < N; ++x){
                    result = max(result, copy_map[y][x]);
                }
            }
            answer = min(answer, result);
        }
    }
    
    for(int i = idx; i < virus.size(); ++i){
        if(!check[i]){
            check[i] = true;
            DFS(i + 1, cnt + 1);
            check[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    cin >> N >> M;

    input();
    DFS(0, 0);

    if(answer == INT_MAX){
        cout << -1 << "\n";
    }else{
        cout << answer << "\n";
    }

    return 0;
}