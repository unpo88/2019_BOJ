#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;
    cin >> N;

    char a[101] = {0, };
    cin >> a;

    int sum = 0;
    for(int i = 0; i < N; ++i){
        sum += (a[i] - 48);
    }

    cout << sum;

    return 0;
}