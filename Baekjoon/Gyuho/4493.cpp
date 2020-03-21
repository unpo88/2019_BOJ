#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int a_cnt = 0;
		int b_cnt = 0;
		
		while (n--) {
			char a, b;
			cin >> a >> b;

			if (a == 'R' && b == 'P') {
				b_cnt++;
			}
			else if (a == 'R' && b == 'S') {
				a_cnt++;
			}
			else if (a == 'S' && b == 'R') {
				b_cnt++;
			}
			else if (a == 'S' && b == 'P') {
				a_cnt++;
			}
			else if (a == 'P' && b == 'S') {
				b_cnt++;
			}
			else if (a == 'P' && b == 'R') {
				a_cnt++;
			}
		}
		if (a_cnt > b_cnt) {
			cout << "Player 1\n";
		}
		else if (a_cnt < b_cnt) {
			cout << "Player 2\n";
		}
		else {
			cout << "TIE\n";
		}
	}

	return 0;
}