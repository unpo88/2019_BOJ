#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int a[4];
	int b[4];

	int sum = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int sum2 = 0;
	for (int i = 0; i < 4; i++) {
		cin >> b[i];
		sum2 += b[i];
	}

	cout << max(sum, sum2);


	return 0;
}