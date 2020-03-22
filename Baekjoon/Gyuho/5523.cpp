#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;

	cin >> N;

	int cntA = 0;
	int cntB = 0;

	while (N--) {
		int A, B;
		cin >> A >> B;

		if (A > B) {
			cntA++;
		}
		else if (A < B) {
			cntB++;
		}
	}


	cout << cntA << " " << cntB;

	return 0;
}