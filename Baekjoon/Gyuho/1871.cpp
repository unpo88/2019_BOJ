#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	char arr[9];
	for (int i = 0; i < N; i++) {
		cin >> arr;
		
		int sum1 = 0;
		int sum2 = 0;

		sum1 = (arr[0] - 'A') * 26 * 26 + (arr[1] - 'A') * 26 + (arr[2] - 'A');
		sum2 = (arr[4] - 48) * 1000 + (arr[5] - 48) * 100 + (arr[6] - 48) * 10 + (arr[7] - 48);

		if (abs(sum1 - sum2) <= 100)	cout << "nice\n";
		else cout << "not nice\n";
	}

	return 0;
}