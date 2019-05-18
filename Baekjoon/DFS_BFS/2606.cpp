#include <iostream>
#include <cstdio>
using namespace std;

int map[101][101];
int visit[101];
int n;
int answer;

int DFS(int v);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    int testCase;
    cin >> testCase;

    int v1, v2;
    for(int i = 0; i < testCase; i++){
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }
    cout << DFS(1);
    return 0;
}

int DFS(int v){
    visit[v] = 1;

    for(int i = 1; i <= n; i++){
        if(visit[i] == 0 && map[v][i] == 1){
            answer++;
            DFS(i);
        }
    }

    return answer;
}