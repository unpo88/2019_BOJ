#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string s, result;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
		if (s[i] < 'D')
			result += s[i] - 'A' + 'X';
		else
			result += s[i] - 'D' + 'A';

	cout << result << "\n";

	return 0;
}