#include <iostream>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;


	while (T--) {
		string s;
		cin >> s;

		int num[10] = { 0, };

		for (int i = 0; i < s.size(); i++) {
			num[s[i] - 48]++;
		}

		int cnt = 0;
		for (int i = 0; i < 10; i++) {
			if (num[i] > 0) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}