#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int answer;

char map[100][100];
bool visited[100][100];

vector<pair<int, int> > v;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void init(){
    answer = 0;
    for(int y = 0; y < 100; ++y){
        for(int x = 0; x < 100; ++x){
            map[y][x] = '0';
            visited[y][x] = false;
        }
    }
}

void DFS(int y, int x){
    for(int dir = 0; dir < 4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= 100 || nx >= 100 || visited[ny][nx])   continue;
        if(!visited[ny][nx] && map[ny][nx] == '0'){
            visited[ny][nx] = true;
            DFS(ny, nx);
        }else if(!visited[ny][nx] && map[ny][nx] == '3'){
            visited[ny][nx] = true;
            answer = 1;
            return ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    for(int tc = 1; tc <= 10; ++tc){
        int T;
        cin >> T;

        init();

        for(int y = 0; y < 100; ++y){
            for(int x = 0; x < 100; ++x){
                cin >> map[y][x];
                if(map[y][x] == '2'){
                    v.push_back(make_pair(y, x));
                }
            }
        }

        for(int i = 0; i < v.size(); ++i){
            visited[v[i].first][v[i].second] = true;
            DFS(v[i].first, v[i].second);
        }
        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}