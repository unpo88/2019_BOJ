#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int T;
    cin >> T;
    
    int A, B;
    
    for(int i = 0; i < T; ++i){
        cin >> A >> B;
        cout << A + B << "\n";
    }
    return 0;
}