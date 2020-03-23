#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n; 
	cin >> n;

	int cand = n;
	int count = 1;
	while (cand != 1) {

		if (cand % 2 == 0) {
			cand = cand / 2;
		}
		else {
			cand = cand * 3 + 1;
		}
		count++;
	}

	cout << count << "\n";
	return 0;
}