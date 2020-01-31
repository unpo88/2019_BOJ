#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;
    cin >> N;

    int three = N / 3;
    int five = N / 5;
    int sum = 0;

    for(int i = 0; i <= three; ++i){
        for(int j = 0; j <= five; ++j){
            if(3 * i + 5 * j == N){
                cout << i + j << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";

    return 0;
}