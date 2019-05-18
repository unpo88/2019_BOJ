#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int answer;

char map[16][16];
bool visited[16][16];

queue<pair<int, int> > q;

const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void init(){
    answer = 0;
    for(int y = 0; y < 16; ++y){
        for(int x = 0; x < 16; ++x){
            map[y][x] = '0';
            visited[y][x] = false;
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

        int end_y, end_x;

        for(int y = 0; y < 16; ++y){
            for(int x = 0; x < 16; ++x){
                cin >> map[y][x];
                if(map[y][x] == '2'){
                    q.push(make_pair(y, x));
                }
            }
        }

        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            for(int dir = 0; dir < 4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny < 0 || nx < 0 || ny >= 16 || nx >= 16 || visited[ny][nx])    continue;
                if(!visited[ny][nx] && map[ny][nx] == '0'){
                    visited[ny][nx] = true;
                    q.push(make_pair(ny, nx));
                }else if(map[ny][nx] == '3'){
                    answer = 1;
                }
            }
        }

        cout << "#" << tc << " " << answer << "\n";
    }
    return 0;
}