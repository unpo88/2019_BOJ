#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;

	string s;
	cin >> s;

	string result = s;

	for (int i = 1; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < s.length(); j++) {
			if (s[j] != temp[j]) {
				result[j] = '?';
			}
		}
	}

	cout << result << "\n";

	return 0;
}