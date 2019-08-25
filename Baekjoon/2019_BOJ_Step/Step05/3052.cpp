#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int result[1000] = {0, };
    for(int i = 0; i < 10; ++i){
        int A;
        cin >> A;
        result[A%42]++;
    }

    int cnt = 0;
    for(int i = 0; i < 1000; ++i){
        if(result[i] != 0){
            cnt = cnt + 1;
        }
    }

    cout << cnt;
    return 0;
}