#include <iostream>
using namespace std;

void hanoi(int x, int y, int count) {
    if (!count) return;
    hanoi(x, 6 - x - y, count-1);
    cout << x << " " << y << "\n";
    hanoi(6 - x - y, y, count-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),  cout.tie(NULL);

    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";

    hanoi(1, 3, N);

    return 0;
}