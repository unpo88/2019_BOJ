#include <cstdio>
#include <string.h>
#include <vector>
using namespace std;

#define INF 987654321

typedef long long lld;

bool visit[3001];

struct spot {
    int y, x, d;
};

int dist(spot a, spot b){
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

bool isConnected(spot a, spot b){
    return (a.d+b.d)*(a.d+b.d) >= dist(a, b);
}


bool dfs(vector<int> adj[], int pos){
    if(visit[pos]) return false;
    visit[pos] = true;
    for(int i=0; i<adj[pos].size(); ++i)
        dfs(adj, adj[pos][i]);
    return true;
}

int main(){
    int T, i, j, k;
    scanf("%d", &T);
    while(T--){
        int N, x, y, r;
        scanf("%d", &N);
        spot s[3001];
        for(i=0; i<N; ++i){
            scanf("%d %d %d", &x, &y, &r);
            s[i].x = x;
            s[i].y = y;
            s[i].d = r;
        }
        
        vector<int> adj[N];   // i번째 진영과 연결되는 다른 진영
        for(i=0; i<N; ++i){
            for(j=0; j<N; ++j){
                if(i == j) continue;
                if( isConnected(s[i], s[j]) ){
                    adj[i].push_back(j);
                }
            }
        }
        
        memset(visit, false, sizeof(visit));
        int count=0;
        for(i=0; i<N; ++i){
            count += dfs(adj, i);
        }
        printf("%d\n", count);
    }
    return 0;
}