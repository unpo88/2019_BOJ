#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

// 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
enum place { EMPTY = 0, HOUSE };

// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
int N;
int map[27][27];
bool visited[27][27] = { false, };

// 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

void BFS(int y, int x);

int cnt = 0;
vector<int> sizeOfHouse;

int main()
{
    cin >> N;
    for(int y = 0; y < N; ++y){
        string input_;
        cin >> input_;
        for(int x = 0; x < N; ++x){
            if(input_[x] == '0')
                map[y][x] = EMPTY;
            else
                map[y][x] = HOUSE;
        }
    }

    // BFS(0, 1);

    for(int y = 0; y < N; ++y){
        for(int x = 0; x < N; ++x){
            if(map[y][x] == HOUSE && !visited[y][x]){
                BFS(y, x);
            }
        }
    }

    // 첫 번째 줄에는 총 단지수를 출력하시오. 
    cout << sizeOfHouse.size() << "\n";
    // 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
    sort(sizeOfHouse.begin(), sizeOfHouse.end());
    for(int i = 0; i < sizeOfHouse.size(); i++){
        cout << sizeOfHouse[i] << "\n";
    }
    return 0;
}

void BFS(int y, int x)
{
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));

    int HouseSize = 0;
    visited[y][x] = true;

    while(!q.empty()){
        HouseSize++;
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++){
            int next_y = cur_y + dy[d];
            int next_x = cur_x + dx[d];

            if(next_y >= N ||  next_x >= N || next_y < 0 || next_x < 0) continue;
            if(map[next_y][next_x] == HOUSE && !visited[next_y][next_x]){
                visited[next_y][next_x] = true;
                q.push(make_pair(next_y, next_x));
            }
        }
    }

    sizeOfHouse.push_back(HouseSize);
}