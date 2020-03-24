#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		string s;
		cin >> s;

		if (s == "end") {
			break;
		}

		bool flag = false;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				flag = true;
			}
		}

		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o') {
				flag = false;
			}
		}

		bool isMo = false;
		int cntMo = 0;
		int cntJa = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				isMo = true;
				cntMo += 1;
				cntJa = 0;
			}
			else {
				isMo = false;
				cntJa += 1;
				cntMo = 0;
			}
			if (cntMo == 3 || cntJa == 3) {
				flag = false;
			}
		}

		if (flag) {
			cout << "<" << s << "> is acceptable." << "\n";
		}
		else {
			cout << "<" << s << "> is not acceptable." << "\n";
		}
	}
	return 0;
}