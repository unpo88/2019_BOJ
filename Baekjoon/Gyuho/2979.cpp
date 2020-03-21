#include <iostream>
using namespace std;

int fare[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < b; j++) {
			fare[j] ++;
		}
	}

	int answer = 0;
	for (int i = 1; i < 101; i++) {
		if (fare[i] == 1)
			answer = answer + fare[i] * A;
		else if (fare[i] == 2)
			answer = answer + fare[i] * B;
		else if (fare[i] == 3)
			answer = answer + fare[i] * C;
	}

	cout << answer << endl;

	return 0;
}