#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int S, T, D;
	cin >> S >> T >> D;

	cout << D / (S * 2) * T;
	
	return 0;
}