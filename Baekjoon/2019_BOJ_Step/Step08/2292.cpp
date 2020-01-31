#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    long long N;
    cin >> N;

    int i = 1;
    while(1){
        if(N <= (3 * i * i - 3 * i + 1)){
            cout << i << "\n";
            return 0;
        }
        i++;
    }
    return 0;
}