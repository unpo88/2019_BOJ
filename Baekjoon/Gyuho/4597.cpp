#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	while (1) {
		cin >> s;
		if (s[0] == '#') {
			break;
		}

		int count = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == '1') {
				count++;
			}
		}

		if (s[s.length() - 1] == 'e') {
			if (count % 2 == 0) {
				s[s.length() - 1] = '0';
			}
			else {
				s[s.length() - 1] = '1';
			}
		}
		else {
			if (count % 2 == 0){
				s[s.length() - 1] = '1';
			}
			else {
				s[s.length() - 1] = '0';
			}
		}

		for (int i = 0; i < s.length(); i++) {
			cout << s[i];
		}
		cout << "\n";

	}

	return 0;
}