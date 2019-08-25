#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;

    cin >> N;

    for(int i = 0; i < N; ++i){
        char a[80];
        cin >> a;

        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < 80; ++j){
            if(a[j] == 'O'){
                cnt += 1;
                a[j] = 'X';
            }else{
                cnt = 0;
            }
            sum += cnt;
        }
        cout << sum << "\n";
    }

    return 0;
}