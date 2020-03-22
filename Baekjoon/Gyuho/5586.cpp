#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;

	int cntJ = 0;
	int cntI = 0;
	for (int i = 0; i < s.length() - 2; i++) {
		if (s[i] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			cntJ++;
		}
		if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			cntI++;
		}
	}

	cout << cntJ << "\n" << cntI;

	return 0;
}