#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s;
	cin >> s;

	vector<char> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_') {
			v.push_back(s[i + 1] - 32);
			i++;
		}
		else if (s[i] >= 65 && s[i] <= 90) {
			v.push_back('_');
			cout << s[i + 1] << " " << s[i + 1] + 32;
			v.push_back(s[i + 1] + 32);
		}
		else {
			v.push_back(s[i]);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}