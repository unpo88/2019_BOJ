#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;
    cin >> N;

    int minResult = 1000000;
    int maxResult = -1000000;
    for(int i = 0; i < N; ++i){
        int A;
        cin >> A;
        minResult = min(minResult, A);
        maxResult = max(maxResult, A);
    }

    cout << minResult << " " << maxResult;
    return 0;
}