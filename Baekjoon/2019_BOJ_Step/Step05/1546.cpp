#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;

    cin >> N;

    int A[1000];

    int M = 0;

    for(int i = 0;  i < N; ++i){
        cin >> A[i];
        M = max(M, A[i]);
    }

    double sum = 0;
    for(int i = 0; i < N; ++i){
        sum += double(A[i]) / M * 100;
    }
    cout.precision(5);
    cout << sum / N;
    return 0;
}