#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K;

int Y, X;

char board[4][7];

int answer;

vector<long long> v2;

map<int, int>  check;

bool cmp(long long a, long long b){
    return a > b;
}

void change(){
    for(int x = 0; x < X; ++x){
        int k = Y - 1;
        int total = 0;
        for(int y = 0; y < Y; ++y){
            int total2 = 0;
            switch(board[x][y]){
                case '0':
                    total2 += 0 * pow(16, k--);
                    break;
                case '1':
                    total2 += 1 * pow(16, k--);
                    break;
                case '2':
                    total2 += 2 * pow(16, k--);
                    break;
                case '3':
                    total2 += 3 * pow(16, k--);
                    break;
                case '4':
                    total2 += 4 * pow(16, k--);
                    break;
                case '5':
                    total2 += 5 * pow(16, k--);
                    break;
                case '6':
                    total2 += 6 * pow(16, k--);
                    break;
                case '7':
                    total2 += 7 * pow(16, k--);
                    break;
                case '8':
                    total2 += 8 * pow(16, k--);
                    break;
                case '9':
                    total2 += 9 * pow(16, k--);
                    break;
                case 'A':
                    total2 += 10 * pow(16, k--);
                    break;
                case 'B':
                    total2 += 11 * pow(16, k--);
                    break;
                case 'C':
                    total2 += 12 * pow(16, k--);
                    break;
                case 'D':
                    total2 += 13 * pow(16, k--);
                    break;
                case 'E':
                    total2 += 14 * pow(16, k--);
                    break;
                case 'F':
                    total2 += 15 * pow(16, k--);
                    break;
            }
            total += total2;
        }
        if(!check[total]){
            v2.push_back(total);
            check[total] = 1;
        }
    }
}

void rotate(){
    change();

    vector<int> v;
    for(int x = 0; x < X; ++x){
        for(int y = Y - 1; y >= 0; --y){
            if(y == Y - 1){
                v.push_back(board[x][y]);
                board[x][y] = board[x][y - 1];
            }else{
                board[x][y] = board[x][y - 1];
            }
        }
    }

    int index = 0;
    for(int x = 0; x < X; ++x){
        if(x == 0){
            board[x][0] = v[v.size() - 1];
        }else{
            board[x][0] = v[index];
            index++;
        }
    }
    sort(v2.begin(), v2.end(), cmp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc){
        v2.clear();
        check.clear();

        answer = 0;

        cin >> N >> K;
        
        Y = N / 4;
        X = 4;
        
        for(int x = 0; x < X; ++x){
            for(int y = 0; y < Y; ++y){
                cin >> board[x][y];
            }
        }

        for(int y = 0; y < Y; ++y){
            rotate();
        }

        cout << "#" << tc << " " << v2[K - 1] << "\n";
    }
    return 0;
}