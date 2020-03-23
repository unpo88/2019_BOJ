#include <iostream>
using namespace std;

int samgak[51];
int ans[4000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int d;
		cin >> d;

		int s = 0;
		int t = 0;

		while (1) {
			if (d < s + t) {
				t--;
				break;
			}
			t++;
			s = t*t;
		}
		cout << t << "\n";
	}

	return 0;
}