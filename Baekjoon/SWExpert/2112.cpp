#include<iostream>

#include<algorithm>
using namespace std;
  
int D, W, K;
int map[14][21];
int cpy[14][21];
int res;
  
bool Check()
{
    bool isOk;
    int cnt;
    for (int j = 1; j <= W; j++){
        cnt = 1;
        isOk = false;
        for (int i = 2; i <= D; i++){
            if (map[i][j] == map[i - 1][j]) cnt++;
            else cnt = 1;
            if (cnt >= K) {
                isOk = true; break;
            }
        }
        if (!isOk) return false;
    }
    return true;
}
  
void Solve(int idx, int val, int cnt)
{
    for (int i = 1; i <= W; i++)
        map[idx][i] = val;
  
    for (int i = idx + 1; i <= D; i++)
        Solve(i, val, cnt + 1);
  
    if (Check()) res = min(res, cnt);
  
    for (int i = 1; i <= W; i++)
        map[idx][i] = cpy[idx][i];
}
  
int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
        cin >> D >> W >> K;
  
        for (int i = 1; i <= D; i++){
            for (int j = 1; j <= W; j++){
                cin >> map[i][j];
                cpy[i][j] = map[i][j];
            }
        }
        res = 999;
        if (Check()) res = 0;
        else{
            Solve(0, 0, 0);
            Solve(0, 1, 0);
        }
        cout << "#" << t << " ";
        cout << res << endl;
    }
}