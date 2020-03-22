#include <iostream>
using namespace std;

int pay;
int coin[] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> pay;

	int total = 1000 - pay;
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		while (total - coin[i] >= 0) {
			total -= coin[i];
			cnt++;
			if (total == 0)
				break;
		}
	}

	cout << cnt;

	return 0;
}