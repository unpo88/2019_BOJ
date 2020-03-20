#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	long long A, B;
	cin >> A >> B;

	if (A > B) {
		swap(A, B);
	}

	cout << ((B * B) + B - (A * A) + A) / 2;

	return 0;
}