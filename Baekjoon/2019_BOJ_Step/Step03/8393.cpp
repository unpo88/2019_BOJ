#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;

    cin >> N;

    int result = 0;
    for(int i = 1; i <= N; ++i){
        result += i;
    }
    
    cout << result;
    return 0;
}