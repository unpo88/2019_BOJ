#include <iostream>
using namespace std;

int main(){
    int H, M;

    cin >> H >> M;

    if(M - 45 < 0){
        if(H - 1 < 0){
            cout << 23 << " " << 60 + (M - 45);
        }else{
            cout << H - 1 << " " << 60 + (M - 45);
        }
    }else{
        cout << H << " " << M - 45;
    }
    return 0;
}