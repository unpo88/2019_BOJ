#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int L, P;
	cin >> L >> P;

	int answer = L * P;
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		cout << num - answer << " ";
	}

	return 0;
}