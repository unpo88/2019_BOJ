#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int X;
    cin >> X;

    int i;
    for(i = 1; X > 0; ++i){
        X = X - i;
    }

    if(i % 2 == 1){
        cout << i + X - 1 << "/" << 1 - X << "\n";
    }else if(i % 2 == 0){
        cout << 1 - X << "/" << i + X - 1 << "\n";
    }


    return 0;
}