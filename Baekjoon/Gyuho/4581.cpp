#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (1) {
		string s;
		cin >> s;

		if (s[0] == '#') {
			break;
		}
		
		int cntY = 0;
		int cntN = 0;
		int cntA = 0;
		int cntP = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'Y') {
				cntY++;
			}
			else if (s[i] == 'N') {
				cntN++;
			}
			else if (s[i] == 'A') {
				cntA++;
			}
			else if (s[i] == 'P') {
				cntP++;
			}
		}

		if (cntA >= cntY + cntN + cntP) {
			cout << "need quorum\n";
		}else if (cntY > cntN) {
			cout << "yes\n";
		}
		else if (cntY == cntN) {
			cout << "tie\n";
		}
		else {
			cout << "no\n";
		}
	}

	return 0;
}