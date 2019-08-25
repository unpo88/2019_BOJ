#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int C;
    cin >> C;

    for(int i = 0; i < C; ++i){
        int N;
        cin >> N;
        int a[1001] = {0, };

        long double sum = 0;
        for(int j = 0; j < N; ++j){
            cin >> a[j];
            sum += a[j];
        }
        sum /= N;
        int cnt = 0;
        for(int j = 0; j < N; ++j){
            if(a[j] > sum){
                cnt += 1;
            }
        }
        long double result;
        result = double(cnt) / N * 100;
        cout << fixed;
        cout.precision(3);
        cout << result << "%\n";
    }

    return 0;
}