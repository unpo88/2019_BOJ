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
	v.push_back(s[0]);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-')	v.push_back(s[i + 1]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}