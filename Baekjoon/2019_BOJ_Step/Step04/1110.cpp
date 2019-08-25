#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int A, B, C, D;
    cin >> A;
    D = A;

    int cnt = 0;

    while(1){
        C = D % 10;
        B = D / 10 + D % 10;
        D = C * 10 + B % 10;
        cnt = cnt + 1;
        if(D == A)  break;
    }
    
    cout << cnt << "\n";

    return 0;
}