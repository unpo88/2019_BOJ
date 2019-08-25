#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int result = 0;
    int A[10];
    for(int i = 0; i < 9; ++i){
        cin >> A[i];
        result = max(result, A[i]);
    }

    for(int i = 0; i < 9; ++i){
        if(result == A[i]){
            cout << result << "\n" << i + 1 << "\n";
            break;
        }
    }

    return 0;
}