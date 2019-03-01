#include <iostream>
#include <queue>
using namespace std;

int M, N;
int map[1001][1001];
int visit[1001][1001];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

queue<pair<int, int> > q;

void DFS();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> map[i][j];
            visit[i][j] = -1;
            if(map[i][j] == 1){
                visit[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    
    int maxVal = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!map[nx][ny] && visit[nx][ny] == -1){
                if(nx > 0 && ny > 0 && nx <= N && ny <= M){
                    visit[nx][ny] = visit[x][y] + 1;
                    q.push(make_pair(nx, ny));
                    if(maxVal < visit[nx][ny]){
                        maxVal = visit[nx][ny];
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= M; j++){
            if(!map[i][j] && visit[i][j] == -1){
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", maxVal);
    return 0;
}