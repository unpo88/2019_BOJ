#include <iostream>
#include <cstdio>
using namespace std;

int testCase;
int N;
int v;
int start;

int answer = 0;

int map[1001][1001];
int visit[1001];

void DFS(int v){
    visit[v] = 1;
    if(v == start){
        answer++;
        return;
    }else{
        for(int i = 1; i <= N; i++){
            if(!visit[i] && map[v][i] == 1){
                DFS(i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> testCase;
    while(testCase--){
        cin >> N;
        answer = 0;

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                map[i][j] = 0;
            }
            visit[i] = 0;
        }
        
        for(int i = 1; i <= N; i++){
            cin >> v;
            map[i][v] = map[v][i] = 1;
        }

        for(int i = 1; i <= N; i++){
            start = i;
            for(int j = 1; j <= N; j++){
                if(!visit[j] && map[i][j] == 1){
                    DFS(j);
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}