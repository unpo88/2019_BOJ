#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 65 && s[i] <= 90) {
				s[i] += 32;
			}
		}

		cout << s << "\n";
	}

	return 0;
}