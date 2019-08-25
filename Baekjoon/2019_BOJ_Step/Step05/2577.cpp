#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    int D;
    D = A * B * C;

    int result[10] = {0, };

    while(D > 0){
        result[D%10]++;
        D = D / 10;
    }

    for(int i = 0; i < 10; ++i){
        cout << result[i] << "\n";
    }
    return 0;
}