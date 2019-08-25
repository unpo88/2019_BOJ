#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int A[8], B[8], C[8];

    for(int i = 0; i < 8; ++i){
        cin >> A[i];
        B[i] = i + 1;
        C[i] = 8 - i;
    }

    bool flag1 = true;
    bool flag2 = true;

    for(int i = 0; i < 8; ++i){
        if(A[i] != B[i]){
            flag1 = false;
        }
        if(A[i] != C[i]){
            flag2 = false;
        }
    }

    if(flag1){
        cout << "ascending";
        return 0;
    }
    if(flag2){
        cout << "descending";
        return 0;
    }

    cout << "mixed";

    return 0;
}