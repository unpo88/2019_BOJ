#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	long long A, B;

	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0)	break;

		cout << A / B << " " << A % B << " / " << B << "\n";
	}

	return 0;
}