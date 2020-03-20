#include <iostream>
using namespace std;

bool check[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	for (int i = 1; i <= 100; i++) {
		check[i*i] = true;
	}

	int sum = 0;
	bool flag = false;
	for (int i = M; i <= N; i++) {
		if (check[i]) {
			sum += i;
			flag = true;
		}
	}

	if (!flag) {
		cout << "-1\n";
		return 0;
	}

	cout << sum << "\n";

	for (int i = M; i <= N; i++) {
		if (check[i]) {
			cout << i << "\n";
			break;
		}
	}

	

	return 0;
}