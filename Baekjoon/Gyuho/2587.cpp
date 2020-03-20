#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}

	sort(num, num + 5);
	cout << sum / 5 << "\n";
	cout << num[2] << "\n";
	return 0;
}