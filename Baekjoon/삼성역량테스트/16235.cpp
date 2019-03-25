#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int F[11][11],  A[11][11];

vector<int> map[11][11];

const int dy[] = { -1, -1, -1,  0,  0, +1, +1, +1 };
const int dx[] = { -1,  0, +1, -1, +1, -1,  0, +1 };

void input(){
    // 첫째 줄에 N, M, K가 주어진다.
    cin >> N >> M >> K;

    // 둘째 줄부터 N개의 줄에 A배열의 값이 주어진다.
    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= N; ++x){
            cin >> A[y][x];
            F[y][x] = 5;
        }
    }

    for(int i = 0; i < M; ++i){
        int y, x, z;
        cin >> y >> x >> z;
        map[y][x].push_back(z);
    }
}

void spring_summer(){
    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= N; ++x){
            if(map[y][x].size() == 0)   continue;

            // 나이가 어린 나무부터 양분을 먹는다.
            sort(map[y][x].begin(), map[y][x].end());
            vector<int> Temp;
            int Die_Tree = 0;

            for(int i = 0; i < map[y][x].size(); ++i){
                // 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
                if(map[y][x][i] <= F[y][x]){
                    F[y][x] -= map[y][x][i];
                    map[y][x][i] += 1;
                    Temp.push_back(map[y][x][i]);
                }else{  // 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
                    // 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
                    Die_Tree += (map[y][x][i] / 2);    
                }
            }
            
            map[y][x].clear();
            for(int i = 0; i < Temp.size(); ++i){
                map[y][x].push_back(Temp[i]);
            }
            F[y][x] += Die_Tree;
        }
    }
}

void fall(){
    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= N; ++x){
            if(map[y][x].size() == 0)   continue;
            for(int i = 0; i < map[y][x].size(); ++i){
                if(map[y][x][i] % 5 == 0){
                    for(int dir = 0; dir < 8; ++dir){
                        int next_y = y + dy[dir];
                        int next_x = x + dx[dir];
                        if(next_y >= 1 && next_y <= N 
                        && next_x >= 1 && next_x <= N){
                            map[next_y][next_x].push_back(1);
                        }
                    }   
                }
            }
        }
    }
}

void winter(){
    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= N; ++x){
            F[y][x] += A[y][x];
        }
    }
}


void solution(){
    for(int i = 0; i < K; ++i){
        spring_summer();
        fall();
        winter();
    }

    int Answer = 0;

    for(int y = 1; y <= N; ++y){
        for(int x = 1; x <= N; ++x){
            Answer += map[y][x].size();
        }
    }

    cout << Answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    input();
    solution();

    return 0;
}

// #include <iostream>
// #include <queue>
// #include <algorithm>
// using namespace std;

// // 나무의 정보
// struct TREE{
//     // 좌표, 나이
//     int y, x, age;
// };

// bool cmp(TREE& a, TREE& b){
//     // 나이가 어린 나무부터 양분을 먹는다.
//     return (a.age < b.age);
// }

// // N : 보드 크기 N X N
// // M : 나무의 개수
// // K : 시간
// int N, M, K;

// // 올해, 내년 나무
// queue<TREE> tree[2];

// // 새로운 트리
// queue<TREE> new_tree;

// // 죽은 트리
// queue<TREE> dead_tree;

// // 번식 트리
// queue<TREE> birth_of_child_tree;

// int map[10][10],    add[10][10];

// // 1 ≤ M ≤ N^2
// TREE init_tree[100];

// // 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
// const int dy[] = { -1, -1, -1,  0,  0, +1, +1, +1 };
// const int dx[] = { -1,  0, +1, -1, +1, -1,  0, +1 };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL),  cout.tie(NULL);
    
//     // 첫째 줄에 N, M, K가 주어진다.
//     cin >> N >> M >> K;

//     for(int y = 0; y < N; ++y){
//         for(int x = 0; x < N; ++x){
//             // 둘째 줄부터 N개의 줄에 A배열의 값이 주어진다. r번째 줄의 c번째 값은 A[r][c]이다.
//             cin >> add[y][x];
//             // 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
//             map[y][x] = 5;
//         }
//     }

//     // 다음 M개의 줄에는 상도가 심은 나무의 정보를 나타내는 세 정수 x, y, z가 주어진다. 처음 두 개의 정수는 나무의 위치 (x, y)를 의미하고, 마지막 정수는 그 나무의 나이를 의미한다.
//     for(int i = 0; i < M; ++i){
//         cin >> init_tree[i].y >> init_tree[i].x >> init_tree[i].age;
//         init_tree[i].y--,   init_tree[i].x--;
//     }

//     // 나이가 어린 나무부터 양분을 먹는다.
//     sort(init_tree, init_tree + M, cmp);

//     int cur = 0,    next = 0;
//     for(int i = 0; i < M; ++i){
//         // 올해 나무
//         tree[cur].push(init_tree[i]);
//     }

//     for(int i = 0; i < K; ++i){
//         // 내년 나무
//         next = (cur + 1) % 2;

//         // 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
//         // 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 
//         // 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
//         // 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.

//         // 새로 생긴 나무
//         while(!new_tree.empty()){
//             TREE cur_tree = new_tree.front();   new_tree.pop();

//             // 나무가 자신의 나이만큼 양분을 먹는다.
//             if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){
//                 // 자신의 나이만큼 양분을 먹고
//                 map[cur_tree.y][cur_tree.x] -= cur_tree.age;
//                 // 나이가 1 증가한다.
//                 ++cur_tree.age;
//                 // 내년 나무에 들어간다.
//                 tree[next].push(cur_tree);
//             }else{
//                 // 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
//                 dead_tree.push(cur_tree);
//             }
//         }

//         // 현재 나무
//         while(!tree[cur].empty()){
//             TREE cur_tree = tree[cur].front();  tree[cur].pop();

//             // 나무가 자신의 나이만큼 양분을 먹는다.
//             if(map[cur_tree.y][cur_tree.x] >= cur_tree.age){
//                 // 자신의 나이만큼 양분을 먹고
//                 map[cur_tree.y][cur_tree.x] -= cur_tree.age;
//                 // 나이가 1 증가한다.
//                 ++cur_tree.age;
//                 // 내년 나무에 들어간다.
//                 tree[next].push(cur_tree);

//                 // 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 한다.
//                 if((cur_tree.age % 5) == 0){
//                     // 번식하는 나무에 넣어준다.
//                     birth_of_child_tree.push(cur_tree);
//                 }
//             }else{
//                 // 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
//                 dead_tree.push(cur_tree);
//             }
//         }

//         // 죽은 나무
//         while(!dead_tree.empty()){
//             TREE cur_tree = dead_tree.front();  dead_tree.pop();
//             // 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
//             map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
//         }

//         // 번식 나무
//         while(!birth_of_child_tree.empty()){
//             TREE cur_tree = birth_of_child_tree.front();    birth_of_child_tree.pop();
//             // 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
//             // 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다. 
//             for(int dir = 0; dir < 8; ++dir){
//                 TREE next_tree;
//                 next_tree.y = cur_tree.y + dy[dir];
//                 next_tree.x = cur_tree.x + dx[dir];
//                 // 나이가 1인 나무가 생긴다.
//                 next_tree.age = 1;

//                 // 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
//                 if(next_tree.y < 0 || next_tree.y >= N ||
//                    next_tree.x < 0 || next_tree.x >= N){
//                        continue;
//                 }
//                 // 새로운 나무
//                 new_tree.push(next_tree);
//             }
//         }

//         // 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
//         for(int y = 0; y < N; ++y){
//             for(int x = 0; x < N; ++x){
//                 map[y][x] += add[y][x];
//             }
//         }
//         // 올해는 내년이 된다.
//         cur = next;
//     }


//     cout << tree[next].size() + new_tree.size() << "\n";

//     return 0;
// // }

// #include <iostream>
// #include <list>
// using namespace std;

// struct TREE{
//     int y, x, age;
//     bool alive;
// };

// int N, M, K;

// int F[10][10],    A[10][10];

// list<TREE> Trees;

// const int dy[] = { -1, -1, -1,  0,  0, +1, +1, +1 };
// const int dx[] = { -1,  0, +1, -1, +1, -1,  0, +1 };

// int solve(){
//     for(int i = 0; i < K; ++i){
//         for(list<TREE>::iterator it = Trees.begin(); it!= Trees.end(); ++it){
//             if(it->age <= F[it->y][it->x]){
//                 F[it->y][it->x] -= it->age;
//                 it->age++;
//             }else{
//                 it->alive = false;
//             }
//         }

//         for(list<TREE>::iterator it = Trees.begin(); it != Trees.end();){
//             if(it->alive){
//                 ++it;
//             }else{
//                 F[it->y][it->x] += (it->age / 2);
//                 it = Trees.erase(it);
//             }
//         }

//         for(list<TREE>::iterator it = Trees.begin(); it != Trees.end(); ++it){
//             if(it->age % 5 == 0){
//                 for(int dir = 0; dir < 8; ++dir){
//                     TREE next;
//                     next.y = it->y + dy[dir];
//                     next.x = it->x + dx[dir];
//                     next.age = 1;
//                     next.alive = true;
//                     if(next.y < 0 || next.y >= N ||
//                        next.x < 0 || next.x >= N){
//                            continue;
//                     }
//                     Trees.push_front(next);
//                 }
//             }
//         }

//         for(int y = 0; y < N; ++y){
//             for(int x = 0; x < N; ++x){
//                 F[y][x] += A[y][x];
//             }
//         }
//     }
    
//     return Trees.size();
// }


// int main(){
//     cin >> N >> M >> K;

//     for(int y = 0; y < N; ++y){
//         for(int x = 0; x < N; ++x){
//             cin >> A[y][x];
//             F[y][x] = 5;
//         }
//     }

//     TREE start;
//     for(int i = 0; i < M; ++i){
//         cin >> start.y >> start.x >> start.age;
//         start.y--,  start.x--;
//         start.alive = true;
//         Trees.push_back(start);
//     }

//     cout << solve() << "\n";
// }