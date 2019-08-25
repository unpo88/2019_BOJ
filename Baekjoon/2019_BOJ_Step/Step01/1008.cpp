#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    long double  A, B;
    cin >> A >> B;
    cout.precision(9);
    cout << A / B << "\n";
    return 0;
}